//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTE 5 /* 4 + null character */
#define MAXAANTAL 6

char * lees();
char **lees_meerdere();
void vernietig_teksten(char ** teksten);

int main(void){
	int i;

	char **teksten = lees_meerdere();
	
	char **h = teksten;
	while(*h){
		printf("!%s!\n", *h);
		h++;
	}

	vernietig_teksten(teksten);
	free(teksten);

}

char * lees(){
	char woord[LENGTE];
	fgets(woord, LENGTE, stdin);
	int lengte = strlen(woord);
	if(woord[lengte - 1] == '\n'){
		woord[lengte - 1] = 0;
		lengte--;
	}else{
		while(getchar() != '\n');
	}
	char *s = malloc((lengte + 1) * sizeof(char));
	strcpy(s, woord);
	return s;
}

char **lees_meerdere(){
	int aantal = 0;
	char *tekst = lees();
	char *lokaal[MAXAANTAL];
	while(aantal < MAXAANTAL - 1 && strcmp(tekst, "STOP")){
		lokaal[aantal] = tekst;
		aantal++;
		tekst = lees();
	}
	if(aantal == MAXAANTAL + 1 && strcmp(tekst, "STOP") != 0){
		lokaal[aantal] = tekst;
		aantal++;
	}

	char **teksten = malloc(sizeof(char*) * (aantal + 1));

	int i;
	for(i = 0; i < aantal; i++){
		teksten[i] = lokaal[i];
	}

	teksten[aantal] = 0;
	return teksten;

}

void vernietig_teksten(char ** teksten){
	while(*teksten){
		free(*teksten);
		teksten++;
	}
}