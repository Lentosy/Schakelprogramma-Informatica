#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>

int main(int argc, char* argv[]){
  int process_count = 3;
  int processes[process_count];
  const char *filename = "./writestring";
  const char *args[] = {filename, "Hello", (char *)0};

  pid_t pid;
  int i;
  for(i = 0; i < process_count; i++){
    if((pid = fork()) == 0){
      processes[i] = pid;
      execve(filename, &args, NULL);
      exit(1);
    }
  }

  for(i = 0; i < process_count; i++){
    waitid(P_ALL, pid, NULL, WEXITED);
  }

  return 0;
}
