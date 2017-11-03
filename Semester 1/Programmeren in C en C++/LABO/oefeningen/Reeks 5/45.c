
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct knoop knoop;
struct knoop {
	char * woord;
	knoop * next;
};

knoop ** geef_array_van_lijsten(int aantal);

int main(void){
	geef_array_van_lijsten(3);
}


knoop ** geef_array_van_lijsten(int aantal){
	knoop ** lijsten = malloc(sizeof(knoop *) * aantal);
	knoop ** hulp = lijsten;
	char woord[80];
	int index = 0;
	while(strcmp(woord, "STOP")){
		scanf("%s", woord);
		printf("Adding %s to list %d\n", woord, index);
		char *input = malloc(sizeof(char) * strlen(woord));

		knoop *k = malloc(sizeof(knoop *));
		strcpy(k->woord, input);

		(*hulp)->next = k;
		index = (index + 1) % aantal;


	}

	free(hulp);
	return lijsten;
}