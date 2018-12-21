import { Component, OnInit, Input } from '@angular/core';
import {Assignment} from "../../models/assignment";
import {UserService} from "../../services/userservice/user.service";

@Component({
  selector: 'app-assignment-student-view-detail',
  templateUrl: './assignment-student-view-detail.component.html',
  styleUrls: ['./assignment-student-view-detail.component.scss']
})
export class AssignmentStudentViewDetailComponent implements OnInit {
  @Input()
  set assignment(assignment: Assignment){
    this._assignment = assignment;

    var self = this;
    this._userService.localUserId.subscribe(function (data) {
      console.log("eigen userId:");
      console.log(data);
      self._assignment.videos.forEach(function (video) {
        console.log(video.userId._id);
        if(video.userId._id == data){
          self.myVideo = video;
        }
      });
      var indexDeletingVid = self._assignment.videos.indexOf(self.myVideo);
      if(indexDeletingVid != -1)
        self._assignment.videos.splice(indexDeletingVid, 1);
    });

    this.uploadDeadline = new Date(this._assignment.uploadDeadline);
    this.annoDeadline = new Date(this._assignment.annotationDeadline);
    this.now = new Date();

    console.log(this._assignment);
  }

  _assignment: Assignment;

  uploadDeadline: Date;
  annoDeadline: Date;
  now: Date;
  myVideo: any = null;

  constructor(private _userService : UserService) { }

  ngOnInit() {

  }

}
