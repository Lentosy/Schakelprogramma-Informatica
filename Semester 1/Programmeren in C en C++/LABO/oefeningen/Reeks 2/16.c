//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

#define SIZE 26

void read(int freq[]);
void horizon_graph(int freq[]);
void vertic_graph(int freq[]);
int max_freq(int freq[]);

int main(void){
	int freq[SIZE] = {0};
	read(freq);
	horizon_graph(freq);
	vertic_graph(freq);
}


void read(int freq[]){
	char c;
	while(c != '$' && scanf("%c", &c) != 0){
		if(c >= 'A' && c <= 'Z'){
			c = c - 'A';
		}
		if(c >= 'a' && c <= 'z'){
			c = c - 'a';
		}
		freq[c]++;
	}
}

void horizon_graph(int freq[]){
	int i;
	int j;
	for(i = 0; i < SIZE; i++){
		printf("%c: ", i + 'a');
		for(j = 0; j < freq[i]; j++){
			printf("*");
		}
		printf("\n");
	}
}

void vertic_graph(int freq[]){
	int max = max_freq(freq);
	int i;
	for(max; max > 0; max--){
		for(i = 0; i < SIZE; i++){
			if(freq[i] >= max){
				printf("%c", i + 'a');
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int max_freq(int freq[]){
	int max = freq[0];
	int i;
	for(i = 1; i < SIZE; i++){
		if(freq[i] > max){
			max = freq[i];
		}
	}
	return max;
}