#include <memory>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void toon_letter_frequenties(ifstream &file);

const string FILEPATH = "/home/bert/Documents/Schakelprogramma-Informatica/Semester 1/Programmeren in C en C++/LABO/txt-bestanden/lord.txt";
int main(){
	ifstream file;
	file.open(FILEPATH, ios::in);
	if(file.is_open()){
		toon_letter_frequenties(file);
	} 
	file.close();
	return 0;
}


void toon_letter_frequenties(ifstream &file){
	int frequenties[26] = {0};
	char c;
	while(!file.fail()){
		c = file.get();
		if(islower(c)){
			frequenties[c - 'a']++;
		}
	}

	for(int i = 0; i < 26; i++){
		c = i + 'a';
		cout << setw(3) << c;
		cout << " ";
		cout << frequenties[i];
		cout << endl;
	}
}
