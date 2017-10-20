// Author: Bert De Saffel


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void init_cap(char *s);
char * alfab_kleinste(char ** voornamen, int size);

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Dag allemaal!\n");
		return 0;
	}

	int size = argc - 1;
	char *alfa = alfab_kleinste(argv, size);
	init_cap(alfa);
	printf("Dag %s\n!", alfa);

	return 0;
}

void init_cap(char *s){
	if(*s >= 'a' && *s <= 'z'){
		*s = toupper(*s);
	}
	while(*s++){
		if(*s >= 'A' && *s <= 'Z'){
			*s = tolower(*s);
		}
	}
}



char * alfab_kleinste(const char ** voornamen, int size){
	voornamen++; // 1ste argument overslaan
	char *kleinste = *voornamen;
	int i;
	for(i = 1; i < size; i++){
		voornamen++;
		if(**voornamen < *kleinste){
			kleinste = *voornamen;
		}
	}

	return kleinste;
}
