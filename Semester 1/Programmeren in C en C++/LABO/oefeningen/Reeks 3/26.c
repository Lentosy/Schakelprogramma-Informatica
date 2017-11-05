// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


void pivoteer(const char *begin, const char *na_einde, char *pivot);
void schrijf(const char *begin, const char *na_einde);

int main(void){
	char tekst[] = {'b','d','?','z','g','o','e','z','e', 'b',' ', 'd','i','g','!','h','o','s','v'};

	pivoteer(tekst + 7, tekst + 12, tekst + 9);
	schrijf(tekst + 4, tekst + 15);
	return 0;
}

void pivoteer(const char *begin, const char *na_einde, char *pivot){
	int links = pivot - begin;
	int rechts = na_einde - pivot - 1;
	
	int i;
	for(i = 1; i <= links; i++){
		char t = pivot[i];
		pivot[i] = pivot[-i];
		pivot[-i] = t;
	}
	
}

void schrijf(const char *begin, const char *na_einde){
	while(begin != na_einde){
		printf("%c", *begin);
		begin++;
	}
}