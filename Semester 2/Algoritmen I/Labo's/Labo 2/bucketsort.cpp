#include "bucketsort.h"
#include <cmath>
#include "insertionsort.h"



template<class T>
void BucketSort<T>::operator()(std::vector<T> & v)const {
	int max = find_max(v);
	int divisor = max / 10;
	std::vector<std::vector<int>> buckets(max / divisor);

	for(int i = 0; i < v.size(); i++) {
		int bucket_index = std::floor(v[i] / divisor);
		buckets[bucket_index].push_back(v[i]);
	}

	InsertionSort<int> insertionsort;
	for(int i = 0; i < buckets.size(); i++) {
		insertionsort(buckets[i]);
	}

	int vector_index = 0;
	for(int i = 0; i < buckets.size(); i++) {
		for(int j = 0; j < buckets[i].size(); j++) {
			v[vector_index] = buckets[i][j];
			vector_index++;
		}

	}


}

template<class T>
string BucketSort<T>::get_name() const {
	return "Bucket Sort";
}

template<class T>
int BucketSort<T>::find_max(std::vector<T> & v) const {
	int max = v[0];
	for(int i = 1; i < v.size(); i++) {
		if(v[i] > max) {
			max = v[i];
		}
	}
	return max;
}
