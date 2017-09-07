#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int SIZE = 1000000000;
const int THREADS = 2;
int *numbers;

int find_min(int *numbers);
int find_max(int *numbers);


void *worker(void *arg){
  char *func = (char *)arg;
  if(strcmp("min", func)){
    printf("Minimum: %d\n", find_min(numbers));
  }else{
    printf("Maximum: %d\n", find_max(numbers));
  }

  pthread_exit(NULL);

}

int main(void){
  pthread_t threads[THREADS];
  numbers = malloc(sizeof(int) * SIZE);

  int i;
  for(i = 0; i < SIZE; i++){
    numbers[i] = rand();
  }

  pthread_create(&threads[0], NULL, worker, (void *)"min");
  pthread_create(&threads[1], NULL, worker, (void *)"max");

  for(i = 0; i < THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  free(numbers);
  return 0;
}

int find_min(int *numbers){
  int min = numbers[0];
  int i;
  for(i = 1; i < SIZE; i++){
    if(numbers[i] < min){
      min = numbers[i];
    }
  }
  return min;
}

int find_max(int *numbers){
  int max = numbers[0];
  int i;
  for(i = 1; i < SIZE; i++){
    if(numbers[i] > max){
      max = numbers[i];
    }
  }
  return max;
}
