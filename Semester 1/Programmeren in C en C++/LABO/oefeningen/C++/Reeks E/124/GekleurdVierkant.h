#ifndef GEKLEURDVIERKANT_H
#define GEKLEURDVIERKANT_H

#include "Vierkant.h"
#include "GekleurdeRechthoek.h"
using namespace std;

class GekleurdVierkant : public GekleurdeRechthoek, public Vierkant{
	public:
		GekleurdVierkant() {};
		GekleurdVierkant(int z = 1, string k = "onbekend") : Vierkant(z), kleur(k) {};
		void print() const;
};

#endif