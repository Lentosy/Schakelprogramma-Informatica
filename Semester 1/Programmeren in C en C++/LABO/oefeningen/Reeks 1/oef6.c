//Author: Bert De Saffel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double msin(double r);

/* Oefening op reeksontwikkeling => efficient zijn */
int main(void){
	
	printf("Enter your angle in radians: ");
	double radians;
	if(scanf("%lf", &radians) == 0){
		printf("Error: not a number\n.");
	}

	printf("sin %f\n", radians);

	printf("msin = %.3f\n sin = %.3f\n", msin(radians), sin(radians));
}


// Approximates the sine of the radians given as the parameter
double msin(double radians){
	

	int factorial_of = 1; 
	int factorial_result = 1; // The last factorial result


	int numerator; 
	double denominator = 0.0;
	double x = radians;

	double prev_term = 1; // The previous result, will be used to compare new result
	double result = 0; // The end-result
	int i = 0;
	while(fabs(prev_term - result) > 0.000000001){

		prev_term = result;
		numerator = i % 2 == 0 ? 1 : -1;
		denominator = factorial_result;
	
		result += (numerator/denominator * x);
		factorial_result *= (factorial_of + 1) * (factorial_of + 2);
		factorial_of += 2;
		x *= x * x;
		i++;
	}

	return result;
	
}