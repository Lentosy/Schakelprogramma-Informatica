#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "doublesmap.cpp"

using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;

using std::string;
using std::ios;

const string FILENAME = "dubbels.dat";
const int MAX_LINES = 1000000;


/*
* This program looks for doubles in a given file
*/
int main() {
	/* Open file in read mode */
	ifstream data(FILENAME.c_str(), ios::in);
	if(!data.is_open()){
		cerr << "Could not open file: " << FILENAME;
		return -1;
	}
	
	/* Variabele setup */
	DoublesMap doublesMap;
	unsigned int number; // The number at the current linenum
	int linenum = 0;   // the linenumber of the current number
	int max = MAX_LINES;     // max amount of linenums you wish to read
	
	/* Read data */
	while(!data.fail() && linenum < max){
		data >> number;
		doublesMap.add(number);
	//	cout << doublesMap; FOR DEBUGGING
		doublesMap.check_doubles();
		linenum++;
	}
    
	data.close();   
	return 0;
}
