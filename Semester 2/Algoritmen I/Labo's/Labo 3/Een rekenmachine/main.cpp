#include <stack>
#include <iostream>

#include "calculator.cpp"
using std::cout;
using std::cin;
using std::endl;

int main(void){
	Calculator calculator;
	while(!calculator.should_stop()){
		cout << ":";
		cin >> calculator;
		cout << endl << calculator << endl;
		cout << "------" << endl;

	}
	
	return 0;
}

