import {Injectable} from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
import {Annotation} from "../../models/annotation";
import {Video} from "../../models/video";
import {Observable} from 'rxjs/Observable';
import {catchError, retry} from "rxjs/operators";
import {ErrorObservable} from 'rxjs/observable/ErrorObservable';

const httpOptions = {
  headers: new HttpHeaders({'Content-Type': 'application/json', 'Authorization': localStorage.getItem('token')})
};

const baseurl = "http://backend.annotatietool-01.project.tiwi.be/api/annotation";//docker
//const baseurl = "http://localhost:9016/api/annotation"//local

@Injectable()
export class AnnotationService {

  constructor(private http: HttpClient) {
  }

  getAnnotaties(): Observable<Annotation[]> {
    return this.http.get<Annotation[]>(baseurl, httpOptions)
      .pipe(
        retry(3),
        catchError(this.handleError)
      )
  }

  addAnnotation(annotation: Annotation): Observable<Annotation> {
    console.log(localStorage.getItem('jwtToken'));
    return this.http.post<Annotation>(baseurl, annotation, httpOptions)
      .pipe(
        retry(3),
        catchError(this.handleError)
      )
  }

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
