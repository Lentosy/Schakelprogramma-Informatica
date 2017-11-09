//Author: Bert De Saffel

#include <stdio.h>

int main(void){
    
    int i;
    for(i = 0; i <= 64; i++){
        printf("%d %o %x\n", i, i, i);
    }

    return 0;   
}
