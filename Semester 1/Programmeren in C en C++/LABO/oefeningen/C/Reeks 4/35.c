// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


typedef struct deeltal deeltal;
struct deeltal{
	int waarde;
	int aantal_delers;
	int * delers;
};

int aantal_delers_van(int x);
int * delers_van(int x, int aantal);
void vul_aan(deeltal *g);
void lees_deeltal(deeltal *g);
void lees_deeltallen(deeltal *d, int aantal);
void schrijf_deeltallen(const deeltal *d, int aantal);
void schrijf_deeltal(const deeltal *g);
void schrijf_delers(const int * delers, int aantal);
const deeltal * zoek(int waarde, deeltal const *ptr, int aantal);


int main(void){
	
	deeltal *d = malloc(sizeof(deeltal));
	lees_deeltal(d);
	schrijf_deeltal(d);
	free(d);
	int aantal;
	printf("Hoeveel deeltallen wil je inlezen: ");
	scanf("%d", &aantal);
	d = malloc(sizeof(deeltal) * aantal);
	lees_deeltallen(d, aantal);
	schrijf_deeltallen(d, aantal);

}

int aantal_delers_van(int x){
	int aantal = 0;
	int i;
	for(i = 1; i <= x / 2; i++){
		if(x % i == 0){
			aantal++;
		}
	}
	return aantal;
}

int * delers_van(int x, int aantal){
	int * delers = malloc(sizeof(int) * aantal);
	int index = 0;
	int i;
	for(i = 1; i <= x / 2; i++){
		if(x % i == 0){
			delers[index++] = i; 
		}
	}
	return delers;
}

void vul_aan(deeltal *g){
	g->aantal_delers = aantal_delers_van(g->waarde);
	g->delers = delers_van(g->waarde, g->aantal_delers);
}

void lees_deeltal(deeltal *g){
	int waarde;
	printf("Geef een geheel getal in: ");
	scanf("%i", &(g->waarde));
	vul_aan(g);
}

void lees_deeltallen(deeltal *d, int aantal){
	int i;
	for(i = 0; i < aantal; i++){
		lees_deeltal(&d[i]);
	}
}

void schrijf_deeltallen(const deeltal *d, int aantal){
	int i;
	for(i = 0; i < aantal; i++){
		schrijf_deeltal(&d[i]);
	}
}

void schrijf_deeltal(const deeltal *g){
	printf("\tWaarde       : %d\n", g->waarde);
	printf("\tAantal Delers: %d\n", g->aantal_delers);
	printf("\tDelers       : ");
	schrijf_delers(g->delers, g->aantal_delers);
	printf("\n\n");
	
}

void schrijf_delers(const int * delers, int aantal){
	int i;
	for(i = 0; i < aantal - 1; i++){
		printf("%d-", delers[i]);
	}
	printf("%d", delers[aantal - 1]);
}

const deeltal * zoek(int waarde, deeltal const *ptr, int aantal){
	int i;
	const deeltal *d = 0;
	for(i = 0; i < aantal; i++){
		if(ptr->waarde == waarde){
			d = ptr;
		}
	}
	return d;
}