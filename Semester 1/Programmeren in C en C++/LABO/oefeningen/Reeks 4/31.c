// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4

char * lees();

int main(void){
	int i;
	for(i = 0; i < 5; i++){
		char * tekst = lees();
		if(tekst){
			printf("Ik las in %s.\n", tekst);
			free(tekst);
		}
		
	}

	return 0;
}

char * lees(){
	char *buffer;
	fgets(buffer, BUFFER_SIZE + 1, stdin);

	buffer[BUFFER_SIZE] = '\0';

	while(buffer){
		printf("%c", *buffer);
		buffer++;
	}

	char *tekst = malloc(strlen(buffer));
	return tekst;
	
}



