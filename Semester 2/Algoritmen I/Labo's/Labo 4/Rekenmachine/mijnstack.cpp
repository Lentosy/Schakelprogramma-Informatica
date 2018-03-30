#include "mijnstack.h"	
#include <iostream>
#include <vector>

using std::vector;
using std::ostream;

template<class T>
T & Mijnstack<T>::top() {
	return this->operator[](this->size() - 1);
};

template<class T>
void Mijnstack<T>::push(T waarde){
	this->push_back(waarde);
}

template<class T>
void Mijnstack<T>::pop(){
	this->resize(this->size() - 1);
}

template<class T>
ostream & operator<<(ostream & out, Mijnstack<T> & ms){
	vector<double>::reverse_iterator it = ms.rbegin();
	while(it != ms.rend()){
		out << *it++ << " ";
	}
	return out;
}

