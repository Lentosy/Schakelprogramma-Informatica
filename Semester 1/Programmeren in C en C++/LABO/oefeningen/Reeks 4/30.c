// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AANTAL 6
#define LENGTE 81 

typedef struct persoon persoon;
struct persoon {
	char naam[LENGTE];
	int leeftijd;
};

void schrijf_cstring(const void *);
void schrijf_int(const void *);
void schrijf_persoon(const void *);
void schrijf_array(const void * array, int aantal, int grootte, char tussenteken, void(*schrijf)(const void*));

int main(void){

	int i;
	char * namen[AANTAL] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
	int leeftijden[AANTAL] = {21, 30, 18, 14, 22, 19};

	persoon *personen = malloc(AANTAL * sizeof(persoon));

	for(i = 0; i < AANTAL; i++){
		strcpy(personen[i].naam, namen[i]);
		personen[i].leeftijd = leeftijden[i];
	}
	schrijf_array(leeftijden, AANTAL, sizeof(int), '+', schrijf_int);
	schrijf_array(namen, AANTAL, sizeof(char *), ';', schrijf_cstring);
	schrijf_array(personen, AANTAL, sizeof(persoon), '\n', schrijf_persoon);

	free(personen);

	return 0;
}

void schrijf_cstring(const void * s){
	printf("%s", *(char **)s);
}

void schrijf_int(const void * i){
	printf("%d", *(int *)i);
}

void schrijf_persoon(const void * p){
	printf("%s (%d)", ((persoon *)p)->naam, ((persoon *)p)->leeftijd);
}

void schrijf_array(const void * array, int aantal, int grootte, char tussenteken, void(*schrijf)(const void*)){
	int i;
	schrijf(array);
	array = (char *)array + grootte;
	for(i = 1; i < aantal; i++){
		printf("%c", tussenteken);
		schrijf(array);
		array = (char *)array + grootte;	
	}
	printf("\n");
}

