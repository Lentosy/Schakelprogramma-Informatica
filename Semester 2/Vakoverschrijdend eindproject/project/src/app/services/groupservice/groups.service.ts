import { Injectable } from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
import {Group} from "../../models/group";
import 'rxjs/add/operator/map';
import {catchError, retry} from "rxjs/operators";
import { Observable } from 'rxjs/Observable';
import { ErrorObservable } from 'rxjs/observable/ErrorObservable';


const apiUrl = "http://backend.annotatietool-01.project.tiwi.be/api/group/";//docker
//const apiUrl = "http://localhost:9016/api/group/";//docker2
//const apiUrl = "http://localhost:3000/api/group/";//local
const httpOptions = {
  headers: new HttpHeaders({ 'Content-Type': 'application/json' })
};


@Injectable()
export class GroupsService {

  

  constructor(private http:HttpClient) { }


  postGroup(fileToUpload: File, className: string) : Observable<Group> {
    const formData: FormData = new FormData();
    formData.append('studentsFile', fileToUpload, fileToUpload.name);
    formData.append('name', className);
    return this.http
      .post<Group>(apiUrl, formData, {headers: { }})
      .pipe(
        catchError(this.handleError)
      );
  }

  deleteGroup(group: Group) : Observable<any> {
    return this.http
      .delete(apiUrl+group._id, {headers: { }})
      .pipe(
        catchError(this.handleError)
      );
  }

  removeStudentFromGroup(student, groupId) : Observable<any> {
    return this.http
      .delete(apiUrl+groupId+"/"+student.studentNumber, {headers: { }})
      .pipe(
        catchError(this.handleError)
      );
  }

  getGroups(): Observable<Group[]> {
    return this.http.get<Group[]>(apiUrl,httpOptions)
      .pipe(
        retry(3),
        catchError(this.handleError)
      );
  }

  getMemberGroups(): Observable<Group[]> { //geeft alle groepen waar je een member van bent
    return this.http.get<Group[]>(apiUrl+'member',httpOptions)
      .pipe(
        retry(3),
        catchError(this.handleError)
      );
  }

  getGroup(id: string): Observable<Group> {
    return this.http.get<Group>(apiUrl + id,httpOptions);

    /*return this.http.get(apiUrl)
     .map((res: Response) => res.json())
     .catch((err: any) => Observable.throw(err.json().error || 'Server error'));*/
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
