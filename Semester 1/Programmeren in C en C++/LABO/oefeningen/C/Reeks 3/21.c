// Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * plaats_van(const double array[], int size, double n);
void plaats_ptr_op_getal(double array[], int size, double **ptr, double n);
int * plaats_in_geordende_array_van(const double array[], int size, double n);


int main(void){
	double array[10] = {0.79, 0.82, 0.87, 0.83, 0.76, 0.45, 0.37, 0.63, 0.55, 0.40};
	int size = sizeof(array) / sizeof(double);

	double values[4] = {0.76, 0.79, 0.40, 0.41}; // testwaarden die gebruikt worden bij elke 
	int indices[4] = {4, 0, size -1, -1}; // indices waarbij de testwaarden overeenkomen met de echte array, -1 = niet voorkomen
	int i;

	printf("---plaats_van()---\n");
	int *result;
	for(i = 0; i < 4; i++){
		result = plaats_van(array, size, values[i]);
		if(result){
			printf("\tIndex van %.2f is %d\n", values[i], *result);
		}else{
			printf("\t%.2f bestaat niet\n", values[i]);
		}
	}

	printf("---plaats_ptr_op_getal()---\n");
	double *ptr;
	for(i = 0; i < 4; i++){
		plaats_ptr_op_getal(array, size, &ptr, values[i]);
		if(ptr){
			printf("\tpointer werd geplaatst op %.2f. ", *ptr);
			array[indices[i]] *= 2;
			printf("Dit wordt vermenigvuldigd met 2, waarde van pointer is nu %.2f\n", *ptr);
			printf("\t\ttoestand array: ");
			int j;
			for(j = 0; j < size; j++){
				printf("%.2f ", array[j]);
			}
			printf("\n");
		}else{
			printf("\t%.2f bestaat niet\n", values[i]);
		}
	}


	double array_sorted[10] = {0.37, 0.40, 0.45, 0.55, 0.63, 0.76, 0.79, 0.82, 0.83, 0.87};
	printf("---plaats_in_geordende_array_van()---\n");
	for(i = 0; i < 4; i++){
		result = plaats_in_geordende_array_van(array_sorted, size, values[i]);
		if(result){
			printf("\tIndex van %.2f is %d\n", values[i], *result);
		}else{
			printf("\t%.2f bestaat niet\n", values[i]);
		}
	}

	return 0;
}

int * plaats_van(const double array[], int size, double n){
	int index = 0;
	while(*(array + index) != n && index < size){
		index++;
	}
	int *result = &index;
	return index > (size - 1) ? 0 : result;
}

void plaats_ptr_op_getal(double array[], int size, double **ptr, double n){
	int index = 0;
	*ptr = array;
	while(*(array + index) != n && index < size){
		index++;
	}

	if(index > size - 1){
		*ptr = 0;
	}else{
		*ptr = (array + index);
	}
}	

int * plaats_in_geordende_array_van(const double array[], int size, double n){
	int left = 0;
	int right = size - 1;
	int index;

	while(array[index] != n){
		if(left > right){
            return 0;
        }
		index = (left + right) / 2;
		if(array[index] < n){
			left = index + 1;
		}else if (array[index] > n){
			right = index - 1;
		}
	}

	int *result = &index;
	return result;

}