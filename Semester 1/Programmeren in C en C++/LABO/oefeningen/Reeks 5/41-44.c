//Author : Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
	int getal;
	knoop * next;
};

knoop * zoek(knoop * k, int getal);
knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens);
void voeg_getal_toe(knoop **k, int g);
void print_lijst(const knoop *k);
void vernietig_lijst(knoop ** k);

int main(void){
	knoop *k = maak_gesorteerde_lijst_automatisch(10,100);
	print_lijst(k);
	vernietig_lijst(&k);

}

knoop * zoek(knoop *lijst, int getal){
	while(lijst && lijst-> getal != getal){
		lijst = lijst->next;
	}
	return lijst;
}

knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens){
	knoop *l = 0;
	int g = rand() % bovengrens;
	int i;
	for(i = 0; i < aantal; i++){
		g -= rand() % 3;
		voeg_getal_toe(&l, g);
	}

	return l;
}

void voeg_getal_toe(knoop ** k, int g){
		knoop *h;
	knoop *m;
	if(*k == 0 || g <= (*k)->getal){
		h = malloc(sizeof(knoop));
		h->next = *k;
		h->getal = g;
		*k = h;
	}else{
		h = *k;
		while(h->next && h->next->getal < g){
			h = h->next;
		}
		m = malloc(sizeof(knoop));
		m->getal = g;
		m->next = h->next;
		h->next = m;
	}
}

void print_lijst(knoop const *k){
	while(k){
		printf("%4d", k->getal);
		k = k->next;
	}
	printf("\n");
}


void vernietig_lijst(knoop ** k){
	while(*k){
		knoop *h = (*k)->next;
		free(*k);
		*k = h;
	}
}
