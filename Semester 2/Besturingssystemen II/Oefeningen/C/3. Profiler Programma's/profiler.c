#include <stdlib.h>
#include <stdio.h>

int main(void){
  int *numbers = malloc(sizeof(int) * 2000);

  free(numbers);
  return 0;
}
