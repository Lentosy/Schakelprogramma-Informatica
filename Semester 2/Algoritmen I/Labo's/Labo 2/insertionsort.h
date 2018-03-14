#ifndef __INSERTIONSORT
#define __INSERTIONSORT
#include "sortvector.h"
#include "sorteermethode.h"

/** class Insertionsort
    \brief implementeert insertion sort
*/

template <typename T>
class InsertionSort : public Sorteermethode<T> {
    public: void operator()(vector<T> & v) const;
};

#endif
