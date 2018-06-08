#include <iostream>
using std::cout;
using std::cerr;
#include <fstream>
using std::ifstream;
using std::ios;
#include <string>
using std::string;

// use doublesqueue instead of doublesmap as it is more efficient (thx Xandro)
#include "doublesmap.cpp"
#include "doublesqueue.cpp"
#include "chrono.cpp"

const string FILENAME = "dubbels.dat";

/*
* This program looks for doubles in a given file (if 10 and 20 exist in the file, 20 is the double of 10, and we print 20)
*/
int main() {
	/* Open file in read mode */
	ifstream data(FILENAME.c_str(), ios::in);
	if(!data.is_open()){
		cerr << "Could not open file: " << FILENAME;
		return -1;
	}
		
	/* Variabele setup */
	DoublesQueue container;
	unsigned int number; // variable to hold a single number in the file
	Chrono clock;
	
	/* Read data */
	clock.start();
	while(data >> number){
		container.add(number);
		if(container.check_doubles()){
			cout << number << "\n";
		}
	}
	clock.stop();
	cout << "Total time: " << clock.time() << " seconds\n";
	data.close(); 	
	

  
	return 0;
}

