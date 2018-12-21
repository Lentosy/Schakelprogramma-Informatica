import { Component, OnInit } from "@angular/core";
import { Video } from "../../models/video";
import { Assignment } from "../../models/assignment";
import { NgxCarousel } from "ngx-carousel";
import { VideoService } from "../../services/videoservice/video.service";
import { AssignmentsService } from "../../services/assignmentservice/assignments.service";
import { HttpErrorResponse } from "@angular/common/http";
import { Router } from "@angular/router";
import { UserService } from "../../services/userservice/user.service";

@Component({
  selector: "app-dashboard-view",
  templateUrl: "./dashboard-view.component.html",
  styleUrls: ["./dashboard-view.component.css"]
})
export class DashboardViewComponent implements OnInit {
  videos: Video[] = [];
  assignments: Assignment[] = [];
  error: string = null;
  public carouselTileTwo: NgxCarousel;
  role = "";
  loading = 1;

  constructor(
    private _videoService: VideoService,
    private _assignmentService: AssignmentsService,
    private router: Router,
    private _userService: UserService
  ) {}

  ngOnInit() {
    this.getVideos();
    this.carouselTileTwo = {
      grid: { xs: 1, sm: 3, md: 4, lg: 6, all: 230 },
      speed: 600,
      interval: 3000,
      point: {
        visible: true
      },
      load: 2,
      touch: true
    };
    let self = this;
    this._userService.localUserRole.subscribe(
      role => {
        console.log(role);
        self.role = role;
        this.getAssignments();
      },
      err => console.log(err)
    );
  }

  getVideos() {
    this._videoService.getVideos().subscribe(
      res => {
        var tempArray = [];
        this._userService.localUserId.subscribe(id => {
          res.forEach(element => {
            console.log(element.userId);
            if (element.userId == id) {
              tempArray.push(element);
            }
          });
        });
        this.videos = tempArray;
      },
      error => {
        if (error instanceof HttpErrorResponse) {
          if (error.status === 401) {
            this.router.navigate(["/login"]);
          }
        }
      },
      () => this.loading++
    );
  }

  getAssignments() {
    if (this.role == "student") {
      console.log(this.role);
      this._assignmentService
        .getStudentAssignments()
        .subscribe(
          res => (this.assignments = res),
          error => console.error(error),
          () => console.log("getAssignments is klaar!")
        );
    } else {
      this._assignmentService
        .getAssignments()
        .subscribe(
          res => (this.assignments = res),
          error => console.error(error),
          () => console.log("getAssignments is klaar!")
        );
    }
  }
}
