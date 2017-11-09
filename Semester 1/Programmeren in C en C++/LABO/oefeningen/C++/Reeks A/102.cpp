#include <iostream>
#include <iomanip>
using namespace std;

#define COUNT 64

int main(void){
	
	for(int i = 1; i <= COUNT; i++){
		cout << std::dec << i << " ";
		cout << std::hex << i << " ";
		cout << std::oct << i << " ";
		cout << "\n";
	}
	
	cout << "START\n";
	return 0;
}