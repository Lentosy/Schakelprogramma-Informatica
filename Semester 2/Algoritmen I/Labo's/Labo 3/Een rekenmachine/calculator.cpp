#include "calculator.h"
#include <stack>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <functional>
using std::ostream;
using std::string;
using std::function;

/* PUBLIC METHODS */

/*
* Default constructor
*/
Calculator::Calculator() : stop(false) { };

/*
* Returns wether or not the stop sign has been given;
*/
bool Calculator::should_stop() const{
	return stop;
}

/*
* Prints the full stack on a single line
*/
ostream& operator<<(ostream & stream, const Calculator & calculator){
	Calculator hulp(calculator); 
	while(!hulp.empty()){
		stream << hulp.top() << " ";
		hulp.clear();
	}
	return stream;
}

/*
* Takes input for the next operation. 
* If the input is a number, it gets pushed on the stack, otherwise the input will be evaluated and matched with the appropriate function
*/
istream& operator>>(istream & stream, Calculator & calculator){
	string input;
	stream >> input;
	unsigned int conv = atoi(input.c_str());
	if(conv != 0){
		calculator.push(conv);
	}else{
		switch(input[0]){
			case '+':
				calculator.plus();
				break;
			case '-':
				calculator.subtract();
				break;
			case '*':
				calculator.multiply();
				break;
			case '/':
				calculator.divide();
				break;
			case 's':
				calculator.square();
				break;
			case 'r':
				calculator.square_root();
				break;
			case 'c':
				calculator.clear();
				break;
			case 'x':
				calculator.stop = true;
				break;
		}
	}
	return stream;
}


/* PRIVATE METHODS */

/*
* Removes the top element
*/
void Calculator::clear(){ 
	pop();
}

/*
* This method executes the unary operation given as a function and adds the result on the stack.
*/
void Calculator::do_unary_operation(function<unsigned int(unsigned int)> func){
	unsigned int n;
	if(!empty() && size() >= 1){
		n = top(); clear();
		push(func(n));
	} 
}

/*
* Replaces the top element with the square root of itself
*/
void Calculator::square_root(){
	do_unary_operation([](unsigned int n){
		return sqrt(n);
	});
}

/*
* Replaces the top element with the square of itself
*/
void Calculator::square(){ 
	do_unary_operation([](unsigned int n){
		return n * n;
	});
}

/*
* This method executes the binary operation given as a function and adds the result on the stack.
*/
void Calculator::do_binary_operation(function<unsigned int(unsigned int, unsigned int)> func){
	unsigned int x;
	unsigned int y;
	if(!empty() && size() >= 2){
		x = top(); clear();
		if(!empty()){
			y = top(); clear();
			push(func(x, y));
		}
	}
}

/*
* Adds the first and second element on the stack together and pushes the result on the stack
*/
void Calculator::plus(){
	do_binary_operation([](unsigned int x, unsigned int y){
		return x + y;
	});
}

/*
* Subtracts the first and second element on the stack together and pushes the result on the stack
*/
void Calculator::subtract(){ 
	do_binary_operation([](unsigned int x, unsigned int y){
		return x - y;
	});
}

/*
* Multiplies the first and second element on the stack together and pushes the result on the stack
*/
void Calculator::multiply(){
	do_binary_operation([](unsigned int x, unsigned int y){
		return x * y;
	});
}

/*
* Divides the first and second element on the stack together and pushes the result on the stack
*/
void Calculator::divide(){ 
	do_binary_operation([](unsigned int x, unsigned int y){
		return x / y;
	});
}



