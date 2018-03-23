#ifndef __CALCULATOR
#define __CALCULATOR

#include <stack>
#include <iostream>
#include <functional>
using std::function;
using std::ostream;
using std::istream;

class Calculator : protected std::stack<unsigned int> {
	public:
		Calculator();
		bool should_stop() const;
		friend ostream& operator<<(ostream & stream, const Calculator& calculator);
		friend istream& operator>>(istream & stream, Calculator& calculator);
	private:
		void clear();
			
		void do_unary_operation(function<unsigned int(unsigned int)> func);
		void square_root();
		void square();
		
		void do_binary_operation(function<unsigned int(unsigned int, unsigned int)> func);
		void plus();
		void subtract();
		void multiply();
		void divide();

		bool stop;
		
};


#endif
