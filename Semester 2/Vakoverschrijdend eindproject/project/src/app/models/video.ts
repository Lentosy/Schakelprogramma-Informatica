import { Annotation } from "./annotation";

export class Video{
    _id : number;
    userId: any;//kan ook object zijn als je populate
    assignmentId : number;
    categoryId: number;
    name: string;
    url: string;
    deleted: boolean;
    annotations: Annotation[];

    constructor(){
      this.annotations = [];
      this.deleted = false;
      this.url ="";
      this.name = "";
      this.categoryId = null;
      this.assignmentId = null;
      this.userId = null;
    }
}
