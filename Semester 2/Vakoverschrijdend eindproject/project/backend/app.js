//imports
let express = require("express");
let session = require("express-session");
let favicon = require('serve-favicon');
let logger = require('morgan');
let bodyParser = require("body-parser");
let flash = require("connect-flash");
let passport = require("passport");
let path = require("path");

//MongoDb database imports
let mongoose = require("mongoose");
let seedDB = require("./seed");

//models
let User = require("./models/user");
let app = express();

//route setup
let homeRoutes = require("./routes/index");
let videoAPIRoutes = require("./routes/api/video");
let assignmentAPIRoutes = require("./routes/api/assignment");
let annotationAPIRoutes = require("./routes/api/annotations");
let groupAPIRoutes = require("./routes/api/group");
let authenticationAPIRoutes = require("./routes/api/user");
//DB config setup
mongoose.Promise = require('bluebird');
//bovenste voor docker
mongoose.connect('mongodb://annotatietool-01-mongodb:27017',{ promiseLibrary: require('bluebird') })

//onderste voor lokaal
//mongoose.connect('mongodb://localhost:27017/annotatietool', { promiseLibrary: require('bluebird') })
  .then(() =>  console.log('connection succesful'))
  .catch((err) => console.error(err));

  app.engine('html', require('ejs').renderFile);

//express setup
app.use(function (req, res, next) {
  // Website you wish to allow to connect
  res.setHeader('Access-Control-Allow-Origin', 'http://annotatietool.tiwi.ugent.be');
  //res.setHeader('Access-Control-Allow-Origin', 'http://localhost:9010');
  // Request methods you wish to allow
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE, HEAD');
  // Request headers you wish to allow
  res.setHeader('Access-Control-Allow-Headers', "Access-Control-Allow-Headers, Origin,Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers,authorization");
  // Set to true if you need the website to include cookies in the requests sent
  // to the API (e.g. in case you use sessions)
  res.setHeader('Access-Control-Allow-Credentials', true);
  // Pass to next layer of middleware
  next();
});
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({'extended':'false'}));
app.use(express.static(path.join(__dirname, 'dist')));
app.use(bodyParser());

//route express setup
app.use('./routes/index', express.static(path.join(__dirname, 'dist')));
app.use("/",homeRoutes);
app.use("/api/video",videoAPIRoutes);
app.use("/api/assignment",assignmentAPIRoutes);
app.use("/api/annotation",annotationAPIRoutes);
app.use("/api/group",groupAPIRoutes);
app.use("/api/user",authenticationAPIRoutes);

//SEED
seedDB();

// app.use("/groups", groupRoutes);

//LOCAL-PASSPORT
app.use(passport.initialize());


app.use(function(req, res, next) {
  res.locals.currentUser = req.user;
  app.locals.currentUser = req.user;
  res.locals.error = flash("error");
  res.locals.success = flash("success");
  next();
});

module.exports = app;
