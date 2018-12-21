import { Injectable } from '@angular/core';
import { Observable } from 'rxjs/Observable';
import { catchError, retry } from "rxjs/operators";
import { ErrorObservable } from 'rxjs/observable/ErrorObservable';
import { saveAs } from 'file-saver';
import { UserService } from '../userservice/user.service';
import { Video } from '../../models/video';

@Injectable()
export class ExportFileService {
  
    constructor(private _userService : UserService) { }

    /* Exporteer de annotaties van een video naar een .csv bestand
     * Maakt gebruik van de caching van de UserService, deze cache is
     * volledig opgevuld met de nodige informatie van de annotaties
     * waardoor er geen missende elementen zullen optreden */
    exportAnnotationsAsCSV(video : Video) {
        if (video != null) {
            var csv = [["StudentLastName", "StudentFirstName", "StudentUserName", "StudentId", "BeginTime", "EndTime", "Description"]];
            video.annotations.forEach(annotation => {
                    csv.push([
                    this._userService.getLastNameById(annotation.userId),
                    this._userService.getFirstNameById(annotation.userId),
                    this._userService.getStudentUserNameById(annotation.userId),
                    String(this._userService.getStudentNumberById(annotation.userId)),
                    String(annotation.beginTime),
                    String(annotation.endTime),
                    annotation.description.replace(/,/g, '/')]); // Noodzakelijk? Gebruiker kan tekst 
                                                                 // invoeren met komma's wat fuckt met
                                                                 // de correcte werking van het csv bestand
            });
            var joined_csv = csv.join('\n');
            var blob = new Blob([joined_csv], {type: 'text/csv'});
            saveAs(blob, video.name + "_annotations.csv");
            
            console.log("Saved .csv file of video to " + video.name + '.csv!');
        } else {
            console.log("Could not save .csv file of input video because it is null");
        }
    }
}
