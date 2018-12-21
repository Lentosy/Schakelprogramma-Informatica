import { Component, OnInit } from '@angular/core';
import {GroupsService} from "../../services/groupservice/groups.service";
import {Group} from "../../models/group";

@Component({
  selector: 'app-group-student-view',
  templateUrl: './group-student-view.component.html',
  styleUrls: ['./group-student-view.component.scss']
})
export class GroupStudentViewComponent implements OnInit {
  groups: Group[] = [];
  error: string = null;

  constructor(private _groupsService: GroupsService) { }

  ngOnInit() {
    this.getGroups();
  }

  getGroups() {
    this._groupsService.getMemberGroups()
      .subscribe(data => {this.groups = data; console.log(data)},
        error => this.error = error);
  }

}
