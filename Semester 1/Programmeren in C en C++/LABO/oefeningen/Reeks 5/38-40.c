// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct knoop knoop;
struct knoop{
	int getal;
	knoop * next;
};

knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens);
knoop * merge(knoop * m, knoop *n);
void voeg_getal_toe(knoop **k, int g);
void print_lijst(const knoop *k);
void vernietig_lijst(knoop ** k);
void verwijder_dubbels(knoop * k);
void keerom(knoop ** k);


int main(void){
	srand(time(NULL));
	knoop *m = maak_gesorteerde_lijst_automatisch(10, 1000);
	knoop *n = maak_gesorteerde_lijst_automatisch(5, 1000);
	printf("\nLIJST m:\n");
	print_lijst(m);
	printf("\nLIJST n:\n");
	print_lijst(n);
	printf("\nDeze worden gemerged. \n\n");

	knoop *mn = merge(m, n);
	printf("\nLIJST mn:\n");
	print_lijst(mn);

	vernietig_lijst(&m);
	vernietig_lijst(&n);
	vernietig_lijst(&mn);

	return 0;
}

knoop * merge(knoop *m,  knoop *n){
	knoop *res = malloc(sizeof(knoop));
	knoop *start = res;

	if(m->getal < n->getal){
		res->getal = m->getal;
		m = m->next;
	}else{
		res->getal = n->getal;
		n = n->next;
	}

	res->next = malloc(sizeof(knoop));

	while(m && n){
		res = res->next;
		if(m->getal < n->getal){
			res->getal = m->getal;
			m = m->next;
		}else{
			res->getal = n->getal;
			n = n->next;
		}
		res->next = malloc(sizeof(knoop));
	}

	while(m){
		res = res->next;
		res->getal = m->getal;
		m = m->next;
		res->next = malloc(sizeof(knoop));
	}

	while(n){
		res = res->next;
		res->getal = n->getal;
		n = n->next;
		res->next = malloc(sizeof(knoop));
	}
	free(res->next);
	res->next = 0;
	return start;
}

void keerom(knoop **l){
	knoop *vorige   = NULL;
	knoop *huidige  = *l;
	knoop *volgende = NULL;

	while(huidige){
		volgende       = huidige->next;
		huidige->next  = vorige;
		vorige         = huidige;
		huidige        = volgende;
	}

	*l = vorige;
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

void voeg_getal_toe(knoop **k, int g){
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

void verwijder_dubbels(knoop * k){
	while(k){
		if(k->next && k->getal == k->next->getal){
			knoop *m = k->next;
			k->next = m->next->next;
			free(m);
			printf("%4d", k->getal);
		}
		
	}
}

void vernietig_lijst(knoop ** k){
	while(*k){
		knoop *h = (*k)->next;
		free(*k);
		*k = h;
	}
}
