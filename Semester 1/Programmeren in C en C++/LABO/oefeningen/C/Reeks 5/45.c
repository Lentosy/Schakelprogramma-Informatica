
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LEN 81

typedef struct knoop knoop;
struct knoop {
	char *woord;
	knoop *next;
};

knoop ** geef_array_van_lijsten(int aantal);
void schrijf_knopen(const knoop * const * k, int aantal);

int main(void){
	knoop **k = geef_array_van_lijsten(3);
	schrijf_knopen(k, 3);
}

knoop ** geef_array_van_lijsten(int aantal){
	knoop ** res = malloc(sizeof(knoop *) * (aantal + 1));
	knoop ** hulp = res;

	char woord[LEN];
	int index = 0;

	while(scanf("%s", woord) && strcmp(woord, "STOP")){
		*hulp = malloc(sizeof(knoop *));
		(*hulp)->woord = malloc(strlen(woord) + 1 * sizeof(char));
		strcpy((*hulp)->woord, woord);
		(*hulp)->next = 0;
		(*hulp) = (*hulp)->next;
		hulp = &hulp[index % aantal];
		index++;	
	}
	hulp = 0;
	return res;
}


void schrijf_knopen(const knoop * const * k, int aantal){
	knoop **h = k;
	int i;
	for(i = 0; i < aantal; i++){
		printf("%d\n", i);
		while(*h && (*h)->next){
			printf("printing zogezegd\n");
			printf("%s", (*h)->woord);
			*h = (*h)->next;
		}
		h++;
	}
}


