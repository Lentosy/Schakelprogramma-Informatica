#include "calculator.h"
#include <stack>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
using std::ostream;
using std::string;

/* PUBLIC METHODS */
Calculator::Calculator() : stop(false) { };

bool Calculator::should_stop(){
	return stop;
}

ostream& operator<<(ostream & stream, const Calculator& calculator){
	Calculator hulp(calculator); 
	while(!hulp.empty()){
		stream << hulp.top() << " ";
		hulp.clear();
	}
	return stream;
}

istream& operator>>(istream & stream, Calculator & calculator){
	string input;
	stream >> input;
	int conv = atoi(input.c_str());
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
				calculator.power();
				break;
			case 'v':
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
void Calculator::get_two_top_elements(unsigned int &n1, unsigned int &n2){
	n1 = top();
	clear();
	n2 = top();
	clear();
}

void Calculator::clear(){ 
	pop();
}

void Calculator::square_root(){
	unsigned int n = top();
	clear();
	push(sqrt(n));
}

void Calculator::power(){ 
	unsigned int n = top();
	clear();
	push(n * n);
}

void Calculator::plus(){ 
	unsigned int n1, n2;
	get_two_top_elements(n1, n2);
	push(n1 + n2);
}

void Calculator::subtract(){ 
	unsigned int n1, n2;
	get_two_top_elements(n1, n2);
	push(n1 - n2);
}

void Calculator::multiply(){
	unsigned int n1, n2;
	get_two_top_elements(n1, n2);
	push(n1 * n2);
}

void Calculator::divide(){ 
	unsigned int n1, n2;
	get_two_top_elements(n1, n2);
	push(n1 / n2);
}



