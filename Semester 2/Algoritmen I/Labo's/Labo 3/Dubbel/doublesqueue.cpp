#include "doublesqueue.h"


void DoublesQueue::add(unsigned int x) {
	push(x);
}

bool DoublesQueue::check_doubles() {
	bool result = false;
	unsigned int to_check = back();
	if(to_check % 2 == 0){
		unsigned int element = front();
		unsigned int half = to_check / 2;
		while(element < half){
			pop();
			element = front();
		}
		
		if(element == half){
			result = true;
		}
	}
	return result;
}

