import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { GroupStudentViewComponent } from './group-student-view.component';

describe('GroupStudentViewComponent', () => {
  let component: GroupStudentViewComponent;
  let fixture: ComponentFixture<GroupStudentViewComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ GroupStudentViewComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(GroupStudentViewComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
