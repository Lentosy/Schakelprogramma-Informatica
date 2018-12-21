var middlewareObj = {};
var jwt = require("jsonwebtoken");

middlewareObj.verifyToken= function(req,res,next){
    if(!req.headers.authorization){
        return res.status(401).send("unauthorized");
    }
    let token = req.headers.authorization.split(' ')[1];
    if(token === 'null'){
        return res.status(401).send("unauthorized");
    }
    let payload = jwt.verify(token, "secret key");
    if(!payload){
        return res.status(401).send("unauthorized");
    }
    req.user = payload;

    next();
}

middlewareObj.verifyTokenTeacher= function(req,res,next){
  if(!req.headers.authorization){
    return res.status(401).send("unauthorized");
  }
  let token = req.headers.authorization.split(' ')[1];
  if(token === 'null'){
    return res.status(401).send("unauthorized");
  }
  let payload = jwt.verify(token, "secret key");
  if(!payload){
    return res.status(401).send("unauthorized");
  }
  req.user = payload;
  if(req.user.rol == "student"){
    return res.status(401).send("unauthorized");
  }

  next();
}

module.exports = middlewareObj;
