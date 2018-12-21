"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var assignment_1 = require("../../models/assignment");
var AssignmentSettingsComponent = /** @class */ (function () {
    function AssignmentSettingsComponent(router, _assignmentService, _groupsService, route) {
        this.router = router;
        this._assignmentService = _assignmentService;
        this._groupsService = _groupsService;
        this.route = route;
        this.model = new assignment_1.Assignment("", "", null, false, false, Date.now().toString(), Date.now().toString());
        this.groups = [];
        this.error = null;
        this.assignmentId = null;
        this.isNewAssignment = false;
        this.maxCountInputs = 7;
        this.QuickOptionsDataInDB = [];
        this.QuickOptionsDATA = [];
        this.QuickOptionsSHOW = [];
        this.QuickOptionsTOADD = [];
    }
    AssignmentSettingsComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.route.params.subscribe(function (params) {
            if (params['id'] == 'new') {
                _this.isNewAssignment = true;
            }
            else {
                _this.getAssignment(params['id']);
            }
        });
        this.getGroups();
    };
    AssignmentSettingsComponent.prototype.addOrChangeAssignment = function () {
        var _this = this;
        this.OnSubmitUpdateQuickOptions();
        console.log(this.groups);
        this.model.groups = this.groups;
        this._assignmentService.postOrPutAssignment(this.model).
            subscribe(function (data) { return _this.model = data; }, function (error) { return console.log(error.body); }, function () {
            _this.ngOnInit();
            _this.router.navigate(['/assignment']);
        });
    };
    AssignmentSettingsComponent.prototype.eventEnableQuickComment = function () {
        var quickBtn = document.getElementById("quick");
        this.QuickCommentsEnabled = quickBtn.checked;
        this.showOptionsForQuickComment(this.QuickCommentsEnabled);
    };
    AssignmentSettingsComponent.prototype.showOptionsForQuickComment = function (show) {
        if (show) {
            this.QuickOptionsSHOW = this.QuickOptionsDATA;
            //SHOW
        }
        else {
            this.QuickOptionsDATA = this.QuickOptionsSHOW;
            this.QuickOptionsSHOW = [];
            //DISABLE / HIDE
        }
    };
    AssignmentSettingsComponent.prototype.onStartSetQuickComment = function () {
        //Get from database-> enabled + data
        //QuickCommentsEnabled
        //console.log("ENABLED"+this.model.quickCommentEnabled);
        //console.log("MDOEL"+this.model.quickComments);
        //console.log("MDOEL"+this.model.description);
        //console.log("MDOEL"+this.model.name);
        this.QuickOptionsDataInDB = this.model.quickComments; //["quickOne","quickTwo","quickThr",""];
        for (var j = 0; j < this.QuickOptionsDataInDB.length; j++) {
            this.QuickOptionsDATA.push(this.QuickOptionsDataInDB[j]);
        }
        this.QuickCommentsEnabled = this.model.quickCommentEnabled; //true;
        //fill until max
        for (var i = this.QuickOptionsDATA.length; i < this.maxCountInputs; i++) {
            this.QuickOptionsDATA.push("");
        }
        this.QuickOptionsSHOW = this.QuickOptionsDATA;
        //set slider
        var quickBtn = document.getElementById("quick");
        quickBtn.checked = this.QuickCommentsEnabled;
        this.showOptionsForQuickComment(this.QuickCommentsEnabled);
        //this.QuickOptions
        //add
        //this.showOptionsForQuickComment() //SHOW OR HIDE
    };
    AssignmentSettingsComponent.prototype.trackByIndex = function (index, obj) {
        return index;
    };
    AssignmentSettingsComponent.prototype.OnSubmitUpdateQuickOptions = function () {
        if (this.QuickCommentsEnabled) {
            this.model.quickComments = this.QuickOptionsSHOW;
        }
        else {
            this.model.quickComments = this.QuickOptionsDATA;
        }
        this.model.quickCommentEnabled = this.QuickCommentsEnabled;
        //return;
        /*for(var i=0;i<7;i++)
        {
          var itemToCheck;
          if(this.QuickCommentsEnabled)
          {
            itemToCheck=this.QuickOptionsSHOW[i];
          }
          else{
            itemToCheck=this.QuickOptionsDATA[i];
          }
    
          var found=false;
          for(var j=0;j<this.QuickOptionsDataInDB.length;j++)
          {
            if(itemToCheck==this.QuickOptionsDataInDB[j])
            {
              this.QuickOptionsDataInDB[j]="";
              found=true;
              break;
            }
          }
    
          if(!found)
          {
            this.QuickOptionsTOADD.push(itemToCheck);
          }
        }
    
    
        for(var i=0;i<this.QuickOptionsDataInDB.length;i++)
        {
          if(this.QuickOptionsDataInDB[i]!="")
          {
            console.log("Remove "+this.QuickOptionsDataInDB[i]);
            //VERWIJDEREN Uit DB
          }
        }
    
    
        for(var i=0;i<this.QuickOptionsTOADD.length;i++)
        {
          if(this.QuickOptionsTOADD[i]!="")
          {
            console.log("Add "+this.QuickOptionsTOADD[i]);
            //TOEVOEGEN AAN DB
          }
        }*/
    };
    AssignmentSettingsComponent.prototype.getGroups = function () {
        var _this = this;
        this._groupsService.getGroups()
            .subscribe(function (data) {
            //elk group object worden volgende fields toegevoegd:
            // de vorige staat (previousActive)
            // de nieuwe staat (gebind aan de checkboxes)
            // op de server kan dan gekeken worden waar de (previousActive != currentActive)
            var groupList = [];
            for (var _i = 0, data_1 = data; _i < data_1.length; _i++) {
                var groupInput = data_1[_i];
                groupInput["previousActive"] = false;
                groupInput["currentActive"] = false;
                for (var _a = 0, _b = groupInput.assignments; _a < _b.length; _a++) {
                    var assignmentId = _b[_a];
                    if (_this.assignmentId == assignmentId) {
                        groupInput["previousActive"] = true;
                        groupInput["currentActive"] = true;
                    }
                }
                console.log(groupInput);
            }
            _this.groups = data;
        }, function (error) { return _this.error = error; });
    };
    AssignmentSettingsComponent.prototype.setGroups = function () {
        //group objecten uitbreiden met een hasAssignemnt field
    };
    AssignmentSettingsComponent.prototype.getAssignment = function (id) {
        var _this = this;
        this.assignmentId = id;
        this._assignmentService.getAssignment(id).subscribe(function (data) {
            _this.model = data;
            _this.onStartSetQuickComment();
        }, function (error) {
            console.log(error);
        });
    };
    AssignmentSettingsComponent.prototype.addDropdownElement = function () {
        this.model.dropdown[this.model.dropdown.length] = this.dropdownElement;
        this.dropdownElement = "";
    };
    AssignmentSettingsComponent.prototype.removeDropdownElement = function (element) {
        console.log("removeElement");
        var index = this.model.dropdown.indexOf(element);
        if (index !== -1) {
            this.model.dropdown.splice(index, 1);
        }
    };
    __decorate([
        core_1.Input()
    ], AssignmentSettingsComponent.prototype, "model", void 0);
    AssignmentSettingsComponent = __decorate([
        core_1.Component({
            selector: 'app-assignment-settings',
            templateUrl: './assignment-settings.component.html',
            styleUrls: ['./assignment-settings.component.scss']
        })
    ], AssignmentSettingsComponent);
    return AssignmentSettingsComponent;
}());
exports.AssignmentSettingsComponent = AssignmentSettingsComponent;
