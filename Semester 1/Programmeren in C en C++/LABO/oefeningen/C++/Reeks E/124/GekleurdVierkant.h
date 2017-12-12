#ifndef GEKLEURDVIERKANT_H
#define GEKLEURDVIERKANT_H

#include "Vierkant.h"
#include "GekleurdeRechthoek.h"
using namespace std;

class GekleurdVierkant : public GekleurdeRechthoek, public Vierkant{
	public:
		GekleurdVierkant() {};
		GekleurdVierkant(int z) : GekleurdVierkant(z, "onbekend") {};
		GekleurdVierkant(int z, string k) : GekleurdeRechthoek(z, z, k), Vierkant(z) {};
		void print() const;
};

#endif