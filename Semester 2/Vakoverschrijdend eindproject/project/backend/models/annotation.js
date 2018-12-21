let mongoose = require("mongoose");
let annotationSchema = new mongoose.Schema({
    videoId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "Video"
    },
    userId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User"
    },
    description: String,
    beginTime: Number,
    endTime: Number
});

let Annotation = mongoose.model("Annotation", annotationSchema);
module.exports = Annotation;
