import {BrowserModule} from '@angular/platform-browser';
import {FormsModule} from '@angular/forms';
import {NgModule, NO_ERRORS_SCHEMA} from '@angular/core';
import {MDBBootstrapModule} from 'angular-bootstrap-md';
import {NgbModule} from '@ng-bootstrap/ng-bootstrap';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {NoopAnimationsModule} from '@angular/platform-browser/animations';
import {MatButtonModule, MatCheckboxModule} from '@angular/material';
import { HttpClientModule,HttpInterceptor, HTTP_INTERCEPTORS } from "@angular/common/http";
import {AppComponent} from './app.component';
import {HeaderComponent} from './shared/header/header.component';
import {GroupEditComponent} from './groups/group-edit/group-edit.component';
import {GroupViewComponent} from './groups/group-view/group-view.component';
import {GroupDetailViewComponent} from './groups/group-detail-view/group-detail-view.component';
import {DashboardViewComponent} from './dashboard/dashboard-view/dashboard-view.component';
import {LoginViewComponent} from './authentication/login-view/login-view.component';
import {VideoUploadComponent} from './video/video-upload/video-upload.component';
import {VideoShowComponent} from './video/video-show/video-show.component';
import {RouterModule, Routes} from '@angular/router';
import {PageNotFoundComponent} from './shared/page-not-found/page-not-found.component';
import {AssignmentViewComponent} from './assignments/assignment-view/assignment-view.component';
import {AssignmentsService} from "./services/assignmentservice/assignments.service";
import {GroupsService} from "./services/groupservice/groups.service";
import {VideoService} from './services/videoservice/video.service';
import {NgxCarouselModule} from 'ngx-carousel';
import {AnnotationService} from './services/annotationservice/annotation.service';
import {AssignmentViewDetailComponent} from './assignments/assignment-view-detail/assignment-view-detail.component';
import {FilterPipe} from './pipes/filter.pipe';
import {NameService} from "./services/nameservice/name.service";
import {AssignmentSettingsComponent} from './assignments/assignment-settings/assignment-settings.component'
import {CommonModule} from "@angular/common";
import { GroupStudentViewComponent } from './groups/group-student-view/group-student-view.component';
import { GroupStudentDetailViewComponent } from './groups/group-student-detail-view/group-student-detail-view.component';
import { AssignmentStudentViewComponent } from './assignments/assignment-student-view/assignment-student-view.component';
import { AssignmentStudentViewDetailComponent } from './assignments/assignment-student-view-detail/assignment-student-view-detail.component'
import { AuthService } from './services/authservice/auth.service';
import { AuthGuard } from './authentication/auth.guard';
import { TokenInterceptorService } from './services/authservice/token-interceptor.service';
import { UserService } from './services/userservice/user.service';
import { ExportFileService } from './services/exportfileservice/exportfile.service';

// videogular
import {VgCoreModule} from 'videogular2/core';
import {VgControlsModule} from 'videogular2/controls';
import {VgOverlayPlayModule} from 'videogular2/overlay-play';
import {VgBufferingModule} from 'videogular2/buffering';
import {MediaPlayerComponent} from './shared/media-player/media-player.component';
import { AssignmentStudentViewDetailDetailComponent } from './assignments/assignment-student-view-detail-detail/assignment-student-view-detail-detail.component';

const appRoutes: Routes = [
  { path: '', component: DashboardViewComponent,canActivate: [AuthGuard] },
  { path: 'video/upload', component: VideoUploadComponent,canActivate: [AuthGuard] },
  { path: 'video/:id', component: VideoShowComponent,canActivate: [AuthGuard] },
  { path: 'class', component: GroupViewComponent,canActivate: [AuthGuard] },
  { path: 'class/student', component: GroupStudentViewComponent,canActivate: [AuthGuard] },
  { path: 'class/:id', component: GroupDetailViewComponent,canActivate: [AuthGuard] },
  { path: 'class/student/:id', component: GroupStudentDetailViewComponent,canActivate: [AuthGuard] },
  { path: 'assignment', component: AssignmentViewComponent,canActivate: [AuthGuard] },
  { path: 'assignment/student', component: AssignmentStudentViewComponent,canActivate: [AuthGuard] },
  { path: 'assignment/student/:id', component: AssignmentStudentViewDetailDetailComponent,canActivate: [AuthGuard] },
  { path: 'assignment/settings/:id', component: AssignmentSettingsComponent,canActivate: [AuthGuard] },
  { path: 'login',component: LoginViewComponent},
  { path: '**', component: PageNotFoundComponent }];

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    GroupEditComponent,
    GroupViewComponent,
    GroupDetailViewComponent,
    DashboardViewComponent,
    LoginViewComponent,
    VideoUploadComponent,
    VideoShowComponent,
    PageNotFoundComponent,
    AssignmentViewComponent,
    AssignmentViewDetailComponent,
    FilterPipe,
    AssignmentSettingsComponent,
    MediaPlayerComponent,
    GroupStudentViewComponent,
    GroupStudentDetailViewComponent,
    AssignmentStudentViewComponent,
    AssignmentStudentViewDetailComponent,
    AssignmentStudentViewDetailDetailComponent
  ],
  imports: [
    BrowserModule,
    CommonModule,
    FormsModule,
    VgCoreModule,
    VgControlsModule,
    VgOverlayPlayModule,
    VgBufferingModule,
    HttpClientModule,
    MDBBootstrapModule.forRoot(),
    NgxCarouselModule,
    BrowserAnimationsModule,
    NoopAnimationsModule,
    NgbModule.forRoot(),
    MatButtonModule,
    MatCheckboxModule,
    RouterModule.forRoot(
      appRoutes,
      //{ enableTracing: true } // <-- debugging purposes only
    )
  ],
  schemas: [ NO_ERRORS_SCHEMA ],
  providers: [GroupsService, AssignmentsService,VideoService,AnnotationService,AuthService,AuthGuard,UserService,ExportFileService,{
    provide: HTTP_INTERCEPTORS,
    useClass: TokenInterceptorService,
    multi: true
  }],
  bootstrap: [AppComponent]
})

export class AppModule {
}
