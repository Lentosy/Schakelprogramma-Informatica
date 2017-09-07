#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

const int THREADS = 4;

void *worker(void *id){
  int thread_id = (int)id;
  int i;
  for(i = 0; i < 5; i++){
    printf("%2d. Process %d has number %d\n",i, thread_id, (thread_id + 50) );
  }

  pthread_exit(&thread_id);
}

int main(void){
  pthread_t threads[THREADS];

  int i = 0;
  for(i; i < THREADS; i++){
    pthread_create(&threads[i], NULL, worker, (void *)i);
  }

  for(i = 0; i < THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  return 0;
}
