#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

const char* program_name;
const int BUF_SIZE = 8;

void copy(const char* from, const char* to);
int main(int argc, char* argv[]){
  if(argc != 3){
    printf("Expected 2 arguments: were %d\n", argc - 1);
    exit(1);
  }
  program_name = argv[0];

  const char* from = argv[1];
  const char* to = argv[2];

  struct stat buffer;
  if(stat(from, &buffer) < 0){
    perror(argv[0]);
    exit(1);
  }

  if(!S_ISREG(buffer.st_mode)){
    printf("%s is not a file\n", from);
    exit(1);
  }

  stat(to, &buffer);

  if(S_ISDIR(buffer.st_mode)){
    printf("%s is a directory\n", to);
    exit(1);
  }

  printf("Printing %s to %s\n", from, to);
  copy(from, to);
  return 0;
}

void copy(const char* from, const char* to){
  int readFileDescriptor = open(from, O_RDONLY);
  int writeFileDescriptor = open(to, O_WRONLY | O_CREAT, S_IRWXU);

  if(readFileDescriptor < 0 || writeFileDescriptor < 0){
    perror(program_name);
    exit(1);
  }

  char* buffer = malloc(sizeof(char) * 8);
  while(read(readFileDescriptor, buffer, BUF_SIZE) > 0){
    write(writeFileDescriptor, buffer, BUF_SIZE);
  }
  free(buffer);

  int closeResult = close(readFileDescriptor);

  if(closeResult < 0){
    perror(program_name);
    exit(1);
  }

  closeResult = close(writeFileDescriptor);
  if(closeResult < 0){
    perror(program_name);
    exit(1);
  }
}
