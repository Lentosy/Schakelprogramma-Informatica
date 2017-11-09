//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>


int cijfersom(int);
int cijfersom_herhaald(int);
int cijfersom_rec(int);

int main(){
    int count = 10; /* The amount of numbers we will scan */
    int i;
    for(i = 0; i < count; i ++){
        int d;
        printf("Enter number %d: ", (i + 1));
        if(scanf("%d", &d) == 0){
            /* keep asking */
        }


        int c_herhaald_res = cijfersom_herhaald(d);
        int c_rec_res = cijfersom_rec(d);
        
        printf("%10scijfersom(%d) = %d\n","" ,d, cijfersom(d));
        printf("%10scijfersom_herhaald(%d) = %d\n", "", d, c_herhaald_res);
        printf("%10scijfersom_rec(%d) = %d\n", "", d, c_rec_res);
        if(c_herhaald_res == c_rec_res){
            printf("%10sOK\n", "");
        }else{
            printf("%10sNIET OK\n", "");
        }
    }
    return 0;
}


int cijfersom(int x){
    int res = 0;
    while(x > 0){
        res += (x % 10);
        x /= 10;
    }
    return res;
}

int cijfersom_herhaald(int x){
    while(x > 10){
        x = cijfersom(x);
    }
    return x;
}

int cijfersom_rec(int x){
    if(x < 10){
        return x;
    }
    return cijfersom_rec(x / 10 + x % 10);
}   




