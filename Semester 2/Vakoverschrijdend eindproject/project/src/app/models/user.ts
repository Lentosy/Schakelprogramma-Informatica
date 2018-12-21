import { Video } from "./video";
import { Annotation } from "./annotation";

export class User{
    _id : string;
    username: string;
    firstName: string;
    lastName: string;
    rol: string;
    studentNumber : number;
    videos:Video[];
    annotations:Annotation[];

    constructor(){
      this.annotations = [];
      this.videos = [];
      this.studentNumber = 0;
      this.rol = "";
      this.username = "";
    }
}
