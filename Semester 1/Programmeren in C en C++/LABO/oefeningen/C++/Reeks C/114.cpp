#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <map>
#include <iomanip>
#include "containers.h"
using namespace std;

#define AANTAL 5

void oef01(void);
void oef02(void);
void oef03(void);

int main(void){
	oef01();
	oef02();
	oef03();
}


void oef01(void){
	stack<string> s;
	s.push("een");
	s.push("twee");
	s.push("drie");
	cout << s;
	cout << s;
}


void oef02(void){
	vector<string> v[AANTAL];
	v[1].push_back("aap");
	v[1].push_back("noot");
	v[1].push_back("mies");

	cout << v[1];
}


void oef03(void){
	vector<vector<int>> v;
	v.resize(AANTAL);
	for(int i = 0; i < AANTAL; i++){
		v.at(i).resize(i);
		v.at(i).clear();
		for(int j = 0; j < i; j++){
			v.at(i).push_back(10 * j);
		}
	}

	for(int i = 0; i < AANTAL; i++){
		vector<int>::reverse_iterator it = v[i].rbegin();
		if(!v[i].empty()){
			cout << *it++ << " ";
		}
		cout << endl;
	}

}