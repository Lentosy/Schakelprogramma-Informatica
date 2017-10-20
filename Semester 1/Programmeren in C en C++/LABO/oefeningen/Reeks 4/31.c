// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

char * lees();

int main(void){
	int i;

	char * tekst = lees();
	printf("Ik las in: %s\n", tekst);
	free(tekst);
	return 0;
}

/* buffer groot maken */

char * lees(){
	char * str = malloc(sizeof(char) * MAX_LEN);
	fgets(str, MAX_LEN + 1, stdin);
	return str;
}


