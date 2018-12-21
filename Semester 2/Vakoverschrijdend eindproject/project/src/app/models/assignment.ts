import { Group } from "./group";

export class Assignment {
  _id : number;
  name : string;
  description : string;
  teacherUpload :boolean;
  privateAnnotations : boolean;
  annotationDeadline: string;
  uploadDeadline: string;
  deleted: boolean;
  groups: any[];
  videos: any[];
  dropdown: string[];
  quickComments: string[];
  rubric: [{
    theme: string,
    score: string,
    description: string
  }];

  constructor(name,descr,Tupload,privateAnno,annoDead,uploadDead){
    this.name = name;
    this.description = descr;
    this.teacherUpload =Tupload;
    this.privateAnnotations = privateAnno;
    this.annotationDeadline= annoDead;
    this.uploadDeadline = uploadDead;
    this.dropdown = [];
    this.rubric = [{
      theme: "",
      score: "",
      description: ""
    }];
    this.quickComments = [];
    this.deleted = false;
  }

}
