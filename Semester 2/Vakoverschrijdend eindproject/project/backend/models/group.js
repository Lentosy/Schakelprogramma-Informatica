let mongoose = require("mongoose");

let groupSchema = new mongoose.Schema({
  docentId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User"
  },
  name: String,

  //relations
  groups: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Group"
    }
  ],
  assignments: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Assignment"

    }
  ],

  studentNumbers: [String],
  students: [
    {
      studentNumber: String,
      firstName: String,
      lastName: String
    }
  ]
});

let Group = mongoose.model("Group", groupSchema);
module.exports = Group;
