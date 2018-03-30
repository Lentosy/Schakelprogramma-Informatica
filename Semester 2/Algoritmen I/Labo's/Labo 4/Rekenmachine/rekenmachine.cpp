#include <iostream>
#include <string>
#include <functional>
#include "rekenmachine.h"
using std::ostream;
using std::string;

bool Rekenmachine::should_stop(){
	return stop;
}

ostream & operator<<(ostream & out, Rekenmachine & r) {
	out << r.resultaten;
	return out;
}

istream & operator>>(istream & in, Rekenmachine & r) {
	string input;
	in >> input;
	double conv = atof(input.c_str());
	if(conv != 0){ // checken if geldig getal
		r.resultaten.push(conv);
	}else if (input[0] == 'x' && input.size() == 1){ // stopcode checken
		r.stop = true;
	}else{
		// zoek in de map van operaties de functie met als sleutel 'input', en voer de functie uit met parameter r.resultaten (mijnstack)
		function<void(Mijnstack<double>&)> f = r.operaties[input];
		if(f != nullptr){ // enkel voor geldige operaties
			f(r.resultaten);			
		}
	}
	
	return in;
}

