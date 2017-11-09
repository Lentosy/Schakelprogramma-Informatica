// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

void my_toupper(char *s);

int main(void){
	char s[80] = "snEEuwwITJE<3!!";
	printf("%s => ", s);
	my_toupper(s);
	printf("%s\n", s);

	char w[80];
	printf("Geef een woord in: ");
	scanf("%s", w);
	my_toupper(w);
	printf("%s\n", w);
}


void my_toupper(char *s){
	if(*s == 0){
		return;
	}

	if(*s >= 'a' && *s <= 'z'){
		*s = *s - 'a' + 'A';
	}

	s++;

	while(*s){
		if(*s >= 'A' && *s <= 'Z'){
			*s = *s - 'A' + 'a';
		}
		s++;
	}
}
