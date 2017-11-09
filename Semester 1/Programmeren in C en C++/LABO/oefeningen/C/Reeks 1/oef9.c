//Author: Bert De Saffel

#include <stdio.h>

int faculteit(int);
int schrijf_faculteit(int);

int main(void){

    int i;
    for(i = 0; i < 40; i++){
       schrijf_faculteit(i);

    }
    return 0;
}

int faculteit(int x){
    if(x == 0){
        return 1;
    }
    return x * faculteit(x - 1);

}   

int schrijf_faculteit(int x){
    printf("%d! = %d\n",x, faculteit(x));

}   
