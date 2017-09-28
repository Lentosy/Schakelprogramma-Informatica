//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ggd(int, int);

int main(void){
    
    printf("ggd(-6, -8) = %d\n", ggd(-6, -8));
    printf("ggd(24, 18) = %d\n", ggd(24, 18));
    printf("ggd( 0, -5) = %d\n", ggd( 0, -5));
    printf("ggd( 6, -35) = %d\n", ggd( 6, -35));
    return 0;
}


int ggd(int x, int y){
    if(x == 0){
        return abs(y);
    }
    if(y == 0){
        return abs(x);
    }       
    return ggd(y, x % y);
}
