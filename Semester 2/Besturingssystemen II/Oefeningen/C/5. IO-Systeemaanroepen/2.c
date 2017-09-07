
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <time.h>

int main(int argc, char *argv[]){
	const char *pathname = "10MBfile";

	int fileDescriptor = open(pathname, O_RDONLY);
	if(fileDescriptor < 0){
		perror(argv[0]);
		exit(1);
	}

	int i = 1;
	for(i; i <= 8192; i += i){
		double start = clock();

		char *buffer = malloc(sizeof(char) * i);

		while(read(fileDescriptor, buffer, i) != 0){}

		free(buffer);
		double time= (clock() - start) / CLOCKS_PER_SEC;
		printf("BUF_SIZE = %4d ; TIME = %0.2f\n",i, time);
	}
	int closeResult = close(fileDescriptor);
	if(closeResult < 0){
		perror(argv[0]);
		exit(1);
	}
	return 0;
}
