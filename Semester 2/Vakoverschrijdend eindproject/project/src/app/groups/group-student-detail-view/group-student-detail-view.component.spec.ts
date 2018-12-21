import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { GroupStudentDetailViewComponent } from './group-student-detail-view.component';

describe('GroupStudentDetailViewComponent', () => {
  let component: GroupStudentDetailViewComponent;
  let fixture: ComponentFixture<GroupStudentDetailViewComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ GroupStudentDetailViewComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(GroupStudentDetailViewComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
