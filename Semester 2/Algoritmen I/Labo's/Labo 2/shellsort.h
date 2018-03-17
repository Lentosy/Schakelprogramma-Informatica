#ifndef __SHELLSORT
#define __SHELLSORT
#include "sortmethod.h"

/** class Abstract class for Shell Sort. The different implementaties use different series
    \brief implements Shell Sort
*/
template <class T>
class ShellSort : public Sortmethod<T> {
	public:
		virtual void operator()(vector<T> & v) const = 0;
		virtual string getName() const = 0;
		void shell_sort(vector<T> & v, int series[], int size) const;
};

#endif
