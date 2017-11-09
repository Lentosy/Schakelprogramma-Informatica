#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define AANTAL 6
#define LEN 5

string genereer_string(int aantal);
void vul_array_met_strings(string array[], int aantal, int len);
void bepaal_min_en_max(const string array[], int aantal, string &min, string &max);
void print_array(const string array[], int aantal);
void print_min_en_max(string min, string max);

int main(void){
	string array[AANTAL];
	vul_array_met_strings(array, AANTAL, LEN);
	
	string min;
	string max;

	bepaal_min_en_max(array, AANTAL, min, max);

	print_array(array, AANTAL);
	print_min_en_max(min, max);

	return 0;
}

string genereer_string(int aantal){
	string s = "";	
	if(aantal < 0){
		return s;
	}
	for(int i = 0; i < aantal; i++){
		char r = 'a' + (rand() % 26);
		s += r;
	}

	return s;
}

void vul_array_met_strings(string array[], int aantal, int len){

	for(int i = 0; i < aantal; i++){
		array[i] = genereer_string(len);
	}
}

void bepaal_min_en_max(const string array[], int aantal, string &min, string &max){
	min = array[0];
	max = array[0];
	for(int i = 1; i < aantal; i++){
		if(array[i].compare(min) < 0){ // woord is kleiner dan min
			min = array[i];
		}else if(array[i].compare(max) > 0){ // woord is groter dan max
			max = array[i];
		}
	}
}

void print_array(const string array[], int aantal){
	cout << "Array met " << aantal << " woorden van " << LEN << " karakters: ";
	for(int i = 0; i < aantal - 1 ; i++){
		cout << array[i] << ", ";
	}
	cout << array[aantal - 1];
	cout << endl;
}

void print_min_en_max(string min, string max){
	cout << "Het kleinste woord is " << min << endl;
	cout << "Het grootste woord is " << max << endl;
}