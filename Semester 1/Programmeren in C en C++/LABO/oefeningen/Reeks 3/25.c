// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void wis(char *);

int main(void){
	// char *s kan nooit aangepast worden, dus char s[]
    char s[] = "8d'a7!<t-)>+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 23g*(e('d22a'(a25n'(";
	wis(s);
	printf("%s\n", s);

	printf("Geef een woord in (met spaties)");
	fgets(s, 41, stdin);
	wis(s);
	printf("%s\n", s);
	return 0;
}

void wis(char *s){
	char *t = s;
	while(*t){
		if(islower(*t) || isspace(*t)){
			*s++ = *t;
		}
		t++;
	}
	*s = 0;
}

