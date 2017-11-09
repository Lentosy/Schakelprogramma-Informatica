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

	char * alfa = alfab_kleinste(argv, argc);
	init_cap(alfa);
	printf("%s\n", alfa);
}

void init_cap(char *s){
	if(*s >= 'a' && *s <= 'z'){
		*s = *s - 'a' + 'A';
	}
	while(*s++){
		if(*s >= 'A' && *s <= 'Z'){
			*s = *s - 'A' + 'a';
		}
	}
}

char * alfab_kleinste(char ** voornamen, int size){
	voornamen++;
	char * kleinste = *voornamen;
	int i;
	for(i = 1; i < size; i++){
		if(*kleinste > **voornamen){
			kleinste = *voornamen;

		}
		voornamen++;
	}


	return kleinste;


}
