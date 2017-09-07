#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(int argc, char* argv[]){
  pid_t pid;
  int process_count = 3;
  int i;
  for(i = 0; i < process_count; i++){
    if((pid = fork()) == 0){
      printf("Child pid of process %d: %d\n", i + 1, getpid());
      exit(1);
    }
  }

  return 0;

}
