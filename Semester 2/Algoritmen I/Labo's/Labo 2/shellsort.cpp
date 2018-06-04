#include "shellsort.h"

template<class T>
void shell_sort(vector<T> & v, int series[], int size) {

	//the series should be in ascending order: {1, 3, 5, .... , 949784, ...}
	// beginnen van grootste gap en naar kleinste gaan
	int k = series[--size];
	while(k >= 1){
		for(int i = k; i < v.size(); i++){
			T h = move(v[i]);
			int j = i - k;
			while(j >= 0 && h < v[j]){
				v[j + k] = move(v[j]);
				j -= k;
			}
			v[j + k] = move(h);
		}
		k = series[--size];
	}
}

