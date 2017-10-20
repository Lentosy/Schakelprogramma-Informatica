// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AANTAL_WOORDEN            3
#define GEMIDDELDE_LENGTE_WOORDEN  7
#define LENGTE_ARRAY_T            AANTAL_WOORDEN * GEMIDDELDE_LENGTE_WOORDEN

void lees(char **);
void schrijf(char **);

int main(void){
	char *pt[AANTAL_WOORDEN + 1]; /* Zodat je ook nog een nullpointer kan wegsteken */

	char t[LENGTE_ARRAY_T];

	pt[0] = t;
	printf("Geef %d woorden in\n", AANTAL_WOORDEN);
	lees(pt);    /* Leest alle woorden in */
	schrijf(pt); /* Schrijft alle woorden onder elkaar uit */

	return 0;
}

void lees(char ** pt){
	int i;
	char s[GEMIDDELDE_LENGTE_WOORDEN];
	for(i = 0; i < AANTAL_WOORDEN; i++){
		if(scanf("%s", s) == 0){
			printf("Error: invalid character\n");
			exit(1);
		}
		*pt = s;
		
	}
	pt[AANTAL_WOORDEN] = '\0';
}

void schrijf(char ** pt){
	
}