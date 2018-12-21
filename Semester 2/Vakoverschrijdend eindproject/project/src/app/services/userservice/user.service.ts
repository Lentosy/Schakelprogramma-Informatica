import {Injectable} from '@angular/core';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
import {Observable} from 'rxjs/Observable';
import {catchError, retry} from "rxjs/operators";
import {ErrorObservable} from 'rxjs/observable/ErrorObservable';
import {User} from '../../models/user'
import {BehaviorSubject} from "rxjs/BehaviorSubject"
import {ReplaySubject, Subject} from "rxjs";
import {Annotation} from "../../models/annotation";

const httpOptions = {
  headers: new HttpHeaders({'Content-Type': 'application/json'})
};

const apiUrl = "http://backend.annotatietool-01.project.tiwi.be/api/user";//docker
//const apiUrl = "http://localhost:9016/api/user";//local

@Injectable()
export class UserService {

  private _localUser: User = new User();
  private _idUserMapping: Map<string, User> = new Map();

  localUserName: Subject<string> = new ReplaySubject();
  localUserFullName: Subject<string> = new ReplaySubject();
  localUserRole: Subject<string> = new ReplaySubject();
  localStudentNumber: Subject<number> = new ReplaySubject();
  localUserId: Subject<string> = new ReplaySubject();

  constructor(private http: HttpClient) {
  }

  // Vraag de huidige gebruiker op via de backend
  requestLocalUser() {
    var userName = localStorage.getItem('userName');
    // if (!this._localUser.username.eq"") {
    if(this._localUser.username == ""){
        this.http.get<User>(apiUrl + '/me', httpOptions).subscribe(res => {
            this._localUser._id = res._id;
            this._localUser.username = res.username;
            this._localUser.firstName = res.firstName;
            this._localUser.lastName = res.lastName;
            // Zou nu moeten werken, zonder gebruik te maken van local storage, dus mogelijk verwijderen
            localStorage.setItem('name', this._localUser.firstName); //_localUser werkt niet goed dus doe ik het via localstorage
            this._localUser.rol = res.rol;
            this._localUser.studentNumber = res.studentNumber;
            this._localUser.annotations = res.annotations;
            this._localUser.videos = res.videos;

            this.localUserName.next(res.username);
            this.localUserFullName.next(res.firstName + " " + res.lastName);
            this.localUserRole.next(res.rol);
            this.localStudentNumber.next(res.studentNumber);
            this.localUserId.next(res._id);

            // Mapping heeft nood aan de lokale gebruiker om de annotaties correct te tonen
            this._idUserMapping.set(res._id, res);

            console.log('Received valid local user from backend: ' + this._localUser.username + '  name: '+ this._localUser.firstName  + '   id: ' + this._localUser.studentNumber + ' role: ' + this._localUser.rol + ' _id: ' + this._localUser._id);
          }, err => {
              this.handleError(err);
          });
      }
  }

  // Een gebruiker ophalen uit de backend op basis van de UserID
  getUserById(userId: number): Observable<User> {
    return this.http.get<User>(apiUrl + '/i/' + userId, httpOptions).pipe(retry(3), catchError(this.handleError));
  }

  // ID van huidige gebruiker om te gebruiken bij annotaties
  getLocalUserId(): string {
    var id = "";

    if (this._localUser) {
      id = this._localUser._id;
    } else {
      console.warn('Local user is null! Is this intended?');
    }

    return id;
  }

  getLocalUserStudentNumber(): number {
    var id = -1;

    if (this._localUser) {
      id = this._localUser.studentNumber;
    } else {
      console.warn('Local user is null! Is this intended?');
    }

    return id;
  }

  getLocalName(): string {
    var name = "";
    console.log(this._localUser);
    if(this._localUser){
      name = this._localUser.firstName;
    }else{
      console.warn("local user is null' Is this intended?");
    }
    return name;
  }


  getLocalUserRole(): string {
    var role = "";

    if (this._localUser) {
      role = this._localUser.rol;
    } else {
      console.warn('Local user is null! Is this intended?');
    }

    return role;
  }

  isUserTeacher(): boolean {
    var result = false;
    if (this._localUser) {
      result = this._localUser.rol == "docent";
    } else {
      console.warn('Local user is null! Is this intended?');
    }

    return result;
  }

  // Clear de cache wanneer de gebruiker uitlogt
  handleLogOut() {
    this._localUser = new User();
    this._idUserMapping = new Map();
    this.localUserFullName.next("");
    this.localUserName.next("");
    this.localUserRole.next("");
    this.localStudentNumber.next(-1);
  }

  /* Zoek via de backend een gebruiker op op basis van de userId gekoppeld aan een annotatie
   * Enkel als de gegeven userId nog niet gecached geweest is of het gegachte element bestaat maar de User is null
   * Dan pas wordt een http request gedaan naar de backend */
  cacheUserId(userId: string) {
    console.log('Caching: ' + userId);
    if (!this._idUserMapping.has(userId) || this._idUserMapping.get(userId) == null) {
      this.http.get<User>(apiUrl + '/gubui/' + userId, httpOptions).subscribe(res => {
        var user = res;
        console.log('Received valid local user from backend: ' + user.username + '  name: '+ user.firstName  + '   id: ' + user.studentNumber + ' role: ' + user.rol + '  Caching...');
        this._idUserMapping.set(userId, user);
      }, err => {
        this.handleError(err);
      });
    }
  }

  // Geef een geldige naam terug van een gebruiker wanneer deze al eens is opgezocht en bestaat in de cache
  getFullnameById(userId: string): string {
    var name = "";
    if (this._idUserMapping.has(userId)) {
      var user = this._idUserMapping.get(userId);
      if (user) {
        name = user.firstName + ' ' + user.lastName;
      }
    }
    return name;
  }

  // Geeft de achternaam van een gebruiker terug op basis van de db id
  getLastNameById(userId: string) : string {
    var lastName = "";
    if (this._idUserMapping.has(userId)) {
      var user = this._idUserMapping.get(userId);
      if (user) {
        lastName = user.lastName;
      }
    }
    return lastName;
  }

  // Geeft de voornaam van een gebruiker terug op basis van de db id
  getFirstNameById(userId: string) : string {
    var firstName = "";
    if (this._idUserMapping.has(userId)) {
      var user = this._idUserMapping.get(userId);
      if (user) {
        firstName = user.firstName;
      }
    }
    return firstName;
  }

  /* Geef het studentennummer terug op basis van de userId
   * Fungeert op dezelfde manier als de functie hierboven */
  getStudentNumberById(userId: string) : number {
    var studentNumber = -1;
    if (this._idUserMapping.has(userId)) {
      var user = this._idUserMapping.get(userId);
      if (user != null) {
        studentNumber = user.studentNumber;
      }
    }
    return studentNumber;
  }

  /* Geef de username van de student terug op basis van de userId */
  getStudentUserNameById(userId: string) : string {
    var userName = "";
    if (this._idUserMapping.has(userId)) {
      var user = this._idUserMapping.get(userId);
      if (user != null) {
        userName = user.username;
      }
    }
    return userName;
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
