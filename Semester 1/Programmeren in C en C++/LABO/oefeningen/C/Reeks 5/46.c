
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
const int LENGTE = sizeof(uint);


int bit_i(uint x, int i);
void schrijf(uint x, int lengte);
uint eenbit(int i);
int aantal_eenbits(uint x);
uint bit_i_aangezet(uint x, int i);

int main(void){

	uint x1 = 198;
	uint x2 = 1977;

	printf("--- bit_i(x, i) ---\n");
	printf("    bit_i(%4d, 0) = %d\n", x1, bit_i(x1, 0));
	printf("    bit_i(%d, 3) = %d\n", x2, bit_i(x2, 3));

	printf("\n\n");
	printf("--- schrijf(x, lengte) ---\n");
	schrijf(x1, 6);
	schrijf(x2, 9);

	printf("\n\n");
	printf("--- eenbit(i) ---\n");
	printf("    eenbit(10) = %d\n", eenbit(10));
	printf("    eenbit(3) = %d\n", eenbit(3));

	printf("\n\n");
	printf("--- aantal_eenbits(x) ---\n");
	printf("    aantal_eenbits(%d) = %d\n", x1, aantal_eenbits(x1));
	printf("    aantal_eenbits(%d) = %d\n", x2, aantal_eenbits(x2));


	return 0;
}



int bit_i(uint x, int i){
	int j;
	for(j = 0; j < i; j++){
		x >>= 1;
	}

	return x & 1;
}

void schrijf(uint x, int lengte){
	printf("    schrijf(%4d, %d) = ", x, lengte);
	int *bits = malloc(sizeof(int) * lengte);
	int i;
	for(i = 0; i < lengte; i++){
		if(x & 1){
			bits[i] = 1;
		}else{
			bits[i] = 0;
		}

		x >>= 1;
	}

	for(i = lengte - 1; i >= 0; i--){
		printf("%d", bits[i]);
	}
	printf("\n");
	free(bits);
}


uint eenbit(int i){
	uint res = 1;
	return res <<= i;
}

int aantal_eenbits(uint x){
	int aantal = 0;
	while(x){
		if(x & 1){
			aantal++;
		}

		x >>= 1;
	}
	return aantal;
}

uint bit_i_aangezet(uint x, int i){
	
}