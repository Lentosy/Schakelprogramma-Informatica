import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AssignmentStudentViewComponent } from './assignment-student-view.component';

describe('AssignmentStudentViewComponent', () => {
  let component: AssignmentStudentViewComponent;
  let fixture: ComponentFixture<AssignmentStudentViewComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AssignmentStudentViewComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AssignmentStudentViewComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
