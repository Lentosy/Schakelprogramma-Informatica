#include <iostream>
#include <fstream>
#include <string>
#include <queue>

// use doublesqueue instead of doublesmap as it is more efficient (thx Xandro)
// #include "doublesmap.cpp" R I P
#include "doublesqueue.cpp"


using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;

using std::string;
using std::ios;

const string FILENAME = "dubbels.dat";
const int MAX_LINES = 1000000;


/*
* This program looks for doubles in a given file (if 10 and 20 exist in the file, 10 has a double)
*/
int main() {
	/* Open file in read mode */
	ifstream data(FILENAME.c_str(), ios::in);
	if(!data.is_open()){
		cerr << "Could not open file: " << FILENAME;
		return -1;
	}
	
	/* Variabele setup */
	DoublesQueue doublesQueue;
	unsigned int number; // variable to hold a single number in the file
		
	/* Read data */
	while(data >> number){
		doublesQueue.add(number);
		if(doublesQueue.check_doubles()){
			cout << number / 2 << endl;
		}
	}
    
	data.close();   
	return 0;
}
