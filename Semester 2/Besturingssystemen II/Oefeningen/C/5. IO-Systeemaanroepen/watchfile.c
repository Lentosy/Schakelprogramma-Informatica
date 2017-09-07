#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

struct file_info{
  char* path;
  time_t last_modified;
  off_t size;
};

void loop(struct file_info filestats);

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Expected one argument: were %d.\n", argc - 1);
    exit(1);
  }

  struct file_info filestats;
  filestats.path = argv[1];
  struct stat buffer;

  if(stat(filestats.path, &buffer) == -1){
    perror(argv[0]);
    exit(1);
  }
  if(!S_ISREG(buffer.st_mode)){
    printf("%s is not a file.\n", filestats.path);
    exit(1);
  }

  filestats.last_modified = buffer.st_mtime;
  filestats.size = buffer.st_size;
  printf("Last known modification(%jd bytes): %s", filestats.size, ctime(&filestats.last_modified));

  loop(filestats);
  return 0;
}

void loop(struct file_info filestats){
  struct stat buffer;
  for(;;){
    if(stat(filestats.path, &buffer) == -1){
      perror("Error access file data");
      exit(1);
    }
    if(difftime(filestats.last_modified, buffer.st_mtime) < 0){
      filestats.last_modified = buffer.st_mtime;
      filestats.size = buffer.st_size;
      printf("Modified(%jd bytes) on %s", filestats.size, ctime(&filestats.last_modified));
    }
    sleep(1);
  }
}
