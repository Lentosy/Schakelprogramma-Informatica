import { Component, OnInit } from '@angular/core';
import {GroupsService} from "../../services/groupservice/groups.service";
import {Group} from "../../models/group";
import {ActivatedRoute} from "@angular/router";
import {NgbModal, ModalDismissReasons,NgbModalRef} from '@ng-bootstrap/ng-bootstrap';

@Component({
  selector: 'app-group-detail-view',
  templateUrl: './group-detail-view.component.html',
  styleUrls: ['./group-detail-view.component.css']
})
export class GroupDetailViewComponent implements OnInit {

  group: Group = new Group();
  groupId: string;
  deleteStudentObj: any;

  private modalObj: NgbModalRef;
  closeResult: string;

  constructor(private modalService: NgbModal, private route: ActivatedRoute, private _groupsService: GroupsService) {
    this.route.params.subscribe( params => this.getGroup(params['id']) );
  }

  open(content) {
    this.modalObj = this.modalService.open(content);
    this.modalObj.result.then((result) => {
      this.closeResult = `Closed with: ${result}`;
    }, (reason) => {
      this.closeResult = `Dismissed ${this.getDismissReason(reason)}`;
    });
  }

  getGroup(id){
    console.log(id);
    this.groupId = id;
    this._groupsService.getGroup(id).subscribe(data => {
      this.group = data;
    }, error => {
      console.log(error);
    });
  }

  deleteStudentClick(student, content){
    this.deleteStudentObj = student;
    this.open(content);
  }

  deleteStudent(){
    this._groupsService.removeStudentFromGroup(this.deleteStudentObj, this.groupId).subscribe(data => {
      for (let i = 0; i < this.group.students.length; ++i) {
        if(this.group.students[i].studentNumber == this.deleteStudentObj.studentNumber) this.group.students.splice(i, 1);
      }
      this.deleteStudentObj = null;
      this.modalObj.close("done");
    }, error =>{
      console.log(error);
    });
  }

  ngOnInit() {

  }

  private getDismissReason(reason: any): string {
    if (reason === ModalDismissReasons.ESC) {
      return 'by pressing ESC';
    } else if (reason === ModalDismissReasons.BACKDROP_CLICK) {
      return 'by clicking on a backdrop';
    } else {
      return  `with: ${reason}`;
    }
  }

}
