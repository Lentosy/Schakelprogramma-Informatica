"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var http_1 = require("@angular/common/http");
require("rxjs/add/operator/map");
var operators_1 = require("rxjs/operators");
var ErrorObservable_1 = require("rxjs/observable/ErrorObservable");
var httpOptions = {
    headers: new http_1.HttpHeaders({ 'Content-Type': 'application/json' })
};
//const apiUrl = "http://localhost:3000/api/assignment/";//local
var apiUrl = "http://backend.annotatietool-01.project.tiwi.be/api/assignment/"; //docker
var AssignmentsService = /** @class */ (function () {
    function AssignmentsService(http) {
        this.http = http;
    }
    AssignmentsService.prototype.getAssignments = function () {
        return this.http.get(apiUrl, httpOptions)
            .pipe(operators_1.retry(3), operators_1.catchError(this.handleError));
    };
    AssignmentsService.prototype.getAssignment = function (id) {
        return this.http.get(apiUrl, httpOptions);
        /*return this.http.get(apiUrl)
          .map((res: Response) => res.json())
          .catch((err: any) => Observable.throw(err.json().error || 'Server error'));*/
    };
    AssignmentsService.prototype.putAssignment = function (assignment) {
        return this.http.put(apiUrl + assignment.id, assignment, httpOptions)
            .pipe(operators_1.catchError(this.handleError));
    };
    AssignmentsService.prototype.postAssignment = function (assignment) {
        return this.http.post(apiUrl, assignment, httpOptions)
            .pipe(operators_1.catchError(this.handleError));
    };
    AssignmentsService.prototype.deleteAssignment = function (id) {
        return this.http.delete(apiUrl + id, httpOptions)
            .pipe(operators_1.catchError(this.handleError));
    };
    AssignmentsService.prototype.handleError = function (error) {
        //TODO: tijdelijke oplossing refine error handling
        //TODO: in beste geval doorsturen naar de component en daar afhandelen.
        if (error.error instanceof ErrorEvent) {
            // A client-side or network error occurred. Handle it accordingly.
            console.error('An error occurred:', error.error.message);
        }
        else {
            // The backend returned an unsuccessful response code.
            // The response body may contain clues as to what went wrong,
            console.error("Backend returned code " + error.status + ", " +
                ("body was: " + error.error));
        }
        // return an ErrorObservable with a user-facing error message
        return new ErrorObservable_1.ErrorObservable('Something bad happened; please try again later.');
    };
    ;
    AssignmentsService = __decorate([
        core_1.Injectable()
    ], AssignmentsService);
    return AssignmentsService;
}());
exports.AssignmentsService = AssignmentsService;
