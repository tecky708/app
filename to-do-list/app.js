const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");
require("dotenv").config();
const app = express();

mongoose.connect(process.env.MONGODB_URI);

const taskSchema = new mongoose.Schema({
  text: {
    type: String,
    required: true,
  },
});

const Task = mongoose.model("Task", taskSchema);

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.set("view engine", "ejs");

app.get("/", (req, res) => {
  Task.find({})
    .then((tasks) => {
      res.render("index", { tasks: tasks });
    })
    .catch((err) => {
      console.log(err);
    });
});

app.post("/add", (req, res) => {
  const text = req.body.text;
  if (text.trim() !== "") {
    const task = new Task({ text: text });
    task
      .save()
      .then(() => {
        res.redirect("/");
      })
      .catch((err) => console.log(err));
  }
});

app.post("/delete", (req, res) => {
  const index = req.body.index;
  Task.findByIdAndRemove(index)
    .then(() => {
      res.redirect("/");
    })
    .catch((err) => console.log(err));
});

const port = process.env.PORT || 3000;
app.listen(port, () => {
  console.log(`Server Started On Port ${port}`);
});
