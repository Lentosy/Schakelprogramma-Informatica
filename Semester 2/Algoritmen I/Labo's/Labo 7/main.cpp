
#include <iostream>
#include <string>
#include "zoekboom.h"
#include "NCString.h"



int main(void){
	Zoekboom<int> * boom;
	boom->voegToe(25);
	
	boom->voegToe(9);
	boom->voegToe(40);
	
	boom->voegToe(4);
	boom->voegToe(14);
	boom->voegToe(33);
	boom->voegToe(57);
	
	boom->voegToe(1);
	boom->voegToe(7);
	boom->voegToe(21);
	boom->voegToe(49);
	
	boom->voegToe(17);
	

	return 0;
}
