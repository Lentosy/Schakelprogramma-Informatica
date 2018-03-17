#ifndef __STDSORT
#define __STDSORT
#include "sorteermethode.h"

/** class Klasse die std::sort uitvoert maar compatibel met Sorteermethode */
template<class T>
class STDSort : public Sorteermethode<T> {
	public:
		void operator()(vector<T> & v) const;
		string getName() const;	
};

#endif
