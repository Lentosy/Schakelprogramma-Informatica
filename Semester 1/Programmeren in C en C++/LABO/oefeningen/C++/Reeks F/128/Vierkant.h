#ifndef VIERKANT_H
#define VIERKANT_H

#include "Rechthoek.h"
using namespace std;

class Vierkant : public Rechthoek{
	public:
		Vierkant() {};
		Vierkant(int z) : Rechthoek(z, z) {};
		void print() const;
};

#endif