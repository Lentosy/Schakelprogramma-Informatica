#include <stdio.h>
#include <string.h>

#define AANTAL 6
#define LENGTE 81 

typedef struct{
	char naam[LENGTE];
	int leeftijd;
}persoon;

void schrijf_cstring(const void **s);
void schrijf_int(const void *i);
void schrijf_persoon(const void *p);
void schrijf_array(const void * array, int aantal, int grootte, char tussenteken, void(*schrijf)(const void *));

int main(){
	int i;
	char * namen[AANTAL] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
	int leeftijden[AANTAL] = {21, 30, 18, 14, 22, 19};
	persoon personen[AANTAL];

	for(i = 0; i < AANTAL; i++){
		strcpy(personen[i].naam, namen[i]);
		personen[i].leeftijd = leeftijden[i];
	}

	schrijf_array(leeftijden, AANTAL, sizeof(int), '+', schrijf_int);
	schrijf_array(namen, AANTAL, sizeof(char *), ';', schrijf_cstring);
	schrijf_array(personen, AANTAL, sizeof(persoon), '\n', schrijf_persoon);

	return 0;
}

void schrijf_cstring(const void *s){
	printf("%s", *(char **)s);
}

void schrijf_int(const void *i){
	printf("%d", *(int *)i);
}

void schrijf_persoon(const void *p){
	printf("%s (%d)", ((persoon *)p)->naam, ((persoon *)p)->leeftijd);
}


void schrijf_array(const void * array, int aantal, int grootte, char tussenteken, void(*schrijf)(const void *)){
	int i;
	char * casted = (char * ) array;
	for(i = 0; i < aantal; i++){
		schrijf(casted);
		casted += grootte;
		printf("%c", tussenteken);
	}
	printf("\n");
}