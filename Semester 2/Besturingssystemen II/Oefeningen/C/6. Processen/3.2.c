#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>

int main(int argc, char* argv[]){
  int process_count = 3;
  int processes[process_count];
  const char *filename = "./writestring";

  pid_t pid;
  int i;
  for(i = 0; i < process_count; i++){
    if((pid = fork()) == 0){
      processes[i] = pid;
      execl(filename, filename, "Hello", (char *)0);
      exit(1);
    }
  }

  for(i = 0; i < process_count; i++){
    waitid(P_ALL, pid, NULL, WEXITED);
  }

  return 0;
}
