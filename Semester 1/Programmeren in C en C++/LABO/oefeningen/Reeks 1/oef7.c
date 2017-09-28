//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>

int main(void){
    const int max = 5; /* The maximum amount of numbers */
    int numbers[max]; /* An array holding all the positive numbers */
    int count = 0; /* The amount of positive numbers */
    int i;
    for(i = 0; i < max; i++){
        int n;
        if(scanf("%d", &n) == 0){ /* No matching item */
            printf("Error: not an integer\n");
            exit(1);
        }else if (n < 0){
            printf("Negative number, stopping input.\n");
            break;
        }else {
            count++;
            numbers[i] = n;
        }
    }

    int sum = 0;
    for(i = 0; i < count; i++){
        sum += numbers[i];
    }

    printf("The sum of the positive integers is: %d\n", sum);
    
    return 0;
}
