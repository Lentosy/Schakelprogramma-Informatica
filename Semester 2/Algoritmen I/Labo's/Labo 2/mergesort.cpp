#include "selectionsort.h"

#include "mergesort.h"

template<class T>
void MergeSort<T>::operator()(vector<T> & v) const {
	vector<int> h(v.size() / 2);
	merge_sort(v, 0, v.size(), h);
}

template<class T>
void MergeSort<T>::merge_sort(vector<T> & v, int l, int r, vector<T> & h) const {
	// rangschikt de deelvector v[l .. r -1] door samenvoegen
	// gebruikt daarbij de hulpvector h
	if(l < r - 1){
		int m = l + (r - l)/2;
		merge_sort(v, l , m, h);
		merge_sort(v, m, r, h);
		merge(v, l, m , r , h);
	}

}

template<class T>
void MergeSort<T>::merge(vector<T> & v, int l, int m, int r, vector<T> & h) const {
	
	
}

template<class T>
string MergeSort<T>::get_name() const {
	return "Merge Sort";
}










