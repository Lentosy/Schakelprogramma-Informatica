import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-group-edit',
  templateUrl: './group-edit.component.html',
  styleUrls: ['./group-edit.component.css']
})
export class GroupEditComponent implements OnInit {

  constructor() {
  }

  //TODO: omzetten angular5
  /*  <script>
  angular.module("editGroupApp", [])
      .controller("EditGroupController", function ($scope) {
        $scope.isLoading = true;
        $scope.students = [];
        $scope.groups = [];


        function getData() {
          //ajax call naar server

          $.getJSON( "/api/groups/getEditData/2", function( data ) {

            $.each( data.students, function( key, val ) {
              addStudent(val);
            });
            $.each( data.groups, function( key, val ) {
              addGroup(val);
            });
            $scope.$apply(function () {
              $scope.isLoading = false;
            })


          });
        }

        function addStudent(val) {
          //todo data omvormen
          $scope.students.push( val);
        }


        socket.on('addStudent', function (student) {
          addStudent(student)
        })

        function addGroup(val) {
          //todo data omvormen
          $scope.groups.push(val)
        }

        getData();
      });

  $(function () {
    $('[data-toggle="tooltip"]').tooltip()
  })
  </script>*/

  ngOnInit() {
  }

}
