const express = require("express");
const bodyParser = require("body-parser");
require("dotenv").config();
const mongoose = require("mongoose");
const path = require("path");
const validUrl = require("valid-url");
const shortid = require("shortid");
const URL = require("./models/url");
const session = require("express-session");
const flash = require("connect-flash");

const app = express();

app.use(
  session({
    secret: "I am so hot.",
    resave: false,
    saveUninitialized: true,
  })
);

app.use(flash());

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, "public")));

app.set("view engine", "ejs");
app.set("views", "views");

mongoose
  .connect(process.env.MONGODB_URI)
  .then(() => {
    console.log("Connected to database!");
  })
  .catch(() => {
    console.log("Connection failed!");
    process.exit(1);
  });

app.get("/", (req, res, next) => {
  let message = req.flash("error")[0];
  res.render("index", {
    shortUrl: null,
    errorMessage: message,
  });
});

app.post("/shorten", async (req, res, next) => {
  const url = req.body.url;
  if (!validUrl.isUri(url)) {
    req.flash("error", "Invalid URL");
    return res.status(401).redirect("/");
  }
  let shortUrl = await URL.findOne({ url: url });
  if (shortUrl) {
    shortUrl.date = new Date();
    return shortUrl
      .save()
      .then((result) => {
        res.status(200).render("index", {
          shortUrl: shortUrl.shortUrl,
          errorMessage: null,
        });
      })
      .catch((err) => {
        req.flash("error", "Something went wrong");
        res.redirect("/");
      });
  }
  const urlCode = shortid.generate();
  shortUrl = new URL({
    url: url,
    urlCode: urlCode,
    shortUrl: `${req.protocol}://${req.get("host")}/${urlCode}`,
  });
  shortUrl
    .save()
    .then((result) => {
      res.status(200).render("index", {
        shortUrl: shortUrl.shortUrl,
        errorMessage: null,
      });
    })
    .catch((err) => {
      req.flash("error", "Something went wrong");
      res.redirect("/");
    });
});

app.get("/:urlCode", async (req, res, next) => {
  const urlCode = req.params.urlCode;
  let url;
  try {
    url = await URL.findOne({ urlCode: urlCode });
  } catch (error) {
    req.flash("error", "Something went wrong");
    return res.status(500).redirect("/");
  }
  if (!url) {
    req.flash("error", "url not found");
    return res.status(404).redirect("/");
  }
  res.redirect(url.url);
});

const port = process.env.PORT || 3000;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
