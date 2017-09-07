/* diningphilosophers.c */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

//         P0
//     F0      F1
//   P4           P1
//    F4         F2
//     P3  F3  P2
//
//
//

/* TYPEDEFS */
typedef enum {THINKING, EATING} action_t;

typedef struct{
  int id;
  int is_available; //1 = true; 0 = false
} fork_t;

typedef struct{
  action_t action;
  int id;
  int forks[2];
} philosopher_t;

/* VARIABLES */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
philosopher_t *philosophers;
fork_t forks;
int COUNT = 5;

/* FUNCTIONS */
void print_status();
void eat(philosopher_t philosopher);
void to_string(philosopher_t philosopher);


/* IMPLEMENTATION */
int main(int argc, char *argv[]){
  philosophers = malloc(sizeof(philosopher_t) * COUNT);
  int i;
  for(i = 0; i < COUNT; i++){
    philosophers[i].action = THINKING;
    philosophers[i].id = i;
    philosophers[i].forks[0] = i;
    philosophers[i].forks[1] = (i + 1) % 5;
    forks[i].id = i;
    forks[i].is_available = 1;
  }

  print_status();
  free(philosophers);
  return 0;
}

void print_status(){
  int i;
  for(i = 0; i < COUNT; i++){
    to_string(philosophers[i]);
  }

}

void eat(philosopher_t philosopher){
  philosopher.action = 1;
  print_status();
  sleep(10);
  philosopher.action = 0;
}

void to_string(philosopher_t philosopher){
  switch(philosopher.action){
    case 0: printf("Philosopher %d is thinking: ", philosopher.id);break;
    case 1: printf("Philosopher %d is eating: ", philosopher.id);break;
  }

  printf("This philosopher can access fork %d and %d",
      philosopher.forks[0],
      philosopher.forks[1]);
  printf("\n");
}
