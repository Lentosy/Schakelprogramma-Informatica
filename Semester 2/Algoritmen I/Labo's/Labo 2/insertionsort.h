#ifndef __INSERTIONSORT
#define __INSERTIONSORT
#include "sortmethod.h"

/** class Insertionsort
    \brief implements Insertion Sort
*/

template <class T>
class InsertionSort : public Sortmethod<T> {
    public: 
		void operator()(vector<T> & v) const;
		string get_name() const;
};

#endif
