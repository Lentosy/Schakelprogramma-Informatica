#include <pthread.h>

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

const int THREADS = 8;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int tickets = 100;

void *sell(void *arg);

int main(void){
  pthread_t threads[THREADS];
  int i;
  for(i = 0; i < THREADS; i++){
    pthread_create(&threads[i], NULL, sell, (void *)i);
  }

  for(i = 0; i < THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  return 0;
}

void *sell(void *arg){
  int thread_id = (int) arg;
  int sold_amount = 0;
  int done = 0;
  while(!done){
    pthread_mutex_lock(&mutex);
    if(tickets <= 0){
      done = 1;
    }else{
      sold_amount++;
      tickets--;
      printf("Thread %d is selling a ticket. %d tickets remaining.\n", thread_id, tickets);
    }
    pthread_mutex_unlock(&mutex);
    sleep(rand() % 3);
  }

  printf("Thread %d has sold %d tickets\n", thread_id, sold_amount);

}
