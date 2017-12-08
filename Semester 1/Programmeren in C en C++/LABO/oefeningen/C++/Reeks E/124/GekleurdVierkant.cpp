#include <iostream>
#include "GekleurdeRechthoek.h"
#include "Vierkant.h"
#include "GekleurdVierkant.h"
using namespace std;




void GekleurdVierkant::print() const{
	Vierkant::print();
	GekleurdeRechthoek::print();
}
