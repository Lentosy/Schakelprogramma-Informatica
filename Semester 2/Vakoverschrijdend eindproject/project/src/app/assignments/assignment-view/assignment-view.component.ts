import {Component, OnInit} from '@angular/core';
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import {Assignment} from "../../models/assignment";
import {Router} from "@angular/router";

@Component({
  selector: 'app-assignment-view',
  templateUrl: './assignment-view.component.html',
  styleUrls: ['./assignment-view.component.scss']
})
export class AssignmentViewComponent implements OnInit {

  assignment: Assignment;// = new Assignment();
  assignments: Assignment[] = [];
  error: string = null;

  constructor(private router: Router, private _assignmentService: AssignmentsService) {
  }

  ngOnInit() {
    this.getAssignments();
  }

  createAssignment() {
    this.router.navigate(['assignment/settings','new']);
  }

  //API CALLS
  getAssignments() {
    this.assignments = [];
    this._assignmentService.getAssignments()
      .subscribe(data => {this.assignments = data; console.log(this.assignments);},
        error => this.error = error);
  }

  getAssignment(id: number) {
    this._assignmentService.getAssignment(id)
      .subscribe(data => this.assignment = data,
        error => this.error = error);
  }

  updateAssignment(assignment: Assignment) {
    //let patientJson = JSON.stringify(assignment);

    this._assignmentService.putAssignment(assignment)
      .subscribe(data => this.assignment = data,
        error => this.error = error);
  }

  postAssignment(assignment: Assignment) {
    //let patientJson = JSON.stringify(assignment);

    this._assignmentService.postAssignment(assignment)
      .subscribe(data => this.assignment = data,
        error => this.error = error);
  }

}
