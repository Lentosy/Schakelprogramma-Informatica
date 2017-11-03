// Author: Bert De Saffel


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void init_cap(char *s);

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("Dag allemaal!\n");
		return 0;
	}

	int i;
	for(i = 1; i < argc; i++){
		init_cap(argv[i]);
		printf("Dag %s!\n", argv[i]);
	}
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


