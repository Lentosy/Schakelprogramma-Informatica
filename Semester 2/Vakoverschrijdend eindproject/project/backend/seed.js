let mongoose = require("mongoose");
let User = require("./models/user");
let Video = require("./models/video");
let Annotation = require("./models/annotation");
let Assignment = require("./models/assignment");
let Group = require("./models/group");

let userData = [{
    username: "docent",
    studentNumber: "01706996",
    firstName: "docent",
    lastName: "docent",
    rol: "docent",
    password: "test"
  },
  {
    username: "rubenjanssens",
    rol: "docent",
    firstName: "Ruben",
    lastName: "Janssens",
    studentNumber: "01706997",
    password: "test"
  },
  {
    username: "student",
    rol: "student",
    firstName: "student",
    lastName: "student",
    studentNumber: "01706998",
    password: "test"
  },
  {
    username: "nickvanhurck",
    rol: "student",
    studentNumber: "01706999",
    firstName: "Nick",
    lastName: "van Hurck",
    password: "test"
  },
  {
    username: "emielvandenbussche",
    rol: "student",
    studentNumber: "01708928",
    firstName: "Emiel",
    lastName: "Vandenbussche",
    password: "test"
  },
  {
    username: "timothythiecke",
    rol: "student",
    studentNumber: "01706994",
    firstName: "Timothy",
    lastName: "Thiecke",
    password: "test"
  },
  {
    username: "arnoutlenaerts",
    rol: "student",
    studentNumber: "01706993",
    firstName: "Arnout",
    lastName: "Lenaerts",
    password: "test"
  }
];

//groep 1
let annotationNick = [{
    description: "mooie interactie met de klant",
    beginTime: "5",
    endTime: "7"
  },
  {
    description: "verzorg de articulatie",
    beginTime: "25",
    endTime: "27"
  }
];
let annotationBert = [{

    description: "spannend",
    beginTime: "6",
    endTime: "8"
  },
  {

    description: "realistisch",
    beginTime: "26",
    endTime: "28"
  }
];
//groep 2
let annotationEmiel = [{

    description: "geloofwaardig",
    beginTime: "7",
    endTime: "9"
  },
  {

    description: "vlot verteld",
    beginTime: "27",
    endTime: "29"
  }
];
let annotationArnout = [{

    description: "verrassend",
    beginTime: "8",
    endTime: "10"
  },
  {

    description: "voorspelbaar",
    beginTime: "28",
    endTime: "30"
  }
];
let annotationTimo = [{

    description: "grappig",
    beginTime: "9",
    endTime: "11"
  },
  {

    description: "ingewikkeld",
    beginTime: "29",
    endTime: "31"
  }
];

let videoData = [{
    name: "Interview tijdens sollicitatie",
    url: "uploads/video/Bku3Ighdf.mp4",
    deleted: false,
    annotations: [],
    userId: null
  },
  {
    name: "Ongemakkelijke ontmoeting met een oude vriend",
    url: "uploads/video/video1.mp4",
    deleted: false,
    annotations: [],
    userId: null
  },
  {
    name: "Avondje café met de vrienden",
    url: "uploads/video/video2.mp4",
    deleted: false,
    annotations: [],
    userId: null
  },
  {
    name: "Omgaan met een nieuwe patiënt ",
    url: "uploads/video/video3.mp4",
    deleted: false,
    annotations: [],
    userId: null
  },
  {
    name: "Verkopen van een auto",
    url: "uploads/video/rJ8wGTHRz.mp4",
    deleted: false,
    annotations: [],
    userId: null
  }
];
let tomorrow = new Date(new Date().setDate(new Date().getDate() + 1));
let yesterday = new Date(new Date().setDate(new Date().getDate() - 1));
let assignmentDataGlenn = [{
    name: "Interviewtechnieken",
    description: "De studenten moeten aan de hand van een video aantonen dat ze goede interviewtechnieken hebben",
    annotationTypes: null,
    teacherUpload: false,
    privateAnnotations: true,
    quickCommentEnabled: true,
    quickComments: ["Something", "another thing"],
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: false
  },
  {
    name: "Praatjesmaker",
    description: "De studenten moeten aan de hand van een video aantonen dat ze zich uit een ongemakkelijke situatie kunnen praten",
    annotationTypes: null,
    teacherUpload: true,
    quickCommentEnabled: true,
    quickComments: ["Something", "another thing"],
    privateAnnotations: true,
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: false
  },
  {
    name: "Vriendenpraat",
    description: "De studenten moeten aan de hand van een video aantonen dat ze ethisch met vrienden kunnen praten",
    annotationTypes: null,
    teacherUpload: true,
    quickCommentEnabled: true,
    quickComments: [],
    privateAnnotations: true,
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    dropdown: ["niet ethisch", "wel ethisch"],
    deleted: false
  },
  {
    name: "La mama",
    description: "De studenten moeten aan de hand van een video aantonen dat ze bange personen kunnen geruststellen",
    annotationTypes: null,
    teacherUpload: false,
    privateAnnotations: true,
    quickCommentEnabled: true,
    quickComments: [],
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: false
  }
];

let assignmentDataRuben = [

  {
    name: "deleted assignment",
    description: "DELETED",
    annotationTypes: null,
    teacherUpload: true,
    quickCommentEnabled: true,
    quickComments: [],
    privateAnnotations: true,
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: true
  },
  {
    name: "Omgaan met persoon tijdens spoedopname",
    description: "De studenten moeten aantonen dat ze in spoedsituaties de persoon in kwestie gerust kunnen stellen",
    annotationTypes: null,
    teacherUpload: false,
    quickCommentEnabled: true,
    quickComments: ["TEST", "TEST2de"],
    privateAnnotations: true,
    videos: [],
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: false
  },

  {
    name: "Gesprekstechnieken",
    description: "De studenten moeten aan de hand van de video de gesprekstechnieken identificeren",
    annotationTypes: null,
    teacherUpload: true,
    quickCommentEnabled: true,
    quickComments: [],
    videos: [],
    privateAnnotations: false,
    annotationDeadline: tomorrow.toString(),
    uploadDeadline: tomorrow.toString(),
    deleted: false
  },
  {
    name: "TO LATE FOR UPLOAD",
    description: "UPLOAD TO LATE",
    annotationTypes: null,
    teacherUpload: true,
    quickCommentEnabled: true,
    quickComments: [],
    privateAnnotations: false,
    annotationDeadline: yesterday.toString(),
    uploadDeadline: yesterday.toString(),
    deleted: false
  }
];

let group1Data = {
  studentNumbers: [
    "01706998",
    "01706999"
  ],
  name: "groep 1",
  assignments: [],
  students: [],
  docentId: ""
};
let group2Data = {
  studentNumbers: [
    "01708928",
    "01706993",
    "01706994"
  ],
  name: "groep 2",
  assignments: [],
  students: [],
  docentId: ""
}


function seedDB() {
  var userCount = 0;
  var videoCount = 0;
  var idGlenn = 0;
  var idRuben = 0;
  var idBert = 0;
  var idNick = 0;
  var idTimo = 0;
  var idArnout = 0;
  var idEmiel = 0;
  var assCountGlenn = 0;
  var assCountRuben = 0;
  var annoCountBert = 0;
  var annoCountNick = 0;
  var annoCountEmiel = 0;
  var annoCountArnout = 0;
  var annoCountTimo = 0;
  var firstAssignmentRuben = false;
  var firstAssignmentGlenn = false;
  var assignmentGlennCount = 0;
  var assignmentRubenCount = 0;
  var groep1Count = 0;
  var groep2Count = 0;
  var assignmentIDGroep1 = [];
  var assignmentIDGroep2 = [];
  //remove users
  User.remove({}, function (err) {
    if (err) {
      console.log(err);
    } else {
      console.log("all users are gone");
      //remove annotations
      Annotation.remove({}, function (err) {
        if (err) {
          console.log(err);
        } else {
          console.log("all annotations are gone");
          //remove assignments
          Assignment.remove({}, function (err) {
            if (err) {
              console.log(err);
            } else {
              console.log("all assignments are gone");
              //remove groups
              Group.remove({}, function (err) {
                if (err) {
                  console.log(err);
                } else {
                  console.log("all groups are gone");
                  //remove videos
                  Video.remove({}, function (err) {
                    if (err) {
                      console.log(err);
                    } else {
                      console.log("all videos are gone");
                      //add users
                      userData.forEach(function (user) {
                        var newUser = new User(user);
                        newUser.save(
                          function (err, user) {
                            if (err) {
                              console.log(err);
                            } else {
                              userCount++;
                              console.log("added user " + user.username);
                              if (user.username == "docent") {
                                idGlenn = user._id;
                              }
                              if (user.username == "rubenjanssens") {
                                idRuben = user._id;
                              }
                              if (user.username == "student") {
                                idBert = user._id;
                              }
                              if (user.username == "nickvanhurck") {
                                idNick = user._id;
                              }
                              if (user.username == "emielvandenbussche") {
                                idEmiel = user._id;
                              }
                              if (user.username == "timothythiecke") {
                                idTimo = user._id;
                              }
                              if (user.username == "arnoutlenaerts") {
                                idArnout = user._id;
                              }
                              //all users added
                              if (userCount == userData.length) {
                                //add assignment to glenn
                                assignmentDataGlenn.forEach(function (ass) {
                                  User.findOne({
                                    _id: idGlenn
                                  }, function (err, obj) {
                                    if (err) {
                                      console.log("error = " + err);
                                    } else {
                                      ass.owner = obj._id;
                                      Assignment.create(ass, function (err, assignment) {
                                        if (err) {
                                          console.log(err);
                                        } else {
                                          assignmentIDGroep1.push(assignment._id);
                                          console.log("an assignment has been added to Glenn");
                                          obj.assignments.push(assignment._id);
                                          obj.save();
                                          group1Data.assignments.push(assignment._id);
                                          group1Data.docentId = idGlenn;
                                          console.log("assignment added to group 1");
                                          //toevoegen van assignments to user
                                          for (var i = 2; i <= 3; i++) {
                                            User.findOne({
                                              username: userData[i].username
                                            }, function (err, userStudent) {
                                              if (err) {
                                                console.log(err);
                                              } else {
                                                userStudent.assignments.push(assignment._id);
                                                userStudent.save();
                                              }
                                            });
                                          } //end of toeveogen van assignments to user
                                          assignmentGlennCount++;
                                          if (assignmentGlennCount == assignmentDataGlenn.length) {
                                            //studenten vullen
                                            group1Data.studentNumbers.forEach(function (studentnr) {
                                              User.findOne({
                                                studentNumber: studentnr
                                              }, function (err, student) {
                                                if (err) {
                                                  console.log(err);
                                                } else {
                                                  var stud = {
                                                    studentNumber: studentnr,
                                                    firstName: student.firstName,
                                                    lastName: student.lastName
                                                  };
                                                  group1Data.students.push(stud);
                                                  groep1Count++;
                                                  if(groep1Count == group1Data.studentNumbers.length){
                                                     //toevoegen groep 1
                                                  Group.create(group1Data, function (err, groep1) {
                                                    if (err) {
                                                      console.log(err);
                                                    } else {
                                                      console.log("groep 1 added complete");
                                                      assignmentIDGroep1.forEach(function(assignmentID){
                                                        Assignment.findById(assignmentID,function(err,model){
                                                          if(err){
                                                            console.log(err);
                                                          }else{
                                                            model.groups.push(groep1._id);
                                                            model.save();
                                                            console.log("group 1 added to assignment");
                                                          }
                                                        })
                                                      });
                                                    }
                                                  });
                                                  }                                                 
                                                }
                                              })
                                            });
                                          }
                                        }
                                      });
                                    }
                                  });
                                }); // end add assignment to Glenn
                                //add assignment to ruben
                                assignmentDataRuben.forEach(function (ass) {
                                  User.findOne({
                                    _id: idRuben
                                  }, function (err, obj) {
                                    if (err) {
                                      console.log("error = " + err);
                                    } else {
                                      ass.owner = obj._id;
                                      Assignment.create(ass, function (err, assignment) {
                                        if (err) {
                                          console.log(err);
                                        } else {                                          
                                          assignmentIDGroep2.push(assignment._id);
                                          console.log("an assignment has been added to ruben");
                                          obj.assignments.push(assignment._id);
                                          obj.save();
                                          group2Data.assignments.push(assignment._id);
                                          group2Data.docentId = idRuben;
                                          console.log("assignment added to group 2");
                                          //toevoegen van assignments to user
                                          for (var i = 3; i <= 6; i++) {
                                            User.findOne({
                                              username: userData[i].username
                                            }, function (err, userStudent) {
                                              if (err) {
                                                console.log(err);
                                              } else {
                                                userStudent.assignments.push(assignment._id);
                                                userStudent.save();
                                              }
                                            });
                                          }
                                          //end of toeveogen van assignments to user
                                          assignmentRubenCount++;
                                          if (assignmentRubenCount == assignmentDataRuben.length) {
                                            //studenten vullen
                                            group2Data.studentNumbers.forEach(function (studentnr) {
                                              User.findOne({
                                                studentNumber: studentnr
                                              }, function (err, student) {
                                                if (err) {
                                                  console.log(err);
                                                } else {
                                                  var stud = {
                                                    studentNumber: studentnr,
                                                    firstName: student.firstName,
                                                    lastName: student.lastName
                                                  };
                                                  group2Data.students.push(stud);
                                                  groep2Count++;
                                                  if(groep2Count == group2Data.studentNumbers.length){
                                                     //toevoegen groep 2
                                                  Group.create(group2Data, function (err, groep2) {
                                                    if (err) {
                                                      console.log(err);
                                                    } else {
                                                      assignmentIDGroep2.forEach(function(assignmentID){
                                                        Assignment.findById(assignmentID,function(err,model){
                                                          if(err){
                                                            console.log(err);
                                                          }else{
                                                            model.groups.push(groep2._id);
                                                            model.save();
                                                            console.log("group 2 added to assignment");
                                                          }
                                                        })
                                                      });
                                                      console.log("groep 2 added complete");
                                                    }
                                                  });
                                                  }                                                 
                                                }
                                              })
                                            });
                                          }
                                        }
                                      });
                                    }
                                  });
                                }); // end add assignment to ruben
                                //add video's
                                videoData.forEach(function (videoObj) {
                                  Video.create(videoObj, function (err, video) {
                                    if (err) {
                                      console.log(err);
                                    } else {
                                      videoCount++;
                                      console.log("added video " + video.name);
                                      if (videoCount == videoData.length) {
                                        //add video to user
                                        //add user to video
                                        for (var i = 0; i < videoData.length; i++) {
                                          var u = 2;
                                          Video.findOne({
                                            name: videoData[i].name
                                          }, function (err, vid) {
                                            if (err) {
                                              console.log(err);
                                            } else {
                                              console.log("video = " + vid.name);
                                              //search user to video
                                              User.findOne({
                                                username: userData[u++].username
                                              }, function (err, user) {
                                                if (err) {
                                                  console.log(err);
                                                } else {
                                                  vid.userId = user._id;
                                                  vid.save();
                                                  console.log("added " + user.firstName + " to video " + vid.name);
                                                  user.videos.push(vid._id);
                                                  user.save();
                                                  console.log("and vice versa");
                                                  if (user.username == "student" || user.username == "nickvanhurck") {
                                                    //toevoegen aan ass van glenn
                                                    Assignment.findOne({
                                                      owner: idGlenn,
                                                      teacherUpload: false
                                                    }, function (err, a) {
                                                      if (err) {
                                                        console.log(err);
                                                      } else {
                                                          vid.assignmentId = a._id;
                                                          vid.save();
                                                          console.log(vid);
                                                          firstAssignmentGlenn = true;
                                                          console.log("added video of " + vid.userId + "to ass " + a.name);
                                                          a.videos.push(vid._id);
                                                          a.save();   
                                                          console.log("added assingment id to video");
                                                      }
                                                    }); //end of adding assignments to video and vice versa
                                                  } else {
                                                    //toevoegen aan ass van ruben
                                                    Assignment.findOne({
                                                      owner: idRuben,
                                                      teacherUpload: false
                                                    }, function (err, a) {
                                                      if (err) {
                                                        console.log(err);
                                                      } else {                                                                                                                
                                                          a.videos.push(vid._id);
                                                          a.save();
                                                          vid.assignmentId = a._id;
                                                          vid.save();
                                                          firstAssignmentRuben = true;
                                                          console.log("added video of " + vid.userId + "to ass " + a.name);                                                                                                                    
                                                          console.log("added assingment id to video");
                                                        
                                                      }
                                                    }); //end of adding assignments to video and vice versa
                                                  }
                                                }
                                              });
                                            }
                                          });
                                        }
                                        //toevoegen annotaties aan video
                                        annotationBert.forEach(function (annotatie) {
                                          User.findOne({
                                            _id: idBert
                                          }, function (err, user) {
                                            if (err) {
                                              console.log(err);
                                            } else {
                                              Annotation.create(annotatie, function (err, annoObj) {
                                                if (err) {
                                                  console.log(err);
                                                } else {
                                                  annoCountBert++;
                                                  annoObj.userId = user._id;
                                                  annoObj.save();
                                                  console.log("annotation of bert added");
                                                  if (annoCountBert == annotationBert.length) {
                                                    annotationArnout.forEach(function (annotatie) {
                                                      User.findOne({
                                                        _id: idArnout
                                                      }, function (err, user) {
                                                        if (err) {
                                                          console.log(err);
                                                        } else {
                                                          Annotation.create(annotatie, function (err, annoObj) {
                                                            if (err) {
                                                              console.log(err);
                                                            } else {
                                                              annoCountArnout++;
                                                              annoObj.userId = user._id;
                                                              annoObj.save();
                                                              console.log("annotation of arnout added");
                                                              if (annoCountArnout == annotationArnout.length) {
                                                                annotationNick.forEach(function (annotatie) {
                                                                  User.findOne({
                                                                    _id: idNick
                                                                  }, function (err, user) {
                                                                    if (err) {
                                                                      console.log(err);
                                                                    } else {
                                                                      Annotation.create(annotatie, function (err, annoObj) {
                                                                        if (err) {
                                                                          console.log(err);
                                                                        } else {
                                                                          annoCountNick++;
                                                                          annoObj.userId = user._id;
                                                                          annoObj.save();
                                                                          console.log("annotation of nick added");
                                                                          if (annoCountNick == annotationNick.length) {
                                                                            annotationEmiel.forEach(function (annotatie) {
                                                                              User.findOne({
                                                                                _id: idEmiel
                                                                              }, function (err, user) {
                                                                                if (err) {
                                                                                  console.log(err);
                                                                                } else {
                                                                                  Annotation.create(annotatie, function (err, annoObj) {
                                                                                    if (err) {
                                                                                      console.log(err);
                                                                                    } else {
                                                                                      annoCountEmiel++;
                                                                                      annoObj.userId = user._id;
                                                                                      annoObj.save();
                                                                                      console.log("annotation of emiel added");
                                                                                      if (annoCountEmiel == annotationEmiel.length) {
                                                                                        annotationTimo.forEach(function (annotatie) {
                                                                                          User.findOne({
                                                                                            _id: idTimo
                                                                                          }, function (err, user) {
                                                                                            if (err) {
                                                                                              console.log(err);
                                                                                            } else {
                                                                                              Annotation.create(annotatie, function (err, annoObj) {
                                                                                                if (err) {
                                                                                                  console.log(err);
                                                                                                } else {
                                                                                                  annoCountTimo++;
                                                                                                  annoObj.userId = user._id;
                                                                                                  annoObj.save();
                                                                                                  console.log("annotation of timo added");
                                                                                                  if (annoCountTimo == annotationTimo.length) {
                                                                                                    var arnoutCheck = false;
                                                                                                    var timoCheck = false;
                                                                                                    var emielCheck = false;
                                                                                                    //add annotation to video and videoID to annotation
                                                                                                    Annotation.find({}, function (err, annos) {
                                                                                                      if (err) {
                                                                                                        console.log(err);
                                                                                                      } else {
                                                                                                        annos.forEach(function (annot) {
                                                                                                          if (annot.userId == idBert.toString()) {
                                                                                                            console.log("searching video");
                                                                                                            Video.findOne({
                                                                                                              userId: idNick
                                                                                                            }, function (err, vid) {
                                                                                                              if (err) {
                                                                                                                console.log(err);
                                                                                                              } else {
                                                                                                                vid.annotations.push(annot._id);
                                                                                                                vid.save();
                                                                                                                annot.videoId = vid._id;
                                                                                                                annot.save();
                                                                                                                console.log("added anno to video");
                                                                                                              }
                                                                                                            });
                                                                                                          } else if (annot.userId == idNick.toString()) {
                                                                                                            console.log("searching video");
                                                                                                            Video.findOne({
                                                                                                              userId: idBert
                                                                                                            }, function (err, vid) {
                                                                                                              if (err) {
                                                                                                                console.log(err);
                                                                                                              } else {
                                                                                                                vid.annotations.push(annot._id);
                                                                                                                vid.save();
                                                                                                                annot.videoId = vid._id;
                                                                                                                annot.save();
                                                                                                                console.log("added anno to video");
                                                                                                              }
                                                                                                            });
                                                                                                          } else if (annot.userId == idArnout.toString()) {
                                                                                                            if (!arnoutCheck) {
                                                                                                              //toevoegen aan timo
                                                                                                              Video.findOne({
                                                                                                                userId: idTimo
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("arnout voegt toe aan timo");
                                                                                                              arnoutCheck = true;
                                                                                                            } else {
                                                                                                              //toevoegen aan emiel
                                                                                                              Video.findOne({
                                                                                                                userId: idEmiel
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("arnout voegt toe aan emiel");
                                                                                                            }
                                                                                                          } else if (annot.userId == idEmiel.toString()) {
                                                                                                            if (!emielCheck) {
                                                                                                              //toevoegen aan timo
                                                                                                              Video.findOne({
                                                                                                                userId: idTimo
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("emiel voegt toe aan timo");
                                                                                                              emielCheck = true;
                                                                                                            } else {
                                                                                                              //toevoegen aan arnout
                                                                                                              Video.findOne({
                                                                                                                userId: idArnout
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("emiel voegt toe aan arnout");
                                                                                                            }
                                                                                                          } else if (annot.userId == idTimo.toString()) {
                                                                                                            if (!timoCheck) {
                                                                                                              //toevoegen aan arnout
                                                                                                              Video.findOne({
                                                                                                                userId: idArnout
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("timo voegt toe aan arnout");
                                                                                                              timoCheck = true;
                                                                                                            } else {
                                                                                                              //toevoegen aan emiel
                                                                                                              Video.findOne({
                                                                                                                userId: idEmiel
                                                                                                              }, function (err, vid) {
                                                                                                                if (err) {
                                                                                                                  console.log(err);
                                                                                                                } else {
                                                                                                                  vid.annotations.push(annot._id);
                                                                                                                  vid.save();
                                                                                                                  annot.videoId = vid._id;
                                                                                                                  annot.save();
                                                                                                                  console.log("added anno to video");
                                                                                                                }
                                                                                                              });
                                                                                                              console.log("timo voegt toe aan emiel");
                                                                                                            }
                                                                                                          }
                                                                                                        });
                                                                                                      }
                                                                                                    });
                                                                                                  }
                                                                                                }
                                                                                              });
                                                                                            }
                                                                                          });
                                                                                        });
                                                                                      }
                                                                                    }
                                                                                  });
                                                                                }
                                                                              });
                                                                            });
                                                                          }
                                                                        }
                                                                      });
                                                                    }
                                                                  });
                                                                });
                                                              }
                                                            }
                                                          });
                                                        }
                                                      });
                                                    });
                                                  }
                                                }
                                              });
                                            }
                                          });
                                        });
                                        //end of toevoegen annotaties aan video
                                      }
                                    }
                                  });
                                });
                                //end of add video's
                              } // end of all users added
                            }
                          }
                        );
                      }); //end add users
                    }
                  }); //end remove videos
                }
              }); // end remove groups
            }
          }); //end remove assignment
        }
      }); //end remove annotations
    }
  }); //end remove users
}

module.exports = seedDB;
