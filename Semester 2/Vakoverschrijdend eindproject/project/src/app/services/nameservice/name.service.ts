import { Injectable } from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
// import { Assignment } from "../../models/assignment"
import 'rxjs/add/operator/map';
import {catchError, retry} from "rxjs/operators";
import { Observable } from 'rxjs/Observable';
import { ErrorObservable } from 'rxjs/observable/ErrorObservable';
import  {} from '@angular/common/http';

const httpOptions = {
  headers: new HttpHeaders({ 'Content-Type': 'application/json' })
};

//const apiUrl = "http://localhost:9016/api/assignment/";//local
const apiUrl = "http://backend.annotatietool-01.project.tiwi.be/api/assignment/";//docker
@Injectable()
export class NameService {

  constructor(private http:HttpClient) {}

  private handleError(error: HttpErrorResponse) {
    //TODO: tijdelijke oplossing refine error handling
    //TODO: in beste geval doorsturen naar de component en daar afhandelen.
    if (error.error instanceof ErrorEvent) {
      // A client-side or network error occurred. Handle it accordingly.
      console.error('An error occurred:', error.error.message);
    } else {
      // The backend returned an unsuccessful response code.
      // The response body may contain clues as to what went wrong,
      console.error(
        `Backend returned code ${error.status}, ` +
        `body was: ${error.error}`);
    }
    // return an ErrorObservable with a user-facing error message
    return new ErrorObservable(
      'Something bad happened; please try again later.');
  };
}
