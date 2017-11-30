#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;



const string FILE_STATION = "/home/bert/Documents/Schakelprogramma-Informatica/Semester 1/Programmeren in C en C++/LABO/txt-bestanden/stationnetje.txt";
const string FILE_PADDESTOEL = "/home/bert/Documents/Schakelprogramma-Informatica/Semester 1/Programmeren in C en C++/LABO/txt-bestanden/paddestoel.txt";
const string FILE_MIX  = "/home/bert/Documents/Schakelprogramma-Informatica/Semester 1/Programmeren in C en C++/LABO/txt-bestanden/mix.txt";


void lees_lijnen(ifstream * files, ofstream &output, int aantal);

int main(){

	int aantal = 2;
	ofstream mix;

	ifstream streams[aantal];
	streams[0].open(FILE_STATION, ios::in);
	streams[1].open(FILE_PADDESTOEL, ios::in);
	mix.open(FILE_MIX, ios::out | ios::app);

	lees_lijnen(streams, mix, aantal);

	for(int i = 0; i < aantal; i++){
		streams[i].close();
	}
	mix.close();
	return 0;
}



void lees_lijnen(ifstream * files, ofstream &output, int aantal){
	string lijnen[10];
	for(int i = 0; i < aantal; i++){
		int j = 0;
		while(!files[i].fail()){
			string s;
			getline(files[i], s);
			if((i + j) % aantal == 0){
				lijnen[j] = s;
			}
			
			j++;
		}
	}

	for(int i = 0; i < 10; i++){
		cout << lijnen[i] << endl;
	}

	cout << endl;
}