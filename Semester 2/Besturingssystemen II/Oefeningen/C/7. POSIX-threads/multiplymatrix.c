#include <getopt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
/* Multiplies a fixed SIZE matrix with itself and prints the result */

/* The amount of threads to use, if enabled */
const int THREADS = 2;
/* Wether or not to use threads */
int use_threads = 0;


int matrixA[SIZE][SIZE];
int matrixB[SIZE][SIZE];
int matrixC[SIZE][SIZE];

void init_matrices(); //Matrices initializeren
void print_matrices(); //Uitprinten van de drie matrices
void multiply_matrices(); //De matrices vermenigvuldigen zonder threads
void multiply_matrices_threads(); //De matrices vermenigvuldigen met threads

int main(int argc, char *argv[]){
	init_matrices();

	if(use_threads == 0){
		multiply_matrices();
	}else{
		multiply_matrices_threads();
	}

	print_matrices();

	return 0;
}

void init_matrices(){
	printf("initializing...\n");
	int row, col;
	for(row = 0; row < SIZE; row++){
		for(col = 0; col < SIZE; col++){
			int n = (row + col) % 5;
			matrixA[row][col] = n;
			matrixB[row][col] = n;
		}
	}
}

void print_matrices(){
	printf("printing...\n");

	int row, col;
	for(row = 0; row < SIZE; row++){
		//Matrix A
		for(col = 0; col < SIZE; col++){
			printf("%4d", matrixA[row][col]);
		}

		printf("\t");
		//Matrix B
		for(col = 0; col < SIZE; col++){
			printf("%4d", matrixB[row][col]);
		}

		printf("\t");
		//Matrix C
		for(col = 0; col < SIZE; col++){
			printf("%4d", matrixC[row][col]);
		}
		printf("\n");
	}
}

void multiply_matrices(){
	printf("multiplying matrices\n");
	int rowA, colB, colArowB;

	for(rowA = 0; rowA < SIZE; rowA++){
		for(colB = 0; colB < SIZE; colB++){
			for(colArowB = 0; colArowB < SIZE; colArowB++){
				matrixC[rowA][colB] += matrixA[rowA][colArowB] * matrixB[colArowB][colB];
			}
		}
	}
}

void *multiply(void *arg){
	int rowA = (int) arg;
	int colB, colArowB;

	for(colB = 0; colB < SIZE; colB++){
		for(colArowB = 0; colArowB < SIZE; colArowB++){
			matrixC[rowA][colB] += matrixA[rowA][colArowB] * matrixB[colArowB][colB];
		}
	}
}

void multiply_matrices_threads(){
	printf("multiplying matrices with threads\n");
	pthread_t threads[THREADS];

	int i, j;
	//i = row of matrixA;
	//j = Thread number
	for(i = 0; i < SIZE; i += THREADS){
		for(j = 0; j < THREADS; j++){
			int row = i + j;
			if(row < SIZE){ // So a thread cannot edit a row that does not exist
				pthread_create(&threads[j], NULL, multiply, (void *)row);
			}
		}
		for(j = 0; j < THREADS; j++){
			pthread_join(threads[j], NULL);
		}
	}
}
