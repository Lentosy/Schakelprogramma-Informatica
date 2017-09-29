//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	for(i = 10; i > 0; i--){
		if(i == 10){ // Deze if wordt 10 keer gecontroleerd
			printf("Hello world!\n");
		}
		printf("%d", i);
		if(i == 1){ // Deze if wordt 10 keer gecontroleerd
			printf("\nSTART\n");
		}
	}
    return 0;
}
