let mongoose = require("mongoose");

let videoSchema = new mongoose.Schema({
    userId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User"
    },
    assignmentId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "Assignment"
    },
    categoryId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "Category"
    },
    name: String,
    url: String, //zou ik op id doen ofwel dit
    deleted: Boolean,

    //relaties

    annotations: [
        {

                type: mongoose.Schema.Types.ObjectId,
                ref: "Annotation"

        }
    ]
});

let Video = mongoose.model("Video", videoSchema);
module.exports = Video;
