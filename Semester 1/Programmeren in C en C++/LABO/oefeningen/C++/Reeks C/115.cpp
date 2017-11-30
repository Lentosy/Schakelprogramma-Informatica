#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <map>
#include <iomanip>
#include <string.h>
#include "containers.h"
using namespace std;

int main(void){
	map<char, vector<string>> mapwoorden;
	string s;

	cout << "Geef woorden in. Eindig met STOP" << endl;
	while("STOP" != s){
		cin >> s;
		char first = s[0];
		mapwoorden[first].push_back(s);
	}

	cout << "Geef nu een letter in : ";
	char c;
	cin >> c;
	cout << mapwoorden[c].size() << " woorden gevonden die beginnen met een " << c << endl;
	cout << mapwoorden[c];
	
}


