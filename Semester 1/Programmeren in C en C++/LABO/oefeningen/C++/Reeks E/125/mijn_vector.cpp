#include "mijn_vector.h"
#include <iostream>
#include <iterator>
#include <map>
#include <iomanip>


template<typename T>
void mijn_vector<T>::verdubbel(bool y){
	typename vector<T>::iterator it = (*this).begin();
	if(y){
		while(it != (*this).end()){
			it = (*this).insert(it++, *it);
			it += 2;

		}
	}else{
		while(it != (*this).end()){
			*it = *it * 2;
			it++;
		}			
	}	
}

// vervangt tweeklanken
void vervang(string & woord, const string & oud, const string & nieuw){
    int vindplaats = woord.find(oud);
    while(vindplaats != string::npos){
        string eerste_deel = woord.substr(0,vindplaats);
        string tweede_deel = woord.substr(vindplaats + oud.size());
        woord = eerste_deel + nieuw + tweede_deel;
        vindplaats = woord.find(oud,vindplaats + nieuw.size());
    }
}
// vervangt enkele klinkers, met uitsluiting van tweeklanken (die in 'verboden' map zitten)
void vervang(string & woord, const string & oud, const string & nieuw, const map<string,string> & verboden){
    int vindplaats = woord.find(oud);
    while(vindplaats != string::npos){		
        string tweeklank = woord.substr(vindplaats,2);
        string tweeklank_voordien = "x";
        if(vindplaats!=0){
            tweeklank_voordien = woord.substr(vindplaats-1,2);
        }
        if(verboden.count(tweeklank) == 0 && verboden.count(tweeklank_voordien) == 0){
            string eerste_deel = woord.substr(0,vindplaats);
            string tweede_deel = woord.substr(vindplaats + oud.size());
            woord = eerste_deel + nieuw + tweede_deel;
            vindplaats = woord.find(oud,vindplaats + nieuw.size());
        }
        else{
            vindplaats = woord.find(oud,vindplaats + 5);
        }
    }
}
string p_taal(const string & s){
    map<string,string> verdubbeling1 = {{"aa","aapaa"},{"oe","oepoe"},{"ie","iepie"},{"ij","ijpij"},{"au","aupau"},{"uu","uupuu"},
	                                   {"ei","eipei"},{"ou","oupou"},{"ui","uipui"},{"ee","eepee"},{"eu","eupeu"},{"oo","oopoo"}};
    map<string,string> verdubbeling2 = {{"a","apa"},{"o","opo"},{"i","ipi"},{"y","ypy"},{"u","upu"},{"e","epe"}};
    string dubbel = s;
    map<string,string>::iterator it = verdubbeling1.begin();
    while(it!=verdubbeling1.end()){
        vervang(dubbel,it->first,it->second);
        it++;
    }	
    it = verdubbeling2.begin();
    while(it!=verdubbeling2.end()){
        vervang(dubbel,it->first,it->second,verdubbeling1);
        it++;
    }
    return dubbel;	
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
	out << "[ ";
	typename vector<T>::const_iterator it = v.begin();
	cout << *it++;
	while(it != v.end()){
		out << " - " << *it++;
	}
	out << "]";
	out << endl;
	return out;
}



