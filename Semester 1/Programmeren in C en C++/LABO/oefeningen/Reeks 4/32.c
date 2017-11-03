// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4
#define MAX_AANTAL 6

char * lees();
char ** lees_meerdere();

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
	char buffer[BUFFER_SIZE + 1];
	printf("Geef een woord in: ");
	fgets(buffer, BUFFER_SIZE, stdin);

	int length = strlen(buffer);
	printf("%d:", length);
	char *tekst = malloc(sizeof(char) * length);
	strcpy(tekst, buffer);
	return tekst;
}

char ** lees_meerdere(){

}

