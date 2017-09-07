#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>

typedef struct Process{
  pid_t pid;
  int number;
} P;

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Expected one argument, but were %d\n", argc - 1);
    exit(1);
  }

  int amount_of_processes = atoi(argv[1]);
  P *processes = malloc(sizeof(P) * amount_of_processes);

  pid_t pid;
  int i;
  for(i = 0; i < amount_of_processes; i++){
    if((pid=fork()) < 0){
      perror(argv[0]);
      exit(1);
    }

    if(pid == 0){
      srand(getpid());
      processes[i].pid = getpid();
      processes[i].number = rand();
      printf("DEBUG: Process %d has number %d\n", processes[i].pid, processes[i].number);
      exit(0);
    }
  }


  return 0;
}
