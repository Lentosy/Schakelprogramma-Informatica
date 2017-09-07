#include <stdlib.h>
#include <stdio.h>

const int SIZE = 10;

int* make();
void merge(int *a, int n);
void print(int *a);

int main(void){
  int *list = make();
  printf("\nUnsorted:\n");
  print(list);
  merge(list, SIZE);
  printf("\nSorted:\n");
  print(list);
}

int* make(){
  int *list = malloc(sizeof(int) * SIZE);
  int i;
  for(i = 0; i < SIZE; i++){
    list[i] = SIZE - i;
  }
  return list;
}

void merge(int *a, int n){

}

void print(int *a){
  int i;
  for(i = 0; i < SIZE; i++){
    printf("%4d", a[i]);
  }
  printf("\n");
}
