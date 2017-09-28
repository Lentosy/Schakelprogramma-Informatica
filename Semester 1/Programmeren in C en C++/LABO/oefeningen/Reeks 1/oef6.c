//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>



/* Oefening op reeksontwikkeling => efficient zijn */
int main(void){
    
    double radians = 0.23;
    double result = 0;

    int exp_of = 1;
    double exp_res = radians;

    int fac_of = 1; 
    long fac_res = 1;


    int n = 0;
    while(n < 5){ /* zolang dat nieuwe res verschilt van oud result */

        int numerator = n % 2 == 0 ? 1 : -1; /*(-1)^1 = -1 ; (-1)^2 = 1; ... (-1)^5 = -1 */
        int denominator = fac_res;
        

        printf("(%d / %d) * %f = %f\n", numerator, denominator, exp_res, ((double)numerator / (double)denominator) * exp_res);
        result += ((double)numerator / (double)denominator) * exp_res;
        printf("%f\n", result);
        
        
        exp_res *= radians * radians;
        exp_of += 2;
        
        fac_res *= (fac_of + 1) * (fac_of + 2);
        fac_of += 2;

        n++;
    }

    printf("sin %.2f = %.2f\n", radians, result);
}


