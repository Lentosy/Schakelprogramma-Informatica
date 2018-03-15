#include "sortvector.h"
#include "insertionsort.h"
#include "sorteermethode.h"
using namespace std;



template<class T>
void InsertionSort<T>::operator()(vector<T> & v)const {
	for(int i = 1; i < v.size(); i ++){
		T el = move(v[i]);
		int j = i - 1;
		while(j >= 0 && el < v[j]){
			v[j + 1] = move(v[j]);
			j--;
		}
		v[j + 1] = move(el);
	}
}

template<class T>
string InsertionSort<T>::getName() const{
	return "Insertion Sort";
}
