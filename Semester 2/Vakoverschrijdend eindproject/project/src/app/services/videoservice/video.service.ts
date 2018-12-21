import {Injectable} from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";

import {BehaviorSubject} from 'rxjs/BehaviorSubject';
import {catchError, retry} from "rxjs/operators";
import {Observable} from 'rxjs/Observable';
import {ErrorObservable} from 'rxjs/observable/ErrorObservable';
import 'rxjs/add/operator/map';
import { Router } from "@angular/router";
import { Video } from "../../models/video";
import { Assignment } from '../../models/assignment';

const httpOptions = {
  headers: new HttpHeaders({'Content-Type': 'application/json'})
};

const baseurl = "http://backend.annotatietool-01.project.tiwi.be/api/video";//docker
//const baseurl = "http://localhost:9016/api/video";//local
@Injectable()
export class VideoService {

  constructor(private http:HttpClient,private router: Router) { }

  getVideos(){
    return this.http.get<any>(baseurl)
  }

  getVideo(id) {
    const endpoint = baseurl + "/" + id;
    return this.http.get<any>(endpoint, httpOptions);
  }

  /*
     getGroup(id: string): Observable<Group> {
      return this.http.get<Group>(apiUrl + id,httpOptions);

      return this.http.get(apiUrl)
       .map((res: Response) => res.json())
       .catch((err: any) => Observable.throw(err.json().error || 'Server error'));
    }*/

  postVideo(fileToUpload: File, title: string, assId: string) {
    const endpoint = baseurl + "/upload";
    var formData: FormData = new FormData();
    formData.append("video", fileToUpload);
    formData.append("title", title);
    formData.append("assignment", assId);
    console.log(fileToUpload);

    return this.http
      .post(endpoint, formData, {headers:{}} )
      .pipe(
        catchError(this.handleError)
      );
  }

  /*
    postVideo(fileToUpload: File , title: string, assId: string) {
      console.log(fileToUpload);
      const data = {
        file: fileToUpload,
        name: title,
        assignment: assId
      }
      return this.http
        .post(baseurl + "/upload", data).subscribe(res=>console.log("Done"));
    }*/

  private handleError(error: HttpErrorResponse) {
    //TODO: tijdelijke oplossing refine error handling
    //TODO: in beste geval doorsturen naar de component en daar afhandelen.
    if (error.error instanceof ErrorEvent) {
      // A client-side or network error occurred. Handle it accordingly.
      console.error('An error occurred:', error.error.message);
      return new ErrorObservable(
        'Something bad happened; please try again later.');
    } else {
      // The backend returned an unsuccessful response code.
      // The response body may contain clues as to what went wrong,
      console.error(
        `Backend returned code ${error.status}, ` +
        `body was: ${error.error}`);

      if(error.error && error.error != "") {
        return new ErrorObservable(
          error.error);
      }else{
        return new ErrorObservable(
          'Something bad happened; please try again later.');
      }
    }

    // return an ErrorObservable with a user-facing error message
  };
}
