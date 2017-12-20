#include <iostream>
#include "GekleurdeRechthoek.h"
using namespace std;


void GekleurdeRechthoek::print() const{
	Rechthoek::print();
	cout << "  kleur: " << kleur << endl;
}
