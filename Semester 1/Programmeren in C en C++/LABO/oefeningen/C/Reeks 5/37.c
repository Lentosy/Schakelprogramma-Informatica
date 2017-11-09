//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
	int d;
	knoop *next;
};

void voeg_voeraan_toe(int d, knoop ** l);
void print_lijst(const knoop *l);
void print_lijst_rec(const knoop *l);
void vernietig_lijst(knoop **l);

int main(void){
	knoop *l = 0;
	voeg_voeraan_toe(7, &l);
	voeg_voeraan_toe(3, &l);
	print_lijst(l);

	print_lijst_rec(l);
	vernietig_lijst(&l);
	return 0;
}


void voeg_voeraan_toe(int d, knoop ** l){
	knoop *k = malloc(sizeof(knoop *));
	k->d = d;
	knoop *h = *l;
	k->next = h;
	*l = k;
}

void print_lijst(const knoop *l){
	while(l){
		printf("%d ", l->d);
		l = l->next;
	}
	printf("\n");
}

void print_lijst_rec(const knoop *l){
	if(l){
		printf("%d ", l->d);
		print_lijst_rec(l->next);
	}else{
		printf("\n");
	}

}

void vernietig_lijst(knoop **l){
	knoop *h;
	while(*l){
		h = *l;
		*l = h->next;
		free(h);
	}
}