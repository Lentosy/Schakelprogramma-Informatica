#include <algorithm>
#include "stdsort.h"

template<class T>
void STDSort<T>::operator()(vector<T> & v)const {
	std::sort(v.begin(), v.end(), std::greater<T>());
}


template<class T>
string STDSort<T>::getName() const{
	return "std::sort";
}


