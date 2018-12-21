"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Assignment = /** @class */ (function () {
    function Assignment(name, descr, annoTypes, Tupload, privateAnno, deadl) {
        this.name = name;
        this.description = descr;
        this.annotationTypes = annoTypes;
        this.teacherUpload = Tupload;
        this.privateAnnotations = privateAnno;
        this.deadline = deadl;
    }
    return Assignment;
}());
exports.Assignment = Assignment;
