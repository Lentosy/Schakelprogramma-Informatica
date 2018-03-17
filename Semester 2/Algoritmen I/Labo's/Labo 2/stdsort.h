#ifndef __STDSORT
#define __STDSORT
#include "sortmethod.h"

/** class Klasse die std::sort uitvoert maar compatibel met Sorteermethode */
template<class T>
class STDSort : public Sortmethod<T> {
	public:
		void operator()(vector<T> & v) const;
		string getName() const;	
};

#endif
