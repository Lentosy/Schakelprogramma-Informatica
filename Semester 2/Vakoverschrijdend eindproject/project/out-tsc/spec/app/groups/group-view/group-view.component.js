"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
var core_1 = require("@angular/core");
var GroupViewComponent = /** @class */ (function () {
    function GroupViewComponent() {
    }
    //TODO: omzetten naar angular5
    /*
    <!--voor de tooltip heb je volgende code nodig:-->
  
  <script>
    $(function () {
      $('[data-toggle="tooltip"]').tooltip()
    })
  
    <% if (typeof formContent !== 'undefined') { %>
      // your code here
      $(window).on('load',function(){
        $('#myModal').modal('show');
      });
  
    <% } %>
    </script>*/
    GroupViewComponent.prototype.ngOnInit = function () {
    };
    GroupViewComponent = __decorate([
        core_1.Component({
            selector: 'app-group-view',
            templateUrl: './group-student-view.component.html',
            styleUrls: ['./group-student-view.component.css']
        }),
        __metadata("design:paramtypes", [])
    ], GroupViewComponent);
    return GroupViewComponent;
}());
exports.GroupViewComponent = GroupViewComponent;
//# sourceMappingURL=group-view.component.js.map
