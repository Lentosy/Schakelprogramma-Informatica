#include "countingsort.h"




template<class T>
void CountingSort<T>::operator()(std::vector<T> & v)const {
	std::vector<int> count(find_max(v) + 1);
	for(int i = 0; i < v.size(); i++){
		count[v[i]]++;
	}
	for(int i = 1; i < count.size(); i++){
		count[i] += count[i - 1];
	}
	
	std::vector<int> hulp = v;
	for(int i = 0; i < count.size(); i++){
		v[count[hulp[i]] - 1] = hulp[i];
	}
	
	
}

template<class T>
string CountingSort<T>::get_name() const {
	return "Counting Sort";
}

template<class T>
int CountingSort<T>::find_max(std::vector<T> & v) const {
	int max = v[0];
	for(int i = 1; i < v.size(); i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	return max;
}
