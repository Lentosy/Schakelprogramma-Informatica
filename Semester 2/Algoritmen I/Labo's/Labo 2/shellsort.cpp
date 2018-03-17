#include "sortvector.h"
#include "shellsort.h"
#include "sortmethod.h"

template<class T>
void shell_sort(vector<T> & v, int series[], int size) {

	int t = 1;
	int k = series[size - t];

	while(k >= 1) {
		for(int i = k; i < v.size(); i ++) {
			T el = move(v[i]);
			int j = i - k;
			while(j >= 0 && el < v[j]) {
				v[j + k] = move(v[j]);
				j -= k;
			}
			v[j + k] = move(el);
		}
		t++;
		k = series[size - t];
	}
}

