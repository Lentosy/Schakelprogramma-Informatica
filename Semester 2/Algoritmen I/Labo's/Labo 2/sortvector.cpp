/**
 \class sortvector
 \brief is een klasse van sorteerbare vectoren
 Bovenop de vectoreigenschappen zijn er hulpfuncties om sorteervergelijkingen
 te vergemakkelijken.
*/
#include <iostream>
#include <iomanip>   // voor setw
#include <cstdlib>   // voor rand - opletten!! 
#include <map>
#include <vector>
#include "sortvector.h"
using namespace std;

/// \fn vul_range vul vector met de waarden T(0)...T(size()-1) in volgorde
template<class T>
void Sortvector<T>::vul_range(){
	int size = this->size();
    for(int i = 0; i < size; i++){
    	(*this)[i] = i;
	}
}

//draait een vector om i guess	
template<class T>
void Sortvector<T>::draai_om(){
	for (int i=0; i<this->size()-i-1; i++ ){
       std::swap((*this)[i],(*this)[this->size()-i-1]);
    }
}
	
//vult vector op van hoog naar klein (v = [5, 4, 3, 2, 1, 0])
template<class T>
void  Sortvector<T>::vul_omgekeerd(){
	int size = this->size() - 1;
	for(int i = size; i >= 0; i--){
		(*this)[size - i] = i;
	}
}

// shuffle vector
template<class T>
void  Sortvector<T>::shuffle(){
    random_shuffle(this->begin(),this->end());
};

// vul vector op met random(geen dubbele) waarden
template<class T>
void Sortvector<T>::vul_random_zonder_dubbels(){
	int r;
	std::map<int, bool> alVoorgekomen;
	int size = this->size();
	for(int i = 0; i < this->size(); i++){
		
		r = rand() % (10 * this->size());
		
		while(alVoorgekomen[r]){
			r = rand() % (10 * this->size());  // ander getal genereren als het al voorgekomen is
		}
		
		alVoorgekomen[r] = true;
		(*this)[i] = r;
	}	
}


template<class T>
bool Sortvector<T>::is_gesorteerd() const{
	int size = this->size();
	int i = 1;
	while((*this)[i - 1] < (*this)[i]){
		i++;	
	}
	return (i >= size);	// als i < size => false, anders true  
}

/// \fn is_range controleert of *this eruit ziet als het resultaat van vul_range(), d.w.z.
/// dat, voor alle i, (*this)[i]==T(i);
template<class T>
bool Sortvector<T>::is_range() const {
	int i;
	int size = this->size();
	while(i < size && (*this)[i] == i){ // zolang dat i < size en de waarde in this[i] = i
		i++;
	} 
	return (i >= size); // als i < size => false, anders true  
}












