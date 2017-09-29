//Author: Bert De Saffel

#include <stdio.h>

int main(){

	int macht = 1;
	// Dit zal ook nog 16.384 uitschrijven, wat groter is dan 10.000
	while(macht < 10000){
		printf("%d ", macht);
		macht *= 2;
		//printf("%d ", macht); -- Zet de printf voor de toekenning
	}
    return 0;
}
