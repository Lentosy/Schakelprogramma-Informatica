import {Component, OnInit} from '@angular/core';
import {HttpClient, HttpHeaders} from '@angular/common/http';
import {Router} from "@angular/router";
import {Observable} from 'rxjs/Observable';
import {tap, catchError} from 'rxjs/operators';
import {of} from 'rxjs/observable/of';
import {AuthService} from '../../services/authservice/auth.service';
import {UserService} from '../../services/userservice/user.service';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {

  name: string;
  isDocent: boolean;

  constructor(private http: HttpClient,
              private authService: AuthService,
              private userService: UserService,
              private router: Router) {
  }

  ngOnInit() {
    let token = localStorage.getItem('token');
    if (token != null) {
      this.userService.requestLocalUser();
      this.userService.localUserFullName.subscribe((value: string) => {
          this.name = value;
        },
        (err) => console.error(err),
        () => console.log("wanneer komt dit hier?"));

      this.userService.localUserRole.subscribe((value: string) => {
        if (value === "docent") {
          this.isDocent = true;
        } else {
          this.isDocent = false;
        }
      });

    }
  }

  loggedIn() {
    return this.authService.loggedIn();
  }

  logout() {
    this.userService.handleLogOut();
    this.authService.logout();
  }

}
