//Author: Bert De Saffel

#include <stdio.h>

int main(void){
	int macht = 1;
	int i;
	// Een for lus gebruik je niet als je niet weet hoeveel iteraties er nodig zullen zijn
	// Hier gok je dat je er 20 nodig hebt
	// Je gebruikt dus beter een while lus
	for(i = 0; i < 20; i++){
		printf("%d ", macht);
		macht *= 2;
		if(macht > 10000){ // Dit is het gevolg van geen while lus te gebruiken, je moet elke keer controleren
			break;
		}
	}
    return 0;
}
