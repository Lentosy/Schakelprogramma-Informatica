//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

void schuif_op(char array[], int size);
void print_array(const char array[], int size);

int main(){
	char rij[] = {'s', 'a', 'p', 'a', 'p', 'p', 'e', 'l'};
	int size = sizeof(rij) / sizeof(char);

	schuif_op(rij, size);
	print_array(rij, size);
	schuif_op(rij, size);
	print_array(rij, size);
	schuif_op(rij, size);
	print_array(rij, size);

	return 0;
}


void schuif_op(char a[], int n){
	int i;
	char start = a[0];
	for(i = 1; i < n; i++){
		a[i - 1] = a[i];
	}
	a[n - 1] = start;
}

void print_array(const char a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%c", a[i]);
	}
	printf("\n");
}