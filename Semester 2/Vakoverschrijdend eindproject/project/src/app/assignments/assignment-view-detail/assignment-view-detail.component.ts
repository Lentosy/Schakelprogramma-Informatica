import {Component, EventEmitter, Input, OnInit, Output} from '@angular/core';
import {Assignment} from "../../models/assignment";
import {Router} from "@angular/router";
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import { UserService } from '../../services/userservice/user.service';

@Component({
  selector: 'app-assignment-view-detail',
  templateUrl: './assignment-view-detail.component.html',
  styleUrls: ['./assignment-view-detail.component.scss']
})
export class AssignmentViewDetailComponent implements OnInit {

  isDocent : boolean;

  @Output()
  refreshEvent = new EventEmitter();

  @Input()
  assignment: Assignment;

  constructor(private router: Router, private _assignmentService: AssignmentsService, private userService: UserService) {
  }

  ngOnInit() {
    this.userService.localUserRole.subscribe((value: string) => {
      if(value === "docent"){
        this.isDocent = true;
      }else{
        this.isDocent = false;
      }
    });
  }

  editAssignment() {
    this.router.navigate(['assignment/settings',this.assignment._id]);
  }

  deleteAssignment() {
    //this.data.empty();
    this._assignmentService.deleteAssignment(this.assignment._id)
      .subscribe(data => this.assignment = data,
        error => console.log(error.body),
        () => {
          this.refreshEvent.emit();
        });
  }
}
