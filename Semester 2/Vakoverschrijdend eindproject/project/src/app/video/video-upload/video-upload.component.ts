import { Component, OnInit  } from '@angular/core';
import { AssignmentsService } from "../../services/assignmentservice/assignments.service";
import { Assignment         } from "../../models/assignment";
import { VideoService       } from "../../services/videoservice/video.service";
import { Video              } from "../../models/video"
import { Router             } from "@angular/router";
import { forEach            } from "@angular/router/src/utils/collection";
import { isFulfilled } from 'q';
import {NgbModal} from "@ng-bootstrap/ng-bootstrap";
import {NgbModalRef} from "@ng-bootstrap/ng-bootstrap";
import {ModalDismissReasons} from "@ng-bootstrap/ng-bootstrap";
import { ViewChild } from '@angular/core';

@Component({
  selector: 'app-video-upload',
  templateUrl: './video-upload.component.html',
  styleUrls: ['./video-upload.component.css']
})

export class VideoUploadComponent implements OnInit {
  private modalObj: NgbModalRef;
  closeResult: string;
  @ViewChild('progressModel') private progressModel;

  assignments: Assignment[] = [];
  filename: string = "/";
  filesize: string = "/";
  filetype: string = "/";

  errorGlobal:      string = null; // global error (server fout)
  errorFile:        string = null; // error indien een fout bestand geselecteerd wordt
  errorTitle:       string = null; // error indien een lege titel meegegeven wordt
  errorAssignment:  string = null; // error indien er geen assignment geselecteerd wordt

  /* attributes for the form */
  title: string = null;
  assignmentId: string = null;
  videofile: File = null;
  uploadButton: HTMLButtonElement;


  constructor(private _videoService: VideoService,
              private _assignmentService: AssignmentsService,
              private _router: Router,
              private modalService: NgbModal) {

  }

  ngOnInit() {
    this.getAssignments();
    this.uploadButton = <HTMLButtonElement> document.getElementById("btn-upload-file");
  }

  /**
   * Haalt alle assignments op voor de huidige gebruiker
   */
  getAssignments() {
    this._assignmentService.getUploadableAssignments()
      .subscribe(data => {
          //filters na datum uit selectie
          let i = 0;
          for (let assignment of data) {
            if (Date.parse(assignment.uploadDeadline) >= Date.now()) {
              this.assignments[i] = assignment;
              i++;
            }
          }
        },
        error => this.errorGlobal = error);
  }

  /**
   * De gebruiker selecteert een bestand.
   * Zie https://developer.mozilla.org/en-US/docs/Web/API/File voor info over het File object.
   * @param files Een array van File objecten dat alle bestanden bevat, dit is default want HTML5 ondersteunt het selecteren
   *              van meerdere bestanden.
   */
  changeVideo(files: FileList): void {

    var file = files[0];


    var size = file.size; // grootte in bytes
    var filetype = file.type;

    //filetype = filetype.substr(0, filetype.indexOf('/')); // behoudt enkel [tekst]/....
    if (filetype !== 'video/mp4') {
      this.errorFile = "Het bestand is geen correct videobestand";
    }

    else {
      this.errorFile = null;
      this.uploadButton.removeAttribute('disabled');
      this.videofile = file;
      this.filename = file.name;
      this.filesize = this.getReadableSize(size);
      this.filetype = filetype;
    }
  }


  /**
   * De gebruiker verandert de titel
   * @param title de nieuwe titel
   */
  changeTitle(title: string): void{
    this.title = title;
    if(!this.title){
      this.errorTitle = "De titel mag niet leeg zijn";
    }else{
      this.errorTitle = null;
    }
  }

  /**
   * De gebruiker selecteert een assignment
   * @param element Het selectelement dat alle opties bevat
   */
  changeAssignment(element : HTMLSelectElement): void {
    this.assignmentId = element.children[element.selectedIndex].getAttribute("id");
    if(!this.assignmentId){
      this.errorAssignment = "Selecteer een taak"
    }else{
      this.errorAssignment = null;
    }
  }

  /**
   * Het uploaden van de video naar de server
   */
  uploadVideo(): void {
    if (this.title && this.assignmentId) {
      this.open(this.progressModel);
      this._videoService.postVideo(this.videofile, this.title, this.assignmentId)
        .subscribe(data => {
            this.modalObj.close("done");
            this._router.navigate(['/video/'+data._id]);
          },
          error => {
            this.modalObj.close("done");
            console.log(error);
            this.errorGlobal = error;
          });

    } else {
      this.errorGlobal = "Niet alle velden zijn correct ingevuld";
    }
  }


  open(content) {
    this.modalObj = this.modalService.open(content);
    this.modalObj.result.then((result) => {
      this.closeResult = `Closed with: ${result}`;
    }, (reason) => {
      this.closeResult = `Dismissed ${this.getDismissReason(reason)}`;
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


  /**
   * Geeft een leesbare versie van de grootte van het bestand
   * Voorbeeld: getReadableSize(31491130) => 31.49 MB
   */
  getReadableSize(size): string {
    var postfixes = ['B', 'KB', 'MB', 'GB'];
    var postfixindex = 0;
    while (size > 1000) {
      size /= 1000;
      postfixindex++;
    }
    var postfix = postfixes[postfixindex];
    return size.toFixed(2) + " " + postfix;
  }
}



