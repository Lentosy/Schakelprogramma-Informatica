#include <iostream>
#include <vector>
#include "Rechthoek.cpp"
#include "GekleurdeRechthoek.cpp"
#include "Vierkant.cpp"
#include "GekleurdVierkant.cpp"


int main(void){
	Rechthoek r2(4, 6);
	GekleurdeRechthoek gr1;
	GekleurdeRechthoek gr3(6, 9, "rood");
	Vierkant v2(10);

	vector<Rechthoek * > v;
	v.push_back(move(&r2));
	v.push_back(move(&gr1));
	v.push_back(move(&gr3));
	v.push_back(move(&v2));

	for(auto x : v){
		(*x).print();
		cout << "  oppervlakte: " << (*x).oppervlakte() << endl
		<< "  omtrek: " << (*x).omtrek() << endl;
	}
	return 0;
		
}