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

#define AANTAL 70

void vul_vector_manueel(vector<map<char, vector<string>>> &v);
void vul_vector_input_redirection(vector<map<char, vector<string>>> &v);
void schrijf_vector(const vector<map<char, vector<string>>> &v);
void schrijf_woorden(const vector<map<char, vector<string>>> &v, char c, int lengte);

int main(void){
	vector<map<char, vector<string>>> vector;
	//vul_vector_manueel(vector);
	vul_vector_input_redirection(vector);

	return 0;
}


void vul_vector_manueel(vector<map< char, vector<string>>> &v){
	v.resize(AANTAL);
	string s;
	while("STOP" != s){
		cin >> s;
		char first = s[0];
		int length = s.length();
		v.at(length)[first].push_back(s);
	}
	cout << "Geef nu een woord in: ";
	cin >> s;
	
}

void vul_vector_input_redirection(vector<map<char, vector<string>>> &v){
	v.resize(AANTAL);
	string s;
	while("STOP" != s){
		cin >> s;
		char first = s[0];
		int length = s.length();
		v.at(length)[first].push_back(s);
	}
    s = "sinterklaas";
	schrijf_woorden(v, s[0], s.length());
}

void schrijf_vector(const vector<map<char, vector<string>>> &v){
	vector<map<char, vector<string>>>::const_iterator itv = v.begin();
	int i = 0;
	while(itv != v.end()){
		cout << "VECTOR " << i << endl;
		map<char, vector<string>> m = *itv;
		map<char, vector<string>>::const_iterator itm = m.begin();
		while(itm != m.end()){
			cout << itm->first;
			cout << " -> ";
			cout << itm->second;
			cout << endl;
			itm++;
			
		}
		itv++;
		i++;
	}
}


void schrijf_woorden(const vector<map<char, vector<string>>> &v, char c, int lengte){
	cout << "Dit zijn woorden met dezelfde lengte en die starten met hetzelfde karakter." << endl;
	map<char, vector<string>> m = v.at(lengte);
	map<char, vector<string>>::const_iterator it = m.begin();
	while(it != m.end()){
		if(it->first == c){
			cout << it->second << endl;
		}


		it++;
	}

}