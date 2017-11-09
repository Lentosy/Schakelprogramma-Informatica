#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


void schrijf(int array[], int aantal, bool achterstevoren = false, char tussenteken = ' ');

int main(void){
	int t[] = {1, 3, 5, 7, 9, 11, 13};
	schrijf(t, 7);
	schrijf(t, 7, true);
	schrijf(t, 7, false, '-');
	schrijf(t, 7, true, '-');
	return 0;
}

void schrijf(int array[], int aantal, bool achterstevoren, char tussenteken){
	if(achterstevoren){
		cout << array[aantal - 1];
		for(int i = aantal - 2; i >= 0; i --){
			cout << tussenteken;
			cout << array[i];
		}
	}else{
		cout << array[0];
		for(int i = 1; i < aantal; i++){
			cout << tussenteken;
			cout << array[i];
		}
	}
	cout << endl;
}