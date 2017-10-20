// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


typedef struct deeltal deeltal;
struct deeltal{
	int waarde;
	int aantal_delers;
	int * delers;
};

void lees_deeltal(deeltal *d);
void lees_deeltallen(deeltal *deeltallen, int aantal);
void schrijf_deeltal(const deeltal *d);
void schrijf_deeltallen(const deeltal *deeltallen, int aantal);
int aantal_delers_van(int x);
int * delers_van(int x, int aantal);
void vul_aan(deeltal *d);
deeltal * zoek(int waarde, deeltal const * ptr, int aantal);


int main(void){
	
	deeltal *deeltallen = malloc(sizeof(deeltal));

	lees_deeltallen(deeltallen, 1);
	schrijf_deeltallen(deeltallen, 1);

	printf("Geef aan hoeveel deeltallen je wil ingeven: ");
	int aantal;
	if(scanf("%d", &aantal) == 0){
		printf("Error: not a valid integer\n");
		exit(1);
	}

	deeltallen = malloc(sizeof(deeltal) * aantal);
	lees_deeltallen(deeltallen, aantal);
	schrijf_deeltallen(deeltallen, aantal);


	int i;
	for(i = 0; i < aantal; i++){
		free(deeltallen[i].delers);
	}
	free(deeltallen);
	return 0;
}

void lees_deeltal(deeltal *d){
	printf("Geef een geheel getal in: ");
	int x;
	if(scanf("%d", &x) == 0){
		printf("Error: not a number\n");
	}

	d->waarde = x;
	vul_aan(d);
}

void lees_deeltallen(deeltal *deeltallen, int aantal){
	int i;
	for(i = 0; i < aantal; i++){
		deeltal d;
		lees_deeltal(&d);
		
		*deeltallen = d;
		deeltallen++;
	}
}

void schrijf_deeltallen(const deeltal *deeltallen, int aantal){
	int i;
	for(i = 0; i < aantal; i++){
		schrijf_deeltal(&deeltallen[i]);
	}
}

void schrijf_deeltal(const deeltal *d){
	printf("Waarde : %d\n", d->waarde);
	printf("\tAantal delers:\t%d\n", d->aantal_delers);
	printf("\tDelers       :\n");
	int i;
	for(i = 0; i < d->aantal_delers; i++){
		printf("\t\t\t *%d\n", d->delers[i]);
	}

	printf("\n\n\n");
}


int aantal_delers_van(int x){

	int aantal = 0;
	int i = 1;
	int half = x / 2;
	while(i <= half){
		if(x % i == 0){
			aantal++;
		}
		
		i++;
	}	
	return aantal;
}

int * delers_van(int x, int aantal){

	int *delers = malloc(aantal * sizeof(int));
	int i = 1;
	int index = 0;
	int half = x / 2;
	while(i <= half){
		if(x % i == 0){
			delers[index] = i;
			index++;
		}
		i++;
	}

	return delers;
}

void vul_aan(deeltal *d){
	int x = d->waarde;
	d->aantal_delers = aantal_delers_van(x);
	d->delers = delers_van(x, d->aantal_delers);
}

deeltal * zoek(int waarde, deeltal const * ptr, int aantal){
	
}