// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int waarde;
	int aantal_delers;
	int * delers;
}deeltal;

void schrijf_ints(const int * d, int aantal);
void schrijf_deeltal(const deeltal *d);

int main(void){
	deeltal d;
	d.waarde = 6;
	d.aantal_delers = 3;
	d.delers = malloc(sizeof(int) * d.aantal_delers);
	d.delers[0] = 1;
	d.delers[1] = 2;
	d.delers[2] = 3;
	schrijf_deeltal(&d);

	free(d.delers);
	return 0;

}

void schrijf_deeltal(const deeltal *d){
	printf("%d ", d->waarde);
	schrijf_ints(d->delers, d->aantal_delers);
	printf("\n");
}

void schrijf_ints(const int * d, int aantal){
	int i;
	for(i = 0; i < aantal - 1; i++){
		printf("%d-", d[i]);
	}
	printf("%d", d[aantal - 1]);
}