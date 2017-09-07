#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Expected one argument, but was %d", argc - 1);
    exit(1);
  }

  printf("The parameter is: %s\n", argv[1]);
  sleep(5);

  exit(1);
}
