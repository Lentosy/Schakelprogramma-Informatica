#include <cmath>
#include <iostream>
#include <iomanip>
#include "breuk.h"
using namespace std;

int mijn_ggd(int a, int b){
   	if(a < 0 || b < 0){
        return mijn_ggd(abs(a),abs(b));
   	}
   	if(a < b){
   	    return mijn_ggd(b,a);
   	}
   	if(b == 0){
   	    return a;
   	}
   	return mijn_ggd(b,a%b);
}

void zet_op_gelijke_noemer(Breuk &k, Breuk &h){
	Breuk m = Breuk(k);
	if(k.noemer != h.noemer){
		if((k.noemer < 0 && h.noemer < 0) || (k.noemer > 0 && h.noemer > 0)){
			k.teller *= h.noemer;
			k.noemer *= h.noemer;

			h.teller *= m.noemer;
			h.noemer *= m.noemer;
		}

		if((k.noemer > 0 && h.noemer < 0) || (k.noemer < 0 && h.noemer > 0)){
			k.teller *= (-h.noemer);
			k.noemer *= (-h.noemer);

			h.teller *= (-m.noemer);
			h.noemer *= (-m.noemer);
		}
	};
}

bool is_stambreuk(Breuk b){
	return b.teller == 1;
}

Breuk Breuk::operator+(const Breuk &b) const {
	Breuk k = Breuk(*this);
	Breuk h = Breuk(b);
	zet_op_gelijke_noemer(k, h);
	Breuk res(k.teller + h.teller, k.noemer);
	res.normaliseer();
	return res;
}

Breuk operator+(const Breuk &b, int i){
	return Breuk(b.teller + (b.noemer * i), b.noemer);
}

Breuk operator+(int i, const Breuk &b){
	return b + i;
}

Breuk Breuk::operator-(const Breuk &b) const{
	Breuk k = Breuk(*this);
	Breuk h = Breuk(b);
	zet_op_gelijke_noemer(k, h);
	Breuk res(k.teller - h.teller, k.noemer);
	res.normaliseer();
	return res;
}

Breuk Breuk::operator-() const {
	if(teller > 0 && noemer > 0){
		return Breuk(-teller, noemer);
	}
	if(teller < 0 && noemer > 0){
		return Breuk(-teller, noemer);
	}
	if(teller > 0 && noemer < 0){
		return Breuk(teller, -noemer);
	}
	if(teller < 0 && noemer < 0){
		return Breuk(teller, -noemer);
	}
}

Breuk& Breuk::operator+=(const Breuk &b){
	Breuk k = Breuk(b);
	zet_op_gelijke_noemer(*this, k);
	this->teller += k.teller;
	this->normaliseer();
	return *this;
}

Breuk& Breuk::operator-=(const Breuk &b){
	Breuk k = Breuk(b);
	zet_op_gelijke_noemer(*this, k);
	this->teller -= k.teller;
	this->normaliseer();
	return *this;
}

Breuk& Breuk::operator++(){
	teller += noemer;
	this->normaliseer();
	return *this;
}

Breuk Breuk::operator++(int){
	Breuk b(*this);
	teller += noemer;
	this->normaliseer();
	return b;
}

bool Breuk::operator==(const Breuk &b) const{
	return (this->noemer == b.noemer) && (this->teller == b.teller);
}

bool Breuk::operator!=(const Breuk &b) const{
	return (this->noemer != b.noemer) || (this->teller != b.teller);
}

bool Breuk::operator<(const Breuk &b) const{
	Breuk k = Breuk(*this);
	Breuk h = Breuk(b);
	zet_op_gelijke_noemer(k, h);

	return k.teller < h.teller;
}

ostream& operator<<(ostream &os, const Breuk &b){
	os << b.teller;
	os << "/";
	os << b.noemer;

	return os;
}

istream &operator>>(istream &is, Breuk &b){
	string breuk;
	is >> breuk;
	int slashpos = breuk.find('/');
	cout << slashpos << endl;
	b.teller = stoi(breuk.substr(0, slashpos));
	b.noemer = stoi(breuk.substr(slashpos + 1, breuk.length()));
	return is;
}


void Breuk::normaliseer(){
	int ggd = mijn_ggd(teller, noemer);
	teller /= ggd;
	noemer /= ggd;

	if(teller < 0 && noemer < 0){
		teller = -teller;
		noemer = -noemer;
	}
}
