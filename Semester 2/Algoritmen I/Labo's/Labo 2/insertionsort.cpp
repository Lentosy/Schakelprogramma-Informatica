#include "insertionsort.h"

/* Implementation of Insertion Sort */


template<class T>
void InsertionSort<T>::operator()(vector<T> & v)const {
	for(int i = 0; i < v.size(); i++){
		T h = move(v[i]);
		int j = i - 1;
		while(j >= 0 && h < v[j]){
			v[j + 1] = move(v[j]);
			j--;
		}
		v[j + 1] = move(h);
	}
}

template<class T>
string InsertionSort<T>::get_name() const{
	return "Insertion Sort";
}
