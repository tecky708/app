const express = require('express');
const mongoose = require('mongoose');

const app = express();
const port = 3000;

// Connect to MongoDB
mongoose.connect('mongodb://localhost/myapp', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

// Create a mongoose schema
const mySchema = new mongoose.Schema({
  name: String,
  age: Number,
});

// Create a mongoose model
const MyModel = mongoose.model('MyModel', mySchema);

// Define a route to fetch all data
app.get('/data', async (req, res) => {
  try {
    const data = await MyModel.find();
    res.json(data);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// Define a route to create new data
app.post('/data', async (req, res) => {
  try {
    const newData = await MyModel.create(req.body);
    res.json(newData);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server listening at http://localhost:${port}`);
});
