var express = require('express');
var router = express.Router();
var Annotation = require('../../models/annotation');
var video = require('../../models/video');
var middleware = require('../../middleware/middleware');

// backend routes ===========================================================
router.use(function (req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept,authorization");
    next();
  });

router.get('/',middleware.verifyToken, function(req, res) {
    console.log("hier in geraakt!!! annotaties ophalen... ");
    Annotation.find(function(err, result) {
        if (err) {
            res.send(err);
        } else {
            res.json(result);
        }
    });
});

router.get('/:id',middleware.verifyToken, function(req, res) {
    Annotation.findById(req.params.id, function(err, result) {
        if (err) {
            res.send(err);
        } else {
            res.status(201).json(result);
        }
    });
});

router.post('/',middleware.verifyToken, function(req, res) {
    if (req.body == null) {
        res.status(400);
        res.json({
            "error": "Invalid Data"
        });
    } else if (req.body.beginTime < 0) {
        res.status(400);
        res.json({
            "error": "Negative timestamp"
        });
    } else if (req.body.endTime < req.body.beginTime){
        res.status(400);
        res.json({
            "error": "Endtime is smaller than beginTime"
        })
    } else {
        console.log("form data is binnengekomen!");
        console.log(req.body);
        let annotation = new Annotation(req.body);
        annotation.save(function(err, result) {
            if (err) {
                console.error(err);
                res.send(err);
            } else {
                //de id van de annotatie toevoegen aan de juiste video
                //console.log("test "+req.body.videoId);
                //console.log("new id: "+annotation.id);
                video.findOneAndUpdate({
                    _id: req.body.videoId
                }, {
                    $push: {
                        "annotations": annotation.id
                    }
                }, function(err, result) {
                    if (err) {
                        res.send(err);
                    } else {
                        res.status(201).json(result);
                    }
                });
            }
        });
        //video.annotations.push(annotation.id);
    }
});

/*
    Video.remove({}, function(err) {
      if (err) {
        console.log(err);
      } else {
        console.log("all videos deleted");
      }
      videoData.forEach(function(video) {
        Annotation.find({}, function(err, objs) {
          console.log(objs);
          if (err) {
            console.log(err);
          } else {
            objs.forEach(function(obj) {
              video.annotations.push(obj._id);
            });
          }
          Video.create(video, function(err, obj) {
            if (err) {
              console.log(err);
            } else {
              console.log("added video to db");
            }
          });
        });

      });
    });
  });
  */


router.put('/:id', function(req, res) {
    if (req.body == null) {
        res.status(400);
        res.json({
            "error": "Invalid Data"
        });
    } else {
        //console.log(req.body);
        Annotation.findOneAndUpdate({
            "id": req.params.id
        }, req.body, function(err, result) {
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

router.delete('/:id', function(req, res) {
    Annotation.delete(req.params.id, function(err, result) {
        if (err) {
            res.send(err);
        } else {
            res.status(201).json(result);
        }
    });
});

module.exports = router;
