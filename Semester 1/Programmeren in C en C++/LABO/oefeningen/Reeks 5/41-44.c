//Author : Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;
struct knoop {
	int getal;
	knoop * next;
};

knoop * zoek(knoop * k, int g);
knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens);
void voeg_getal_toe(knoop **k, int g);
void print_lijst(const knoop *k);
void vernietig_lijst(knoop ** k);
void verwijder(knoop **k, int g);

int main(void){
	srand(time(NULL));
	knoop *k = maak_gesorteerde_lijst_automatisch(10,100);
	print_lijst(k);
	verwijder(&k, k->next->getal);
	print_lijst(k);
	vernietig_lijst(&k);

}

knoop * zoek(knoop *k, int g){
	while(k->next && k->getal != g){
		k = k->next;
	}
	return k;
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
	if((*k)->next){
		vernietig_lijst(&(*k)->next);
	}
	free(*k);
}

void verwijder(knoop **k, int g){
	knoop *h = *k;
	knoop *m = *k;
	while(m->next && m->getal != g){
		h = m;
		m = m->next;
	}

	h->next = m->next;
	free(m);
	
}
