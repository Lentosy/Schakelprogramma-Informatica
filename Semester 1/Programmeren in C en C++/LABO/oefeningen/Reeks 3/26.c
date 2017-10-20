// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


void pivoteer(char *, char *, char *);
void schrijf(char *, char *);
int main(void){
	char tekst[] = {'b','d','?','z','g','o','e','z','e', 'b',' ', 'd','i','g','!','h','o','s','v'};

	pivoteer(tekst + 7, tekst + 12, tekst + 9);
	schrijf(tekst + 4, tekst + 15);
	return 0;
}

void pivoteer(char *begin, char *na_einde, char *pivot){
	char t;
	while(begin != pivot && na_einde-- != pivot){
		t = *begin;
		*begin = *na_einde;
		*na_einde = t;
		begin++;
	}
}

void schrijf(char *begin, char *na_einde){
	while(begin != na_einde){
		printf("%c", *begin);
		begin++;
	}
}
