#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <time.h>

int main(int argc, char *argv[]){

	const char *pathname = "10MBtemp";

	int size = 10 * 1024 * 1024;
	char *buffer = malloc(sizeof(char) * size);
	int j = 0;
	for(j; j < size; j++){
		buffer[j] = rand() % 26 + 'a';
	}


	int fileDescriptor = open(pathname, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if(fileDescriptor < 0){
		perror(argv[0]);
		exit(1);
	}

	int i = 1;
	for(i; i <= 8192; i += i){
		double start = clock();

		while(write(fileDescriptor, buffer, i) != 0);
	
		double time = (clock() - start) / CLOCKS_PER_SEC;
		printf("BUF_SIZE = %4d ; TIME = %0.2f\n", i, time);
	}

	free(buffer);

	int closeResult = close(fileDescriptor);
	if(closeResult < 0){
		perror(argv[0]);
		exit(1);
	}

	return 0;

}
