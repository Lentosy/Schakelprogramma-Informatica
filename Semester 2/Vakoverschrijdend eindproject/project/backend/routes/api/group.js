var express = require("express");
var router = express.Router();
let csv = require("fast-csv");
let multer = require('multer');
var mongoose = require('mongoose');
let Group = require("../../models/group");
var middleware = require("../../middleware/middleware");

let fileUpload = multer({dest:'../../tmp/'}).single('studentsFile');

// backend routes ===========================================================
router.use(function (req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept,authorization");
  next();
});



router.post("/", middleware.verifyTokenTeacher,fileUpload, function(req,res){ //binnengekomen json opslaan in database
  let newGroup = new Group({docentId: req.user._id, name: req.body.name});
  let isFirst = true;
  let hasHeader = false;
  let kolomIndexen = {"Officiële code": 0, "Voornaam": 1, "Familienaam": 2};
  console.log(req.file);
  
  csv
    .fromPath(req.file.path, { delimiter:';'})
    .on("data", function(data){
    
      //de eerste keer wordt gecontrolleerd als de csv een header heeft of niet, als hij geen heeft,
      //dan zijn de indexen van de kolommen hardgecodeerd
      //als hij wel een header heeft kunnen we de indexen later bepaelen
      if(isFirst){
        isFirst = false;
        let kolomKeys = Object.keys(kolomIndexen);
        if(kolomKeys.indexOf(data[0]) != -1){ //de eerste rij bevat een van de keys van indexenMetHeader
          hasHeader = true;
          for(let i  = 0; i < data.length; i++){
            for(let j = 0; j < kolomKeys.length; j++){
              if(data[i] == kolomKeys[j]) kolomIndexen[kolomKeys[j]] = i;
            }
          }
        }
      }else if(hasHeader){ //als hij een header heeft mag hij nooit de eerste keer de data ophalen
        voegStudentToe();
      }
      if(!hasHeader){
        voegStudentToe();
      }

      function voegStudentToe() {
        try {
          newGroup.studentNumbers.push(data[kolomIndexen["Officiële code"]]);
          newGroup.students.push({studentNumber: data[kolomIndexen["Officiële code"]],
            firstName: data[kolomIndexen["Voornaam"]], lastName: data[kolomIndexen["Familienaam"]]});
        }catch(ex){
          console.error(ex);
        }
      }

    })
    .on("end", function(){
      console.log("parsing csv done => can be inserted in db!");

      newGroup.save(newGroup, function (err, result) {
        if (err) {
          console.error(err);
          res.send(err);
        } else {
          console.log("gelukt!");
          res.status(201).json(result);
        }
      });

    })
    .on("error", function(){
      console.log("error parsing csv");
  });
});

router.delete('/:id', middleware.verifyTokenTeacher, function (req, res) {
  Group.find({ _id:req.params.id }).remove( function(err, result){
    if (err) {
      res.send(err);
    } else {
      res.status(201).json(result);
    }
  } );

});

router.delete('/:groupId/:studentNumber', middleware.verifyTokenTeacher, function (req, res) {
  console.log(req.params.studentNumber);
  console.log(req.params.groupId);
  Group.update(
    {_id: req.params.groupId},
    { $pull: { students: { studentNumber: req.params.studentNumber }, studentNumbers: req.params.studentNumber } },
    { safe: true, multi:true }, function(err, result) {
      if (err) {
        res.send(err);
      } else {
        res.status(201).json(result);
      }
    });

});

router.post('/:groupId/student', middleware.verifyTokenTeacher, function(req, res) {
  //checken als data isset
  if (typeof req.body.firstName === 'undefined') req.status(403).json("first name not valid");
  if (typeof req.body.lastName === 'undefined') req.status(403).json("last name not valid");
  if (typeof req.body.studentNumber === 'undefined') req.status(403).json("student number not valid");
});

router.get("/",middleware.verifyTokenTeacher, function (req, res) {
  let groups = Group.
  find({
    docentId: req.user._id
  }).
  sort("name").
  exec(function (error, result) {
    res.json(result);
  });
});

router.get('/member', middleware.verifyToken, function (req, res) { //geeft alle groepen waar je een member van bent( voor studenten)
  Group.find({studentNumbers: req.user.studentNumber})
    .populate('assignments')
    .exec(function(err, result){
      if (err) {
        res.send(err);
      } else {
        res.status(201).json(result);
      }
    });
});

router.get('/:groupId',middleware.verifyToken, function (req, res) {
  Group.findById(req.params.groupId)
    .populate("assignments")
    .exec(function(err, result){
    if (err) {
      res.send(err);
    } else {
      res.status(201).json(result);
    }
  });
});



module.exports = router;
