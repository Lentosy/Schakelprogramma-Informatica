// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


void my_toupper(char *);

int main(void){

	char s[] = "snEEuwwITJE<3!!";
	my_toupper(s);
	printf("%s\n", s);
	return 0;
}


void my_toupper(char *s){
	if(*s >= 'a' && *s <= 'z'){
		*s -= 32;
	}
	while(*s++){
		if(*s >= 'A' && *s <= 'Z'){
			*s += 32;
		}
	}
}