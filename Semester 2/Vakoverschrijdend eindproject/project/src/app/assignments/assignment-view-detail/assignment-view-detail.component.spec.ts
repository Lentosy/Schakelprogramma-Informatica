import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AssignmentViewDetailComponent } from './assignment-view-detail.component';

describe('AssignmentViewDetailComponent', () => {
  let component: AssignmentViewDetailComponent;
  let fixture: ComponentFixture<AssignmentViewDetailComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AssignmentViewDetailComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AssignmentViewDetailComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
