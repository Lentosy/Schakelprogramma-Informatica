let mongoose = require("mongoose");

let assignmentSchema = new mongoose.Schema({
  name: String,
  description: String,
  owner: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User"
  },
  deadline: String,
  teacherUpload: Boolean,
  privateAnnotations: Boolean,
  annotationDeadline: String,
  uploadDeadline: String,
  dropdown: [String],
  quickComments: [String],
  rubric: [{
    theme: String,
    score: String,
    description: String
  }],
  deleted: Boolean,

  //relaties
  videos: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Video"
    }
  ],
  groups: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Group"
    }
  ]
});

let Assignment = mongoose.model("Assignment", assignmentSchema);
module.exports = Assignment;
