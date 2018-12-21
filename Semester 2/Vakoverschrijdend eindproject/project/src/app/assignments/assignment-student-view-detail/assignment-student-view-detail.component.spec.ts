import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AssignmentStudentViewDetailComponent } from './assignment-student-view-detail.component';

describe('AssignmentStudentViewDetailComponent', () => {
  let component: AssignmentStudentViewDetailComponent;
  let fixture: ComponentFixture<AssignmentStudentViewDetailComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AssignmentStudentViewDetailComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AssignmentStudentViewDetailComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
