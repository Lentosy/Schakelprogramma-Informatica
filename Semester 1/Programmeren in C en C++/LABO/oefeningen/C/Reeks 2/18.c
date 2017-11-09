//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define MIN -1000
#define MAX 1000


void zoek_extremen(int numbers[], int *, int *);

int main(){
    srand(time(NULL));

    int numbers[SIZE] = {0};
    int i;
    int max;
    int min;
    for(i = 0; i < SIZE; i++){
        numbers[i] = (int)rand() % (MAX - MIN + 1) + MIN;
    }

    zoek_extremen(numbers, &max, &min);
    printf("\nmin: %d\nmax %d\n", min, max);
    return 0;
}



void zoek_extremen(int numbers[], int *max, int *min){
    *min = numbers[0];
    *max = numbers[0];
    int i;
    for(i = 1; i < SIZE; i++){
        printf("%d ", numbers[i]);
        if(*min > numbers[i]){
            *min = numbers[i];
        }
        if(*max < numbers[i]){
            *max = numbers[i];
        }
    }  
}




