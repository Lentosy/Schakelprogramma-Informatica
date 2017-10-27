// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

void verzetNaarEersteHoofdletter(const char **);
const char * pointerNaarEersteKleineLetter(const char *);
void schrijf(const char *, const char *);

int main(void){
	const char zus1[50] = "sneeuwWITje";
	const char zus2[50] = "rozeROOD";
	const char* begin;
	const char* eind;
	begin = zus1;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind);   /* schrijft  WIT  uit */
	printf("\n");
	begin = zus2;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind);   /* schrijft  ROOD  uit */
	return 0;
}

// ** aangezien de POINTER aangepast moet worden 
void verzetNaarEersteHoofdletter(const char **p){
	while(**p && **p < 'A' && **p > 'Z'){
		(*p)++;
	}
}

const char * pointerNaarEersteKleineLetter(const char *p){
	while(*p && *p > 'a' && *p < 'z'){
		p++;
	}
	return p;
}


void schrijf(const char *begin, const char *eind){
	while(begin != eind){
		printf("%c\n", *begin);
		begin++;
	}
}