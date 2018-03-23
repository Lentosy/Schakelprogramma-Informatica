#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "chrono.cpp"

// use doublesqueue instead of doublesmap as it is more efficient (thx Xandro)
#include "doublesmap.cpp"
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
	DoublesMap container;
	unsigned int number; // variable to hold a single number in the file
	
	/* Read data */
	Chrono clock;
	clock.start();
	while(data >> number{
		container.add(number);
		if(container.check_doubles()){
			cout << number  << endl;
		}
	}
	clock.stop();
	cout << "Total time: " << clock.time() << " seconds" << endl;
	data.close(); 	
	

  
	return 0;
}
