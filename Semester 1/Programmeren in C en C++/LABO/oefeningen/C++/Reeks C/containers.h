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




