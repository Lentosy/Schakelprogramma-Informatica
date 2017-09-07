#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const int PROCESS_COUNT = 200;
const char *smemname = "/memory";

int main(void){
  int smem = shm_open(smemname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  pid_t processes[PROCESS_COUNT];
  pid_t pid;
  int i;
  for(i = 0; i < PROCESS_COUNT; i++){
    if((pid = fork()) == 0){
      long length = sysconf(_SC_PAGESIZE);
      char *buffer = mmap(NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, smem, 0);
      srand(getpid());
      int random = (int) rand();
      printf("i am child process %4d: %d\n", i, random);
      munmap(buffer, length);
      exit(0);
    }
  }



  for(i = 0; i < PROCESS_COUNT; i++){
    waitid(P_ALL, pid, NULL, WEXITED);
  }

  shm_unlink(smemname);

  return 0;
}
