//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void wis (char *s);

int main(void){
	char s[80] = "8d'a7!<t-)>+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 2 3g*(e('d22a'(a25n'(";
	wis(s);
	printf("%s\n", s);
}

void wis(char *s){
	char *w = s;
	while(*s){
		if(islower(*s) || isspace(*s)){
			*w = *s;
			w++;
		}

		s++;
	}
	*w = 0;
}