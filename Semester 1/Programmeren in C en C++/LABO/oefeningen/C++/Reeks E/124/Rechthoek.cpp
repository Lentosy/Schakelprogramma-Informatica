#include <iostream>
#include "Rechthoek.h"
using namespace std;

void Rechthoek::print() const{
	cout << "Rechthoek: " << hoogte  << " op " << breedte << endl;
}

int Rechthoek::oppervlakte() const{
	return breedte * hoogte;
}

int Rechthoek::omtrek() const{
	return 2 * (breedte + hoogte);
}



