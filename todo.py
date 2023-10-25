<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple To-Do List</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        .container {
            max-width: 400px;
            margin: 0 auto;
        }
        h1 {
            text-align: center;
        }
        #task-input {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
        }
        #task-list {
            list-style: none;
            padding: 0;
        }
        .task-item {
            display: flex;
            justify-content: space-between;
            align-items: center;
            border: 1px solid #ddd;
            padding: 10px;
            margin: 5px 0;
            background-color: #f9f9f9;
        }
        .task-remove {
            color: red;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Simple To-Do List</h1>
        <input type="text" id="task-input" placeholder="Add a new task">
        <ul id="task-list"></ul>
    </div>

    <script>
        const taskInput = document.getElementById('task-input');
        const taskList = document.getElementById('task-list');

        // Add a new task
        taskInput.addEventListener('keypress', function(event) {
            if (event.key === 'Enter' && taskInput.value.trim() !== '') {
                const taskText = taskInput.value.trim();
                const taskItem = document.createElement('li');
                taskItem.className = 'task-item';
                taskItem.innerHTML = `
                    <span>${taskText}</span>
                    <span class="task-remove">❌</span>
                `;
                taskList.appendChild(taskItem);
                taskInput.value = '';
                // Remove the task when the '❌' is clicked
                taskItem.querySelector('.task-remove').addEventListener('click', function() {
                    taskList.removeChild(taskItem);
                });
            }
        });
    </script>
</body>
</html>
