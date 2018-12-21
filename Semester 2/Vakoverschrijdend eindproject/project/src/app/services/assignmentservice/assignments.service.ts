import {Injectable} from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
import {Assignment} from "../../models/assignment"
import 'rxjs/add/operator/map';
import {catchError, retry} from "rxjs/operators";
import {Observable} from 'rxjs/Observable';
import {ErrorObservable} from 'rxjs/observable/ErrorObservable';
import {} from '@angular/common/http';

const httpOptions = {
  headers: new HttpHeaders({'Content-Type': 'application/json', 'Authorization': localStorage.getItem('token')})
};

//const apiUrl = "http://localhost:9016/api/assignment/";//local
const apiUrl = "http://backend.annotatietool-01.project.tiwi.be/api/assignment/";//docker
@Injectable()
export class AssignmentsService {

  constructor(private http: HttpClient) {
  }

  getAssignments() {
    return this.http.get<any>(apiUrl,httpOptions)
  }

  getUploadableAssignments() { //geeft andere assignments afhankelijk student of docent
    return this.http.get<any>(apiUrl+"uploadable",httpOptions)
  }

  getStudentAssignments(): Observable<Assignment[]> {
    return this.http.get<Assignment[]>(apiUrl+"student", httpOptions)
      .pipe(
        retry(3),
        catchError(this.handleError)
      )
  }

  getAssignment(id: number): Observable<Assignment> {
    return this.http.get<Assignment>(apiUrl + id, httpOptions);

    /*return this.http.get(apiUrl)
      .map((res: Response) => res.json())
      .catch((err: any) => Observable.throw(err.json().error || 'Server error'));*/
  }

  putAssignment(assignment: Assignment) {
    return this.http.put<Assignment>(apiUrl + assignment._id, assignment, httpOptions)
      .pipe(
        catchError(this.handleError)
      );
  }

  postOrPutAssignment(assignment: Assignment) {
    console.log(assignment._id);
    if (assignment._id != null) {
      console.log("EDIT");
      return this.putAssignment(assignment);
    } else {
      return this.postAssignment(assignment);
    }
  }

  postAssignment(assignment: Assignment) {
    console.log("CREATE");
    return this.http.post<Assignment>(apiUrl, assignment, httpOptions)
      .pipe(
        catchError(this.handleError)
      );
  }

  deleteAssignment(id: number) {
    console.log(id);
    return this.http.delete<Assignment>(apiUrl + id, httpOptions)
      .pipe(
        catchError(this.handleError)
      );
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
