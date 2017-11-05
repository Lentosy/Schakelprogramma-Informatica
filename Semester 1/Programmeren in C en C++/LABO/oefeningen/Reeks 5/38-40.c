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
knoop * merge(knoop **k, knoop **m);
void voeg_toe_gesorteerd(int d, knoop ** k);
void verwijder_dubbels(knoop **k);
void print_lijst(const knoop *k);
void vernietig_lijst(knoop **k);


int main(void){
	srand(time(NULL));
	printf("Lijst met 10 gesorteerde getallen met als bovengrens 1000 wordt aangemaakt: ");
	knoop *l = maak_gesorteerde_lijst_automatisch(10, 1000);
	printf("\n\t\t\tl: ");
	print_lijst(l);

	printf("\nLijst met  5 gesorteerde getallen met als bovengrens 1000 wordt aangemaakt: ");
	knoop *n = maak_gesorteerde_lijst_automatisch(5, 1000);
	printf("\n\t\t\tn: ");
	print_lijst(n);

	printf("\nBeide lijsten worden samengevoegd: ");
	knoop *ln = merge(&l, &n);
	printf("\n\t\t   ln: ");
	print_lijst(ln);
	printf("\n");

	vernietig_lijst(&ln);
	return 0;
}

knoop * merge(knoop **k,  knoop **m){
	knoop *begin;
	knoop **res = &begin;
	knoop *kh = *k;
	knoop *mh = *m;

	while(kh && mh){
		if(kh->getal < mh->getal){
			*res = kh;
			kh = kh->next;
		}else{
			*res = mh;
			mh = mh->next;
		}
		res = &((*res)->next);
	}
	if(kh){
		*res = kh;
	}

	if(mh){
		*res = mh;
	}

	*k = 0;
	*m = 0;
	return begin;
}





knoop * maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens){
	int i;
	int d = rand() % bovengrens;

	knoop *k = 0;

	for(i = 0; i < aantal; i++){
		d += rand() % (5 - (-5) + 1) + (-5);
		voeg_toe_gesorteerd(d, &k);
	}
	return k;
}


void voeg_toe_gesorteerd(int d, knoop ** k){;
	knoop *h;
	knoop *m;
	if(*k == 0 || d <= (*k)->getal){
		h = malloc(sizeof(knoop *));
		h->next = *k;
		h->getal = d;
		*k = h;
	}else{
		h = *k;
		while(h->next && h->next->getal < d){
			h = h->next;
		}
		m = malloc(sizeof(knoop *));
		m->getal = d;
		m->next = h->next;
		h->next = m;
	}
}

void verwijder_dubbels(knoop **k){
	knoop *h = *k;
	knoop *prev = h;
	h = h->next;
	while(h){
		if(prev->getal == h->getal){
			prev->next = h->next;
			free(h);
		}else{
			prev = h;
		}
		h = h->next;
	}
}


void print_lijst(const knoop* k){
	while(k){
		printf("%3d ", k->getal);
		k = k->next;
	}
}

void vernietig_lijst(knoop **k){
	knoop *h;
	while(*k){
		h = *k;
		*k = h->next;
		free(h);
	}
}

