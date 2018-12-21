var express = require('express');
var router = express.Router();
var assignmentsModel = require('../../models/assignment');
var groupsModel = require('../../models/group');
var mongoose = require('mongoose');
var middleware = require("../../middleware/middleware");

// backend routes ===========================================================
router.use(function (req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept,authorization");
  next();
});

router.get('/',middleware.verifyTokenTeacher, function (req, res) {
  assignmentsModel.find({deleted: {$ne: true}, owner: req.user._id})
    .populate("groups")
    .populate({
      path: 'videos',
      populate: { path: 'userId' }
    })
    .exec(function (err, result) {
    console.log("GET all assignments from teacher");
    if (err) {
      res.send(err);
    } else {
      res.json(result);
    }
  });
});

router.get('/uploadable',middleware.verifyToken, function (req, res) {
  if(req.user.rol != "student") {
    console.log("is geen student");
    assignmentsModel.find({deleted: {$ne: true}, owner: req.user._id, teacherUpload: true}, function (err, result) {
      if (err) {
        res.send(err);
      } else {
        res.json(result);
      }
    });
  }else{
    console.log("hiering");
    groupsModel.find({studentNumbers: req.user.studentNumber})
      .exec(function(err, result1) {
        if (err) {
          res.send(err);
        } else {
          //dit geeft een een lijst terug van groups met assignmentIds
          //deze ids opslaan en dan de ganse models opzoeken
          var assignmentIds = [];
          for (let i = 0; i < result1.length; i++) {
            for (let j = 0; j < result1[i].assignments.length; j++) {
              assignmentIds.push(result1[i].assignments[j]);
            }
          }
          assignmentsModel.find({
            deleted: {$ne: true},
            _id: {"$in": assignmentIds},
            teacherUpload: false,

          }).exec(function (err, result) {
              if (err) {
                res.send(err);
              } else {
                res.json(result);
              }
            });
        }
      });
  }
});



router.get('/student',middleware.verifyToken, function (req, res) { //student wil zijn assignments ophalen
  groupsModel.find({studentNumbers: req.user.studentNumber})
    .exec(function(err, result1) {
      if (err) {
        res.send(err);
      } else {
        //dit geeft een een lijst terug van groups met assignmentIds
        //deze ids opslaan en dan de ganse models opzoeken
        var assignmentIds = [];
        for (let i = 0; i < result1.length; i++) {
          for (let j = 0; j < result1[i].assignments.length; j++) {
            assignmentIds.push(result1[i].assignments[j]);
          }
        }

        assignmentsModel.find({
          deleted: {$ne: true},
          _id: {"$in": assignmentIds}
        })
          .populate({
            path: 'videos',
            populate: { path: 'userId' }
          })
          .populate('owner')
          .exec(function (err, result) {
          console.log("GET all assignments");
          if (err) {
            res.send(err);
          } else {
            console.log("assign result:");
            console.log(result);
            console.log(result.videos);
            res.json(result);
          }
        });
      }
    });
});

router.get('/:id',middleware.verifyToken, function (req, res) {
  assignmentsModel.findById(req.params.id)
    .populate("owner")
    .populate({
      path: 'videos',
      populate: { path: 'userId' }
    })
    .exec(function(err, result){
      console.log(req.params.id);
    if (err) {
      res.send(err);
    } else {
      //console.error("gelukt!");
      res.status(201).json(result);
    }
  });
});

router.post('/', middleware.verifyTokenTeacher, function (req, res) {
  if (req.body == null) {
    res.status(400);
    res.json({
      "error": "Invalid Data"
    });
  } else {
    var newAssign = req.body;
    newAssign.owner = req.user._id;
    var groupIds = [];
    for(let i = 0; i < newAssign.groups.length; i++){
      var groupItem = newAssign.groups[i];
      if(groupItem.currentActive){
        groupIds.push(mongoose.Types.ObjectId(groupItem._id));
      }
    }
    newAssign.groups = groupIds;

    console.log(newAssign);

    assignmentsModel.create(newAssign, function (err, result) {
      if (err) {
        console.error(err);
        res.send(err);
      } else {
        groupIds.forEach(function (groupId) {
          groupsModel.findOneAndUpdate({_id: groupId}, {$push: {assignments: result._id}}, function (err2, result2) {
            if(err)
              console.error(err);
          });
        });

        res.status(201).json(result);
      }
    });
  }
});

router.put('/:id', middleware.verifyTokenTeacher, function (req, res) {
  if (req.body == null) {
    res.status(400);
    res.json({
      "error": "Invalid Data"
    });
  } else {

    var newAssign = req.body;
    var groupIds = [];
    var addedGroupIds = [];
    var deletedGroupIds = [];
    for(let i = 0; i < newAssign.groups.length; i++){
      var groupItem = newAssign.groups[i];
      if(!groupItem.currentActive && groupItem.previousActive){
        deletedGroupIds.push(groupItem._id);

      }else if(groupItem.currentActive && !groupItem.previousActive){
        addedGroupIds.push(groupItem._id);
      }
      if(groupItem.currentActive){
        groupIds.push(mongoose.Types.ObjectId(groupItem._id));
      }

    }
    newAssign.groups = groupIds;

    console.log(newAssign);


    assignmentsModel.findOneAndUpdate({_id: req.params.id}, newAssign, function (err, result) {
      if (err) {
        console.error(err);
        res.send(err);
      } else {
        //nu we weten da de assignment id bestaat, kunnen we deze toevoegen of verwijderen van de group objecten
        addedGroupIds.forEach(function (groupId) {
          groupsModel.findOneAndUpdate({_id: groupId}, {$push: {assignments: result._id}}, function (err2, result2) {
            if(err)
              console.error(err);
          });
        });
        deletedGroupIds.forEach(function (groupId) {
          groupsModel.findOneAndUpdate({_id: groupId}, {$pull: {assignments: result._id}}, function (err2, result2) {
            if(err)
              console.error(err);
          });
        });

        res.status(201).json(result);
        console.log(result);
      }
    });
  }
});

router.delete('/:id', middleware.verifyTokenTeacher, function (req, res) {
  assignmentsModel.findOneAndUpdate({_id: req.params.id}, {
    $set: {
      "deleted": true
    }
  }, function (err, result1) {
    if (err) {
      console.error(err);
      res.send(err);
    } else {
      res.status(201).json(result1);
    }
  });
});

module.exports = router;
