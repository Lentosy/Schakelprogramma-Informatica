import { Component, OnInit } from '@angular/core';
import {Group} from "../../models/group";
import {ActivatedRoute} from "@angular/router";
import {GroupsService} from "../../services/groupservice/groups.service";

@Component({
  selector: 'app-group-student-detail-view',
  templateUrl: './group-student-detail-view.component.html',
  styleUrls: ['./group-student-detail-view.component.scss']
})
export class GroupStudentDetailViewComponent implements OnInit {
  group: Group = new Group();
  groupId: string;

  constructor(private route: ActivatedRoute, private _groupsService: GroupsService) {
    this.route.params.subscribe( params => this.getGroup(params['id']) );
  }

  ngOnInit() {
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

}
