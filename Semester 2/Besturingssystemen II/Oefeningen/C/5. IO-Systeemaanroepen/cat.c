#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

#define BUF_SIZE 8

int main(int argc, char *argv[]){

	if(argc < 2){
		printf("Expected at least one argument: were %d\n", argc - 1);
		exit(1);
	}

	int i;
	for(i = 1; i < argc; i++){
		char *pathname = argv[i];
		int fileDescriptor = open(pathname, O_RDONLY);
		if(fileDescriptor < 0){
			perror(argv[0]);
			exit(1);
		}

		char buffer[BUF_SIZE];
		int bytes;
		while((bytes = read(fileDescriptor, buffer, BUF_SIZE)) > 0){
			write(1, buffer, bytes);
		}

		int closeResult = close(fileDescriptor);
		if(closeResult < 0){
			perror(argv[0]);
			exit(1);
		}
	}

	return 0;
}
