import { Component, OnInit } from '@angular/core';
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import {ActivatedRoute} from "@angular/router";
import {Assignment} from "../../models/assignment";

@Component({
  selector: 'app-assignment-student-view-detail-detail',
  templateUrl: './assignment-student-view-detail-detail.component.html',
  styleUrls: ['./assignment-student-view-detail-detail.component.scss']
})
export class AssignmentStudentViewDetailDetailComponent implements OnInit {
  assignment: Assignment = new Assignment("", "", false, false, Date.now().toString(),Date.now().toString());
  assignmentId: string;

  constructor(private route: ActivatedRoute, private _assignmentsService: AssignmentsService) {
    this.route.params.subscribe( params => this.getAssignment(params['id']) );
  }

  ngOnInit() {

  }

  getAssignment(id){
    console.log(id);
    this.assignmentId = id;
    this._assignmentsService.getAssignment(id).subscribe(data => {
      this.assignment = data;
    }, error => {
      console.log(error);
    });
  }

}
