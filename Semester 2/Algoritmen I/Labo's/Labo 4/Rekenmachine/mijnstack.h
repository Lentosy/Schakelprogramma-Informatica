#ifndef __MIJNSTACK
#define __MIJNSTACK

#include <vector>
#include <iostream>
using std::vector;
using std::ostream;



template<class T>
class Mijnstack : public vector <T> {
	public:
		T & top();
		void push(T waarde);
		void pop();
		
		template<class U>
		friend ostream & operator<<(ostream & out, Mijnstack<U> & ms);
};

#endif
