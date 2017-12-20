#ifndef GEKLEURDERECHTHOEK_H
#define GEKLEURDERECHTHOEK_H

#include "Rechthoek.h"
#include <iostream>
using namespace std;

class GekleurdeRechthoek : public Rechthoek{
	public:
		GekleurdeRechthoek() : kleur("onbekend") {};
		GekleurdeRechthoek(int h, int b) : GekleurdeRechthoek(h, b, "onbekend") {}
		GekleurdeRechthoek(int h, int b, string k) : Rechthoek(h, b), kleur(k) {}
		void print() const;
	protected:
		string kleur;
};

#endif