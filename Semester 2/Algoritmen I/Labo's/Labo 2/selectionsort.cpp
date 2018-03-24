#include "selectionsort.h"

template<class T>
void SelectionSort<T>::operator()(vector<T> & v) const {
	for(int i = v.size() - 1; i > 0; i--){
		int imax = i;
		for(int j = 0; j < i; j++){
			if(v[j] > v[imax]){
				imax = j;
			}
		}
		swap(v[i], v[imax]);
	}
}

template<class T>
string SelectionSort<T>::get_name() const {
	return "Selection Sort";
}





