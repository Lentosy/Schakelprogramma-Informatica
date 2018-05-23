#include "hashtabel.h"

template<class T, int(* hashindex)(const T&,int n)>
hashtabel<T, hashindex>::hashtabel(int n){
	this->resize(n);
} 

template<class T, int(* hashindex)(const T&,int n)>
void hashtabel<T, hashindex>::voegToe(const T & element){
	int index = hashindex(element, this->size());
	this->operator[](index).push_back(element);
} 


template<class T, int(* hashindex)(const T&,int n)>
double hashtabel<T, hashindex>::berekenEfficientie() const{
	// (1/n) * (n + 1/2 * sum(n_i)^2)
	// => 1 + {[1/(2*n)] *sum (ni^2)}
	 
	double result = 0;
	
	for(int i = 0; i < this->size(); i++){
		double listsize = this->operator[](i).size();
		result += (listsize * listsize);
	}
	
	result /= (2 * this->size());
	result += 1;
	
	return result;
} 

template<class T, int(* hashindex)(const T&,int n)>
void hashtabel<T, hashindex>::print(std::ostream& out) const{
	int index = 0;
	typename std::vector<std::list<T>>::const_iterator vector_it = this->begin();
	while(vector_it != this->end()){
		typename std::list<T>::const_iterator list_it = (*vector_it).begin();
		out << index << " : [";
		while(list_it != (*vector_it).end()){
			out << *list_it++ << " ";
		}
		out << "]\n";
		vector_it++;	
		index++;
	}
}
	



