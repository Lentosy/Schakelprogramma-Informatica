// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


typedef struct deeltal deeltal;
struct deeltal{
	int waarde;
	int aantal_delers;
	int * delers;
};

void schrijf_ints(int * array, int size);
void schrijf_deeltal(deeltal *);

int main(void){
	deeltal d;
	d.waarde = 6;
	d.aantal_delers = 3;
	int delers[3] = {1, 2, 3};
	d.delers = delers;

	schrijf_deeltal(&d);
	return 0;
}


void schrijf_ints(int *array, int size){
	int i;
	printf("%d", *array);
	for(i = 1; i < size; i++){
		array++;
		printf("-%d", *array);
	}
	printf("\n");
}

void schrijf_deeltal(deeltal *d){
	printf("%-4d", d->waarde);
	//int size = sizeof(d->delers) / sizeof(int);
	int size = 3;
	schrijf_ints(d->delers, size);
}