#ifndef __SHELLSORT
#define __SHELLSORT
#include "sortvector.h"
#include "sorteermethode.h"

/** class Abstracte klasse voor Shell Sort. De implementaties van deze klasse maken gebruik van een specifieke reeks
    \brief implementeert Shell Sort
*/
template <typename T>
class ShellSort : public Sorteermethode<T> {
	public:
		virtual void operator()(vector<T> & v) const = 0;
		virtual string getName() const = 0;
};

#endif
