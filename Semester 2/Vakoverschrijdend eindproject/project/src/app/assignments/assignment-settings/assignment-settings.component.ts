import {Component, Input, OnInit} from "@angular/core";
import {Assignment} from "../../models/assignment";
import {AssignmentsService} from "../../services/assignmentservice/assignments.service";
import {Router, ActivatedRoute} from "@angular/router";
import {Group} from "../../models/group";
import {GroupsService} from "../../services/groupservice/groups.service";


@Component({
  selector: 'app-assignment-settings',
  templateUrl: './assignment-settings.component.html',
  styleUrls: ['./assignment-settings.component.scss']
})


export class AssignmentSettingsComponent implements OnInit {
  @Input()
  model: Assignment = new Assignment("", "", false, false, Date.now().toString(),Date.now().toString());
  groups: Group[] = [];
  error: string = null;
  assignmentId: string = null;
  isNewAssignment: boolean = false;

  //comments
  dropdownElement: string;
  quickCommentElement: string;
  rubricThemeElement: string;

  constructor(private router: Router, private _assignmentService: AssignmentsService,
              private _groupsService: GroupsService, private route: ActivatedRoute,) {
  }

  ngOnInit(): void {
    this.route.params.subscribe( params => {
      if(params['id'] == 'new'){
        this.isNewAssignment = true;
      }
      else{
        this.getAssignment(params['id']);
      }
    } );
    this.getGroups();
  }

  addOrChangeAssignment() {
    //this.OnSubmitUpdateQuickOptions();
    console.log("assignment:");
    console.log(this.model);

    console.log(this.groups);
    this.model.groups = this.groups;
    this._assignmentService.postOrPutAssignment(this.model).
    subscribe(data => this.model = data,
      error => console.log(error.body),
      () => {
        this.ngOnInit();
        this.router.navigate(['/assignment']);
      });
    }

  getGroups() {
    this._groupsService.getGroups()
      .subscribe(data => {
        //elk group object worden volgende fields toegevoegd:
          // de vorige staat (previousActive)
          // de nieuwe staat (gebind aan de checkboxes)
          // op de server kan dan gekeken worden waar de (previousActive != currentActive)
          var groupList = [];
          for (let groupInput of data) {
            groupInput["previousActive"] = false;
            groupInput["currentActive"] = false;

            for(let assignmentId of groupInput.assignments){
              if(this.assignmentId == assignmentId) {
                groupInput["previousActive"] = true;
                groupInput["currentActive"] = true;
              }
            }
            console.log(groupInput);
          }

          this.groups = data;
      },
        error => this.error = error);
  }
  setGroups(){
    //group objecten uitbreiden met een hasAssignemnt field

  }

  getAssignment(id){
    this.assignmentId = id;
    this._assignmentService.getAssignment(id).subscribe(data => {
      this.model = data;
      //this.onStartSetQuickComment();
    }, error => {
      console.log(error);
    });
  }

  addDropdownElement(){
    this.model.dropdown[this.model.dropdown.length] = this.dropdownElement;
    this.dropdownElement = "";
  }

  removeDropdownElement(element){
    const index: number = this.model.dropdown.indexOf(element);
    if (index !== -1) {
      this.model.dropdown.splice(index, 1);
    }
  }

  addRubricElement(){
    let rubic = {
      theme: this.rubricThemeElement,
      score: "",
      description: ""
    };
    this.model.rubric[this.model.rubric.length]= rubic;
    this.rubricThemeElement = "";
  }

  removeRubricElement(element){
    const index: number = this.model.rubric.indexOf(element);
    if (index !== -1) {
      this.model.rubric.splice(index, 1);
    }
  }

  addQuickCommentElement(){
    this.model.quickComments[this.model.quickComments.length] = this.quickCommentElement;
    this.quickCommentElement = "";
  }

  removeQuickCommentElement(element){
    const index: number = this.model.quickComments.indexOf(element);
    if (index !== -1) {
      this.model.quickComments.splice(index, 1);
    }
  }
}
