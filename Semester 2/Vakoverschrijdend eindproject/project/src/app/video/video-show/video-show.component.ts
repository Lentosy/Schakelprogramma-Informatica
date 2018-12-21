import {Component, Input, OnInit} from '@angular/core';
import {Subscriber} from 'rxjs/Subscriber';
import {HttpClient} from '@angular/common/http';
import {AnnotationService} from '../../services/annotationservice/annotation.service';
import {VideoService} from '../../services/videoservice/video.service'
import {forEach} from '@angular/router/src/utils/collection';
import {Annotation} from '../../models/annotation';
import {Video} from '../../models/video'
import {ActivatedRoute} from "@angular/router";
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import {Assignment} from "../../models/assignment";
import {VgAPI} from "videogular2/core";
import {UserService} from '../../services/userservice/user.service'
import {ExportFileService} from '../../services/exportfileservice/exportfile.service'

@Component({
  selector: 'video-show.component',
  templateUrl: './video-show.component.html',
  styleUrls: ['./video-show.component.scss']
})

export class VideoShowComponent implements OnInit {
  error: string = null;

  currentTimeString: string = "00:00";
  endTimeString: string = "00:00";

  //zeker nodig
  video: Video = null;
  assignment: any = null;
  dropdownSelection: string;
  videoPlayer;
  videoApi;

  //rubric
  rubricScoreSelection: string;
  rubricThemeSelection: string;
  rubricScores = ["Onvoldoende <5", "Matig 6", "Goed 7/8", "Uitstekend 9/10"];
  rubricDesc: string;

  //annotatiedata
  videoId: string;
  endTime: number = 0;
  beginTime: number = 0;
  commentInput: string;

  //streamlokaal port
  //streamsrc : string = "http://localhost:9016/api/video/stream/";
  //stream server port
  streamsrc : string = "http://backend.annotatietool-01.project.tiwi.be/api/video/stream/";

  constructor(private _videoService: VideoService,
              private _annotationService: AnnotationService,
              private _assignmentsService: AssignmentsService,
              private route: ActivatedRoute,
              private _userService: UserService,
              private _exportFileService: ExportFileService) {

  };

  ngOnInit() {
    //this.getAnnotations();
    this.route.params.subscribe(params => {
      this.streamsrc += params['id'];
      //console.log("Nieuwe streamsrc: " + this.streamsrc)
      this.getVideo(params['id']);
      this.videoId = params['id'];
    });

    this._userService.requestLocalUser();
  }

  getVideoApi(api: VgAPI) {
    this.videoPlayer = api.getDefaultMedia();
    this.videoApi = api;
    this.videoApi.getDefaultMedia().subscriptions.timeUpdate.subscribe(() => this.updateCurrentTimeString());
  }

  setCurrentTime(newVal: number) {
    if (newVal < 0)
      newVal = 0;
    if (newVal > Math.floor(this.videoPlayer.duration))
      newVal = Math.floor(this.videoPlayer.duration);

    var dif: number = newVal - Math.floor(this.videoPlayer.currentTime);
    let currentTime = Math.floor(newVal);
    this.endTime = (Number(this.endTime) + dif);

    if (this.endTime < currentTime)
      this.endTime = currentTime;
    if (this.endTime > this.videoPlayer.duration && this.videoPlayer.duration != 0)
      this.endTime = Math.floor(this.videoPlayer.duration);


    this.endTimeString = pad(Math.floor(this.endTime / 60), 2) + ":" + pad(this.endTime % 60, 2);
    this.currentTimeString = pad(Math.floor(currentTime / 60), 2) + ":" + pad(currentTime % 60, 2);

    if (Math.floor(this.videoPlayer.currentTime) != Math.floor(currentTime)) {
      this.videoPlayer.currentTime = (currentTime);
    }
  }

  changeCurrentTime(amount) {
    let current = this.videoPlayer.currentTime;
    this.setCurrentTime(amount + current);
    this.videoPlayer.pause();
  }

  setEndTime(newVal) {
    if (newVal < this.videoPlayer.currentTime)
      newVal = this.videoPlayer.currentTime;
    if (newVal > this.videoPlayer.duration)
      newVal = this.videoPlayer.duration;

    this.endTime = Math.floor(newVal);
    this.endTimeString = pad(Math.floor(this.endTime / 60), 2) + ":" + pad(this.endTime % 60, 2);
  }

  changeEndTime(amount) {
    this.setEndTime(amount + this.endTime);
    this.videoPlayer.pause();
  }

  setVideoTimestamp(timestamp: number) {
    this.videoPlayer.currentTime = timestamp;
  }

  pauzeFocus() {
    this.videoPlayer.pause();
  }

  getVideo(id: string) {
    this._videoService.getVideo(id).subscribe(
      data => {
        this.video = data;
        this.assignment = this.video.assignmentId;
        this.sortAnnotations();
        this.video.annotations.forEach(element => {
          this._userService.cacheUserId(element.userId);
        });
      },
      error => console.log(error))
  }

  addAnnotation() {
    let ann = new Annotation();
    ann.beginTime = Math.floor(Number(this.videoPlayer.currentTime));
    ann.endTime = Math.ceil(Number(this.endTime));
    ann.description = this.commentInput;
    ann.videoId = this.videoId;
    this.commentInput = "";

    ann.userId = this._userService.getLocalUserId();

    this.cacheAnnotationAndSort(ann);
  }

  addQuickComment(text: string) {
    let currentTime = this.videoPlayer.currentTime;

    let ann = new Annotation();
    ann.beginTime = Math.floor(Number(currentTime));
    ann.endTime = Math.ceil(Number(currentTime));
    ann.description = text;

    ann.userId = this._userService.getLocalUserId();
    ann.videoId = this.videoId;

    this.cacheAnnotationAndSort(ann);
  }

  addDropdownComment(): void {
    let currentTime = this.videoPlayer.currentTime;

    let ann = new Annotation();
    ann.beginTime = Math.floor(Number(currentTime));
    ann.endTime = Math.ceil(Number(currentTime));
    console.log(this.dropdownSelection);
    ann.description = this.dropdownSelection;

    ann.userId = this._userService.getLocalUserId();
    ann.videoId = this.videoId;

    this.cacheAnnotationAndSort(ann);
  }

  addRubricComment() {
    let currentTime = this.videoPlayer.currentTime;

    let ann = new Annotation();
    ann.beginTime = Math.floor(Number(currentTime));
    ann.endTime = Math.ceil(Number(currentTime));
    ann.description = this.rubricThemeSelection + " - " + this.rubricScoreSelection + ": " + this.rubricDesc;

    ann.userId = this._userService.getLocalUserId();
    ann.videoId = this.videoId;

    this.cacheAnnotationAndSort(ann);
  }

  cacheAnnotationAndSort(annotation: Annotation) {
    this.video.annotations.push(annotation);

    this.video.annotations.forEach(element => {
      console.log(element._id + ' ' + element.beginTime + ' ' + element.userId);
    });

    this.sortAnnotations();

    this._annotationService.addAnnotation(annotation).subscribe(data => {
      this.videoPlayer.play();
    }, error => {
      console.log(error);
    });
  }

  sortAnnotations() {
    if (this.video) {
      // Indien zelfde starttijd, ook sorteren op naam?
      // Indien zelfde naam, ook sorteren op categorie (bv quick comments)?
      this.video.annotations = this.video.annotations.sort((a, b): number => {
        if (a.beginTime < b.beginTime)
          return -1;
        else if (a.beginTime === b.beginTime)
          return 0;
        else if (a.beginTime > b.beginTime)
          return 1;
      });
    }
  }

  checkAnnotationDeadline() {
    if (this.assignment == null) {
      return false
    } else {
      return Date.parse(this.assignment.annotationDeadline) >= Date.now();
    }
  }

  updateCurrentTimeString() {
    let currentTime = Math.floor(this.videoPlayer.currentTime);
    let time = pad(Math.floor(currentTime / 60), 2) + ":" + pad(currentTime % 60, 2);
    this.currentTimeString = time;
    this.endTimeString = time;
  }
}

//voo leading zero's
function pad(num, size) {
  var s = num + "";
  while (s.length < size) s = "0" + s;
  return s;
}






