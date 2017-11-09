//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN 100
#define MAX 120
#define COUNT (MAX - MIN) + 1

int main(){

	srand(time(NULL));

	bool numbers[COUNT] = { false };

	int i;
	for(i = 0; i < COUNT; i++){
		int r = (int)rand() % (MAX - MIN + 1) + MIN;
		numbers[r - MIN] = true;
		printf("%d\n", r);
	}

	printf("-----\n");

	for(i = 0; i < COUNT; i++){
		if(numbers[i] == false){
			printf("%d\n", i + MIN);
		}
	}
	
}


