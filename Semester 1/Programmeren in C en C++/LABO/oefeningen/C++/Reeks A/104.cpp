#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
	char k = 'y';
	string w = "";
	w += k;
	cout << "karakter " << k << " omgezet: " << w << "." << endl;

	char c = 'x';
	string s = "" + c;
	cout << "karakter " << c << " omgezet: " << s << "." << endl;
	return 0;
}