#ifndef __DOUBLESQUEUE
#define __DOUBLESQUEUE

#include <queue>

using std::queue;
using std::ostream;

class DoublesQueue : protected queue<unsigned int> {
	public:
		void add(unsigned int);
		bool check_doubles();
};

#endif



