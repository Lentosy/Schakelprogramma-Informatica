import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AssignmentSettingsComponent } from './assignment-settings.component';

describe('AssignmentSettingsComponent', () => {
  let component: AssignmentSettingsComponent;
  let fixture: ComponentFixture<AssignmentSettingsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AssignmentSettingsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AssignmentSettingsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
