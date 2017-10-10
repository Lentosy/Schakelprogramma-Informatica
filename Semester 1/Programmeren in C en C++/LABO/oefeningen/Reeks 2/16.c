//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

#define SIZE 26


void read(int freq[]);
void horiz_graph(const int freq[]);
void verti_graph(const int freq[]);
int max_freq(const int freq[]);

int main(){
	int freq[SIZE] = {0};
	read(freq);
	horiz_graph(freq);
	verti_graph(freq);
	return 0;
}


void read(int freq[]){;
	char c;
	do{
		if(c >= 'A' && c <= 'Z'){
			freq[c - 'A']++;
		}else { //(ch >= 'a' && ch <= 'z')
			freq[c - 'a']++;
		}	
	}while(scanf("%c", &c) != 0 && c != '$');

}

void horiz_graph(const int freq[]){
	printf("Horizontal frequence graph:\n");
	int i;
	int j;
	for(i = 0; i < SIZE; i++){
		printf("%c: ",i + 'a');
		for(j = 0; j < freq[i]; j++){
			printf("*");
		}
		printf("\n");
	}
}

void verti_graph(const int freq[]){
	printf("Vertical frequence graph:\n");
	int i;
	int j;
	for(i = max_freq(freq); i > 0; i--){
		for(j = 0; j < SIZE; j++){
			if(freq[j] >= i){
				printf("%c", j + 'a');
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int max_freq(const int freq[]){
	int max = freq[0];
	int i;
	for(i = 1; i < SIZE; i++){
		if(max < freq[i]){
			max = freq[i];
		}
	}
	return max;
}