import { Component, OnInit } from '@angular/core';
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import {Router} from "@angular/router";
import {Assignment} from "../../models/assignment";

@Component({
  selector: 'app-assignment-student-view',
  templateUrl: './assignment-student-view.component.html',
  styleUrls: ['./assignment-student-view.component.scss']
})
export class AssignmentStudentViewComponent implements OnInit {

  assignments: Assignment[] = [];
  error: string = null;

  constructor(private router: Router, private _assignmentService: AssignmentsService) {
  }

  ngOnInit() {
    this.getAssignments();
  }

  getAssignments() {
    this.assignments = [];
    this._assignmentService.getStudentAssignments()
      .subscribe(data => this.assignments = data,
        error => this.error = error);
  }

}
