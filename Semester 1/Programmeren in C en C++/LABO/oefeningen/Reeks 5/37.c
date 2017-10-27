
#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop{
	int getal;
	knoop * next;
};

void voeg_voeraan_toe(int getal, knoop ** k);
void print_lijst_it(knoop const *k);
void vernietig_lijst(knoop ** k);

int main(void){
	knoop *k = 0;
	voeg_voeraan_toe(7, &k);
	voeg_voeraan_toe(3, &k);
	print_lijst_it(k);
	vernietig_lijst(&k);
	return 0;
}

void voeg_voeraan_toe(int getal, knoop ** k){	
	knoop * l = malloc(sizeof(knoop));
	l->getal = getal;
	l->next = *k;
	*k = l;
}

void print_lijst_it(knoop const *k){
	while(k){
		printf("%d\n", k->getal);
		k = k->next;
	}
}

void vernietig_lijst(knoop ** k){
	while(*k){
		knoop *h = (*k)->next;
		free(*k);
		*k = h;
	}
}
