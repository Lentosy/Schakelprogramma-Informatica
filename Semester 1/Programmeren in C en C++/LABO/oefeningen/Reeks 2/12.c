//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

void schrijf_even_posities(const char [], int);

int main(){
	char letters[] = {'p', 'o', 'r', 'e', 'o','i', 'f', 'o', 'i', 'e', 'c', 'i', 'i', ':', 'a', '-', 't', '('};
   	int n = sizeof(letters)/sizeof(char);
   	schrijf_even_posities(letters, n);
    return 0;
}

void schrijf_even_posities(const char c[], int n){
	int i;
   	for(i = 0; i < n; i += 2){
   		printf("%c", c[i]);
   	}
   	printf("\n");
}

