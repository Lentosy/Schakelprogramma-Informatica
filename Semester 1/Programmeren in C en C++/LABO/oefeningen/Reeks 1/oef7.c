//Author: Bert De Saffel


#include <stdio.h>
#include <stdlib.h>



int main(void){
    const int max = 5;
    int som = 0;
    int getal = 0;
    int i = 0;

    while(i < max && getal >= 0){
        som += getal;
        scanf("%d", &getal);
        i++;
    }


    printf("De som van deze getallen is: %d\n", som);


}