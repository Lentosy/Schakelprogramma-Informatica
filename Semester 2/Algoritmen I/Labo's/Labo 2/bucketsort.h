
#ifndef __BUCKET_SORT
#define __BUCKET_SORT

#include "sortmethod.h"


template<class T>
class BucketSort : public Sortmethod<T> {
	public:
		void operator()(std::vector<T>& v) const;
		string get_name() const;
	private:
		int find_max(std::vector<T>& v) const;

};

#endif
