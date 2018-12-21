import { Component, OnInit } from '@angular/core';
import {NgbModal, ModalDismissReasons,NgbModalRef} from '@ng-bootstrap/ng-bootstrap';
import {GroupsService} from "../../services/groupservice/groups.service";
import {Group} from "../../models/group";

@Component({
  selector: 'app-group-view',
  templateUrl: './group-view.component.html',
  styleUrls: ['./group-view.component.css']
})
export class GroupViewComponent implements OnInit {
  private modalObj: NgbModalRef;
  fileToUpload: File = null;
  closeResult: string;
  newClassName: string = "";
  error: string = null;
  deleteClassObj = null;

  groups: Group[] = [];

  constructor(private modalService: NgbModal, private _groupsService: GroupsService) {}

  ngOnInit() {
    this.getGroups();
  }

  open(content) {
    this.modalObj = this.modalService.open(content);
    this.modalObj.result.then((result) => {
      this.closeResult = `Closed with: ${result}`;
    }, (reason) => {
      this.closeResult = `Dismissed ${this.getDismissReason(reason)}`;
    });
  }
  deleteClassClick(group, content){
    this.deleteClassObj = group;
    this.open(content);
    return false;
  }
  deleteClass(){
    this._groupsService.deleteGroup(this.deleteClassObj).subscribe(data => {
      for (let i = 0; i < this.groups.length; ++i) {
          if(this.groups[i]._id == this.deleteClassObj._id) this.groups.splice(i, 1);
      }
      this.deleteClassObj = null;
      this.modalObj.close("done");
    }, error => {
      console.log(error);
    });
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

  handleFileInput(files: FileList) {
    console.log("file veranderd");
    this.fileToUpload = files.item(0);
  }

  postNewGroup() {
    console.log("post klik"+ this.newClassName);
    this._groupsService.postGroup(this.fileToUpload, this.newClassName).subscribe(data => {
      this.groups.push(data);
      this.newClassName = "";
      this.fileToUpload = null;
      this.modalObj.close("done");
    }, error => {
      console.log(error);
    });
  }

  getGroups() {
    this._groupsService.getGroups()
      .subscribe(data => this.groups = data,
        error => this.error = error);
  }

}
