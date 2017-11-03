// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AANTAL_WOORDEN             3
#define GEMIDDELDE_LENGTE_WOORDEN  7
#define LENGTE_ARRAY_T             AANTAL_WOORDEN * GEMIDDELDE_LENGTE_WOORDEN



void lees(char ** const pt);
void schrijf(char ** const pt);

int main(void){
	char *pt[AANTAL_WOORDEN + 1]; /* Zodat je ook nog een nullpointer kan wegsteken */

	char t[LENGTE_ARRAY_T];

	pt[0] = t;
	lees(pt);    /* Leest alle woorden in */
	schrijf(pt); /* Schrijft alle woorden onder elkaar uit */

	int f;
	scanf("%d", &f);
	return 0;
}

void lees(char * * const pt){
	int i;
	char buffer[GEMIDDELDE_LENGTE_WOORDEN];
	for(i = 0; i < AANTAL_WOORDEN; i++) {
		printf("Geeft woord %d in: ", (i + 1));
		if(scanf("%s", &buffer) == 0){
			printf("Error: invalid character\n");
			exit(1);
		}

		int length = strlen(buffer);
		char *woord = buffer;
		*pt = woord;
    } 

   
}

void schrijf(char * * const pt){
	printf("%s\n", *pt);
}
