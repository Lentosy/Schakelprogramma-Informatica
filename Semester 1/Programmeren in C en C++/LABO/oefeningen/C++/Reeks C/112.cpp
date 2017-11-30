#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct persoon persoon;
struct persoon{
	string naam;
	int leeftijd;
};

template<typename T>
void schrijf(vector<T> &v);



int main(void){
	vector<int> v1 = {0, 1, 2, 3, 4, 5, 6};
	schrijf(v1);
	vector<string> v2 = {"Tekst", "Woord", "Vectoren"};
	schrijf(v2);
	vector<double> v3 = {1.32, 1.14, 8.47, -9.7, 1.111111};
	schrijf(v3);
	vector<char> v4 = {'c', 'h', 'a', 'r'};
	schrijf(v4);
	vector<bool> v5 = {true, false, false, false, true, true, false};
	schrijf(v5);
	persoon p;
	p.leeftijd = 22;
	p.naam = "Bert";
	vector<persoon> v6 = { p };
	schrijf(v6);
	return 0;
}

ostream& operator<< (ostream& out, const persoon &p){
	out << p.naam << " (" << p.leeftijd << " j)";
	return out;
}

template<typename T>
void schrijf(vector<T> &v){
	cout << "[ ";
	for(int i = 0; i < v.size() - 1; i++){
		cout <<  v[i] << " | ";
	}
	cout << v.back();
	cout << " ]";
	cout << endl;
}