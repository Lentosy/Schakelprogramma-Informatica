#ifndef __CALCULATOR
#define __CALCULATOR

#include <stack>
#include <iostream>
using std::ostream;
using std::istream;

class Calculator : protected std::stack<unsigned int> {
	public:
		Calculator();
		bool should_stop();
		friend ostream& operator<<(ostream & stream, const Calculator& calculator);
		friend istream& operator>>(istream & stream, Calculator& calculator);
	private:
		void get_two_top_elements(unsigned int &n1, unsigned int &n2);
		/*
		* Removes the top element
		*/
		void clear();
		/*
		* Take the square root of the top element
		*/
		void square_root();
		/*
		* Multiply the top element by 2
		*/
		void power();
		/*
		* Adds the two top elements with each other and place the result on stack
		*/
		void plus();
		/*
		* Subtract the two top elements with each other and place the result on stack
		*/
		void subtract();
		/*
		* Multiply the two top elements with each other and place the result on stack 
		*/
		void multiply();
		/*
		* Divide the two top elements with each other and place the result on stack
		*/
		void divide();
		/*
		* Checks wether or not the calculator should stop asking for input
		*/

		bool stop;
		
};


#endif
