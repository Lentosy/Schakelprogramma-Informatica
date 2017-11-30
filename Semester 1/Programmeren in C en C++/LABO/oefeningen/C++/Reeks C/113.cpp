#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <map>
#include <iomanip>
using namespace std;


template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
	out << "[ ";
	typename vector<T>::const_iterator it = v.begin();
	out << *it++;
	while(it != v.end()){
		out << " | " << *it++;
	}
	out << " ]";
	out << endl;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T> &s){
	out << "{ ";
	typename set<T>::const_iterator it = s.begin();
	out << *it++;
	while(it != s.end()){
		out  << " , " << *it++;
	}
	out << " }";
	out << endl;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, stack<T> s){
	while(!s.empty()){
		out << s.top();
		out << endl;
		s.pop();
	}
	return out;
}

template<typename T, typename K>
ostream& operator<<(ostream& out, map<T, K> &m){
	typename map<T, K>::const_iterator it = m.begin();
	while(it != m.end()){
		out << it->first;
		out << " -> ";
		out << it->second;
		out << endl;
		it++;
		
	}
	return out;
}








int main(void){
	cout << "Vector : ";
	vector<int> v = {0, 1};
	cout << v;

	cout << "Set    : ";
	set<int> set = {0, 1};
	cout << set;

	cout << "Stack  : ";
	stack<int> stack;
	stack.push(0);
	stack.push(1);
	cout << stack;

	cout << "Map    : ";
	map<char, int> map;
	map['A'] = 0;
	map['B'] = 1;
	cout << map;

	cout << endl;
	return 0;
}




