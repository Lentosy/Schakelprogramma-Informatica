let mongoose = require("mongoose");

let categorySchema = new mongoose.Schema({
    type:String,

    //relatie (onder voorbehoud)
    videos:[
        {
            
              type: mongoose.Schema.Types.ObjectId,
              ref: "Video"
            
          }
    ]
});

let Category = mongoose.model("Category", categorySchema);
module.exports = Category;
