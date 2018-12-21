import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AssignmentStudentViewDetailDetailComponent } from './assignment-student-view-detail-detail.component';

describe('AssignmentStudentViewDetailDetailComponent', () => {
  let component: AssignmentStudentViewDetailDetailComponent;
  let fixture: ComponentFixture<AssignmentStudentViewDetailDetailComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AssignmentStudentViewDetailDetailComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AssignmentStudentViewDetailDetailComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
