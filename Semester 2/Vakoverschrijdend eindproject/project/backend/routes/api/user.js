let express = require("express");
let router = express.Router();
let passport = require("passport");
let User = require('../../models/user');
var jwt = require('jsonwebtoken');
var middleware = require("../../middleware/middleware");
var ObjectId = require('mongodb').ObjectID;

/* GET ALL USERS */
router.get('/',middleware.verifyToken, function(req, res, next) {
  User.find(function (err, users) {
    if (err) return next(err);
    res.json(users);
  });
});

/* USER BY USERNAME */
router.get('/u/:userName', middleware.verifyToken, function(req, res) {
  console.log("Welcome to the backend (finally...)");
  console.log("Received user get request for " + req.params.userName);

  if (req.body == null) {
    console.warn("user.js >> Request body is empty!");
    res.status(400).json({"error" : "Empty body"});
  } else {
    User.findOne({"username": req.params.userName}, function(err, user){
      if (err) {
        console.warn("user.js >> Error while finding user!");
        res.status(400);
        res.json({"error" : "err while finding user"})
      }
      if (!user) {
        console.log("user.js >> Could not find user = " + user);
        res.status(401).send({success:false,msg:'Could not find user!'});
      } else {
        console.log("user.js >> Found user associated with " + req.params.userName + "!");
        //res.json({success: true, body: user});
        res.send(user);
      }
    })
  }
});


/* GET LOGGED IN USER */
router.get('/me', middleware.verifyToken, function(req, res) {
  console.log("getting me");
  res.send(req.user);
});


/* USER BY STUDENT NUMBER */
router.get('/i/:studentNumber', function(req, res) {
  console.log('Backend reached');
  if (req.body == null) {
    console.warn("user.js >> Request body is empty!");
    res.status(400).json({"error" : "Empty body"});
  } else {
    User.findOne({"studentNumber": req.params.studentNumber}, function(err, user){
      if (err) throw err;
      if (!user) {
        console.log("user = " + user);
        res.status(401).send({success:false, msg:'Could not find user!'});
      } else {
        console.log("user.js >> Found user associated with Id " + req.params.studentNumber + '!');
        res.send(user);
      }
    });
  }
})

/* GET USER BY USER ID */
router.get('/gubui/:userId', middleware.verifyToken, function(req, res) {
  console.log('/gubui/' + req.params.userId);
  if (req.body == null) {
    res.status(400).json({"error" : "Empty body"});
  } else {
    User.findOne({"_id" : ObjectId(String(req.params.userId))}, function(err, user) {
      if (err) throw err;
      if (!user) {
        console.log("Could not find user by userId");
        res.status(401).send({succes:false, msg:'Could not find user!'});
      } else {
        console.log("user.js >> Found user associated with userId " + req.params.userId + ' [' + user.userName + ']');
        console.log(user);
        res.send(user);
      }
    });
  }
});

router.post("/login",function(req, res) {
    User.findOne({username: req.body.username},function(err,user){
      if(err) throw err;
      if(!user){
        console.log("user = " + user);
        res.status(401).send({success:false,msg:'Authentication failed, no user'});
      }else{
        user.comparePassword(req.body.password,function(err,isMatch){
          if(isMatch && !err){
            var token = jwt.sign(user.toJSON(), "secret key");
            // return the information including token as JSON
            res.json({success: true, token: 'JWT ' + token});
          }else{
            res.status(401).send({success:false,msg:'Authentication failed, wrong password'});
          }
        })
      }
    })
  }
);

module.exports = router;
