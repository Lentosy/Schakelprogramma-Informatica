var express = require('express');
var router = express.Router();
var video = require('../../models/video');
var assignment = require('../../models/assignment');
var annotation = require('../../models/annotation');
var multer = require("multer");
var passport = require("passport");
var jwt = require('jsonwebtoken');
var path = require('path');
require('../config/passport')(passport);
var middleware = require("../../middleware/middleware");
var shortid = require('shortid');
var fs = require('fs');

// backend routes ===========================================================
router.use(function (req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept,authorization");
  next();
});

router.get('/',middleware.verifyToken, function (req, res) {
    video.find(function (err, result) {
    if (err) {
      res.send(err);
    } else {
      res.json(result);
    }
  });
});

/* Gets called when asking for a specific video with id = :id*/
router.get('/:id',middleware.verifyToken, function (req, res) {
  if(req.user.rol != "student") {
    video.findById(req.params.id)
      .populate("annotations")
      .populate("assignmentId")
      .exec(function (err, result) {
        if (!err) {

          res.status(201).json(result);
        } else {
          res.send(err);
        }
      });
  }else{ //student mag enkel alle comments zien als de assignment niet prive is
    video.findById(req.params.id)
      .populate("annotations")
      .populate("assignmentId")
      .exec(function (err, result) {
        if (err) {
          res.send(err);
        } else {
          if(!result.assignmentId.privateAnnotations){
            res.status(201).json(result);
          }else{
            console.log("private annotations!");
            for(let i = 0; i < result.annotations.length;){
              if(result.annotations[i].userId == req.user._id){
                i++;
              }else{
                result.annotations.splice(i, 1);
              }
            }
            res.status(201).json(result);
          }
        }
      });
  }
});

//videostream
router.get('/stream/:id',function (req, res) {
  let reg = new RegExp("[^/]*$");
  let match = reg.exec(req.originalUrl);
  video.findById(match, function(err,vid){
    if(!err){
    let path = vid.url;
    let stat = fs.statSync(path);
    let filesize = stat.size;
    let range = req.headers.range;

    console.log("File info: size: " + filesize + "range: " + range);

    if (range) {
      const parts = range.replace(/bytes=/, "").split("-");
      const start = parseInt(parts[0], 10);
      const end = parts[1]? parseInt(parts[1], 10): filesize-1;
      const chunksize = (end-start)+1;
      const file = fs.createReadStream(path, {start, end});
      const head = {
        'Content-Range': `bytes ${start}-${end}/${filesize}`,
        'Accept-Ranges': 'bytes',
        'Content-Length': chunksize,
        'Content-Type': 'video/mp4',
      };
      res.writeHead(206, head);
      file.pipe(res);
    } else {
      const head = {
        'Content-Length': filesize,
        'Content-Type': 'video/mp4',
      };
      res.writeHead(200, head);
      fs.createReadStream(path).pipe(res);
    }
    }else{
      res.send(err);
    }
  });


});


//upload video
//multer conf
const validExtensions = [
  //".divx",
  ".mp4"
  //".avi",
  //".wmv",
  //".mov",
  //".qt",
  //".avchd",
  //".flv",
  //".swf",
  //".mpg",
  //".m4p",
  //".m4v",
  //".svi"
];
const multerconf = {
  storage : multer.diskStorage({
    destination: function(req, file, cb) {
      cb(null, path.join(__dirname, "../../../uploads/video/"));
    },
    filename: function(req, file, cb) {
      cb(null, shortid.generate() + path.extname(file.originalname));
    }
  }),
  fileFilter: function(req,file, cb) {
    let ext = path.extname(file.originalname);
    let i = 0;
    while (ext !== validExtensions[i] && i < validExtensions.length) {
      // alle extensies overlopen
      i++;
    }

    if (i == validExtensions.length) {
      // zal enkel waar zijn indien geen enkele extensie gematched is
      req.fileValidationError = "Wrong file Extension";
      return cb(null,false,new Error("only video formats"));
    }
      cb(null, true);
  }
};
var upload = multer(multerconf).single('video');
  let videopath;
//upload post method
router.post("/upload", middleware.verifyToken, upload , function(req, res) {
  let ass = req.body.assignment;
  //controlleren als men voor deze asisgnment mag uploaden-------------------------------------------------------
  if(req.user.rol == "student"){
    assignment.findById(ass)
      .populate("videos")
      .populate("groups")
      .exec(function(err, foundAss) {
        if(foundAss.teacherUpload == true) res.status(400).send("You are not allowed to upload to this assignment");
        else {
          var foundAVid = false;
          for (let i = 0; i < foundAss.videos.length; i++) {
            if (foundAss.videos[i].userId == req.user._id) foundAVid = true;
          }
          if (foundAVid) res.status(400).send("You allready have uploaded a video for this assignment");
          else {
            var foundAGroup = false;
            for (let i = 0; i < foundAss.groups.length; i++) {
              if (!foundAGroup) {
                for (let j = 0; j < foundAss.groups[i].studentNumbers.length; j++) {
                  let studentNumber = foundAss.groups[i].studentNumbers[j];
                  if (studentNumber == req.user.studentNumber && !foundAGroup) {
                    foundAGroup = true;
                    continueUpload();
                  }
                }
              }
            }
            if (!foundAGroup) res.status(400).send("You are not allowed to upload to this assignment");
          }
        }
      });
  }else{//docent---------controlleren als teacherupload en owner = req.user._id
    assignment.findById(ass, function (err, foundAss) {
      if(err){
        res.status(400).end();
      }else{
        if(foundAss.teacherUpload == false){console.log("niet teacher Upload"); res.status(400).end();}
        else if(foundAss.owner != req.user._id){console.log("niet de owner"); res.status(400).end();}
        else continueUpload();
      }
    });
  }

  /*-----------------------------------------------------------controle klaar--- upload toegestaan---------------*/
  function continueUpload() {
    console.log("in de continue upload geraakt!");
    let title = req.body.title;

    upload(req, res, function(err) {
      if (err || req.fileValidationError) {
        res.status(400).end();
      } else {
        video.create({name : title,
          url : "uploads/video/" + req.file.filename,
          deleted: false,
          userId: req.user._id,
          assignmentId : ass}, function(err,obj){
          if(err){
            res.status(400).end();
          }else{
            //console.log("videoid: " + obj._id);
            //console.log("assid: " + ass);
            assignment.findOneAndUpdate({_id: ass},{$push:{"videos":obj}},function(err,assobj){
              if(err){
                res.status(400).end();
              }else{
                res.status(201).json(obj); // geef de video terug
              };
            });
          };
        });
      };
    });
  }
});

router.put('/:id', function (req, res) {
  if (req.body == null) {
    res.status(400);
    res.json({
      "error": "Invalid Data"
    });
  } else {
    //console.log(req.body);
    video.findOneAndUpdate({"id":req.params.id},req.body, function (err, result) {
      if (err) {
        //console.error(err);
        res.send(err);
      } else {
        //console.error("gelukt!");
        res.status(201).json(result);
      }
    });
  }
});

router.delete('/:id', function (req, res) {
  video.delete(req.params.id,function(err, result){
    if (err) {
      res.send(err);
    } else {
      res.status(201).json(result);
    }
  });
});

getToken = function (headers) {
  if (headers && headers.authorization) {
    var parted = headers.authorization.split(' ');
    if (parted.length === 2) {
      return parted[1];
    } else {
      return null;
    }
  } else {
    return null;
  }
};

module.exports = router;
