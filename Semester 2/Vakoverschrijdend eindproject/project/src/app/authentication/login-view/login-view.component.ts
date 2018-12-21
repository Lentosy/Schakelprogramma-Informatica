import { Component, OnInit } from '@angular/core';
import { User } from '../../models/user';
import {HttpClient, HttpErrorResponse, HttpHeaders} from "@angular/common/http";
import { Router } from "@angular/router";
import { AuthService } from '../../services/authservice/auth.service';
import { UserService } from '../../services/userservice/user.service';
import { HeaderComponent } from '../../shared/header/header.component';

//const baseurl = "http://localhost:3000/api/user";//local
const baseurl = "http://backend.annotatietool-01.project.tiwi.be/api/user";//docker
const httpOptions ={
  headers:new HttpHeaders({'Content-Type':'application/json'})
};

@Component({
  selector: 'app-login-view',
  templateUrl: './login-view.component.html',
  styleUrls: ['./login-view.component.css']
})
export class LoginViewComponent implements OnInit {

  loginData = {username:'',password:''};
  data :any;
  message = '';

  constructor(private http:HttpClient,private router:Router,private authService: AuthService, private _userService: UserService) {}

  ngOnInit() {
    localStorage.setItem('userName', null);
    localStorage.setItem('name', null);
  }

  login(){
    console.log("logging in!");
    var self = this;
    this.authService.loginUser(this.loginData).subscribe(res => {
      this.data = res;
    }, err => {
      this.message = err.error.msg;
    },()=> {
      localStorage.setItem('userName', this.loginData.username);
      localStorage.setItem('token', this.data.token);
      self._userService.requestLocalUser();
      this.router.navigate(['']);
    })
  }
}
