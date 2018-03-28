#include "quicksort.h"

template<class T>
void QuickSort<T>::operator()(vector<T> & v) const {
	quick_sort(v, 0, v.size() - 1);
}

template<class T>
void QuickSort<T>::quick_sort(vector<T> & v, int l, int r) const {
	if(l < r){
		T pivot = v[l];
		int i = l, j = r;
		while(v[j] > pivot){
			j--;
		}
		while(i < j){
			swap(v[i], v[j]);
			i++;
			while(v[i] < pivot){
				i++;
			}
			j--;
			while(v[j] > pivot){
				j--;
			}
		}
		
		quick_sort(v, l, j);
		quick_sort(v, j + 1, r);
	}
}

template<class T>
string QuickSort<T>::get_name() const {
	return "Quick Sort";
}



