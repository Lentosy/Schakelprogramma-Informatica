// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AANTAL_WOORDEN            3
#define GEMIDDELDE_LENGTE_WOORDEN  7
#define LENGTE_ARRAY_T            AANTAL_WOORDEN * (1 + GEMIDDELDE_LENGTE_WOORDEN)

void lees(char **);
void schrijf(const char * const * pt);

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
	for(i = 0; i < AANTAL_WOORDEN; i++){
		scanf("%s", *pt);
		*(pt + 1) = *pt + strlen(*pt) + 1;
		pt++;
	}
	*pt = 0;
}

void schrijf(const char * const * pt){
	while(*pt){
		printf("%s\n", *pt);
		pt++;
	}
}