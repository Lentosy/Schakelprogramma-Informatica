export class Group {
  _id : string;
  name : string;
  students: [{
    studentNumber: string,
    firstName: string,
    lastName: string
  }];
  assignments: any[];

  constructor(){
    this.name = "";
    this.students = null;
  }
}
