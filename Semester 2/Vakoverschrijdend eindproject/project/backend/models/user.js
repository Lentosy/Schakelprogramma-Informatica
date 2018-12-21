let mongoose = require("mongoose");
var bcrypt = require('bcrypt-nodejs');

let userSchema = new mongoose.Schema({
    username: {
        type: String,
        unique: true,
        required: true
    },
    firstName: {
        type:String,
        required: true
    },
    lastName: {
        type:String,
        required: true
    },
  password: {
        type: String,
        required: true
    },
    rol: String, //of number
    studentNumber: String, // of string idk format

    //relaties
    videos: [
        {
            
                type: mongoose.Schema.Types.ObjectId,
                ref: "Video"
        
        }
    ],
    assignments: [
        {
            
                type: mongoose.Schema.Types.ObjectId,
                ref: "Assignment"
            
        }
    ]
    /*,
    groupsTeacher: [ //teacher beheert volgende groepen
        {
            groupTeacher: {
                type: mongoose.Schema.Types.ObjectId,
                ref: "Group"
            }
        }
    ]*/
  //je kan alle groups van een user ophalen door group.find(userId = id)
    // groups: [ //student zit in volgende groepen
    //     {
    //         group: {
    //             type: mongoose.Schema.Types.ObjectId,
    //             ref: "Group"
    //         }
    //     }
    // ]
});

userSchema.pre('save', function (next) {
    var user = this;
    if (this.isModified('password') || this.isNew) {
        bcrypt.genSalt(10, function (err, salt) {
            if (err) {
                return next(err);
            }
            bcrypt.hash(user.password, salt, null, function (err, hash) {
                if (err) {
                    return next(err);
                }
                user.password = hash;
                next();
            });
        });
    } else {
        return next();
    }
});

userSchema.methods.comparePassword = function (passw, cb) {
    bcrypt.compare(passw, this.password, function (err, isMatch) {
        if (err) {
            return cb(err);
        }
        cb(null, isMatch);
    });
};

module.exports = mongoose.model("User", userSchema);
