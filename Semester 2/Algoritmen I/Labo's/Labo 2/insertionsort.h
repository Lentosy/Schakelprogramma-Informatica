#ifndef __INSERTIONSORT
#define __INSERTIONSORT
#include "sortvector.h"
#include "sorteermethode.h"

/** class Insertionsort
    \brief implementeert Insertion Sort
*/

template <class T>
class InsertionSort : public Sorteermethode<T> {
    public: 
		void operator()(vector<T> & v) const;
		string getName() const;
    
};

#endif
