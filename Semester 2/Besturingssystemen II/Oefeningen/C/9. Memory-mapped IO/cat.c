#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file(int filedescriptor);

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Expected at least one argument, was %d\n", argc - 1);
    exit(1);
  }

  int filedescriptor;
  struct stat buffer;
  int i;
  for(i = 1; i < argc; i++){
    if(stat(argv[i], &buffer) < 0){
      printf("\n\n");
      perror(argv[i]);
    } else if (S_ISREG(buffer.st_mode)){
      filedescriptor = open(argv[i], O_RDONLY);
      if(filedescriptor < 0){
        printf("\n\n");
        perror(argv[0]);
      }else{
        printf("\n\n\n-----Printing %s-----\n", argv[i]);
        print_file(filedescriptor);
      }
    } else {
      printf("\n\n%s: This is a directory\n", argv[i]);
    }
  }
  return 0;
}

void print_file(int filedescriptor){
  long length = sysconf(_SC_PAGESIZE);
  char *addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, filedescriptor, 0);
  printf("%s", addr);
  if(close(filedescriptor) < 0){
    perror("Error closing file: ");
  }
  munmap(addr, length);
}
