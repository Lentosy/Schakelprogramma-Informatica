
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

	const char *pathname = "10MBfile";
	int fileDescriptor = open(pathname, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if(fileDescriptor < 0){
		perror(argv[0]);
		exit(1);
	}

	int i = 0;
	for(i; i < 10 * 1024 * 1024; i++){
		char letter = rand() % 26 + 'a';
		int writeResult = write(fileDescriptor, &letter, 1);
		if(writeResult < 0){
			perror(argv[0]);
			exit(1);
		}
	}

	int closeResult = close(fileDescriptor);
	if(closeResult < 0){
		perror(argv[0]);
		exit(1);
	}
	return 0;
}
