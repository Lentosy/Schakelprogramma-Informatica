#ifndef __SHELLSORT
#define __SHELLSORT
#include "sortvector.h"
#include "sorteermethode.h"

/** class ShellSort
    \brief implementeert Shell Sort
*/

template <typename T>
class ShellSort : public Sorteermethode<T> {
	public:
		virtual void operator()(vector<T> & v) const = 0;
};

#endif
