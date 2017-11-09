//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

/* Bepaalt de index van een reeël getal in een array met:
 *
 *	array = de array waarin gezocht wordt
 *   size = de grootte van de array
 *      x = het getal dat gezocht moet worden
 */
int index_van(const double array[], int size, double x);

int main(){
	double numbers[] = {0,6,4.74,9,7.87,4,3.57,5,12.75,3};
	int size = sizeof(numbers) / sizeof(double);
	double res = index_van(numbers, size, 45);
	printf("%0.2f\n", res);
}


int index_van(const double array[], int size, double x){
	int i = 0;
	while(x != array[i] && i < size){
		i++;
	}
	return i == size ? -1 : i;
}