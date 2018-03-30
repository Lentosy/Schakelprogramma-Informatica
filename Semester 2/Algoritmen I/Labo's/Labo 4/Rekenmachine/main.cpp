#include <iostream>
#include "mijnstack.cpp"
#include "rekenmachine.cpp"

using std::cout;
using std::cin;
using std::endl;


int main(void){
	cout << "Welcome to Bert's calculator.\n";
	Rekenmachine r; 
	while(!r.should_stop()){
		cout << ":";
		cin >> r;
		cout << endl;
		cout << r << endl;	
		cout << endl;
		cout << "------";
		cout << endl;
	}
	return 0;
}
