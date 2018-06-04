#ifndef __COUNTING_SORT
#define __COUNTING_SORT

#include "sortmethod.h"


template<class T>
class CountingSort : public Sortmethod<T> {
	public:
		void operator()(std::vector<T>& v) const;
		string get_name() const;
	private:
		int find_max(std::vector<T>& v) const;

};

#endif
