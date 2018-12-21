import { Injectable } from '@angular/core';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { Router } from '@angular/router';
import { BehaviorSubject } from 'rxjs/BehaviorSubject';

//const baseurl = "http://localhost:9016/api/user";//local
const baseurl = "http://backend.annotatietool-01.project.tiwi.be/api/user";//docker
const httpOptions ={
  headers:new HttpHeaders({'Content-Type':'application/json'})
};

@Injectable()
export class AuthService {

  constructor(private http:HttpClient,private router:Router) { }

  loginUser(user){
    return this.http.post(baseurl + '/login',user);
    
  }

  loggedIn(){
    return !!localStorage.getItem('token') // getItem haalt een waarde (non bool) op, we converteren naar bool door !! te doen
  }

  

  getToken(){
    return localStorage.getItem('token');
  }

  logout(){
    localStorage.removeItem('token');
    this.router.navigate(['/login']);
  }
}
