#ifndef BREUK_H
#define BREUK_H

#include <iostream>
#include <iomanip>
using namespace std;
class Breuk{
	public:
		/* CONSTRUCTORS */
		Breuk(int t = 1, int n = 1) : teller(t), noemer(n) {normaliseer();};
		Breuk(const Breuk &b) : Breuk(b.teller, b.noemer) {};

		/* OPERATORS */
		Breuk operator+(const Breuk &) const;
		friend Breuk operator+(const Breuk &, int);
		friend Breuk operator+(int, const Breuk &);
		Breuk operator-(const Breuk &) const;
		Breuk operator-() const;
		Breuk& operator+=(const Breuk &);
		Breuk& operator-=(const Breuk &);
		Breuk& operator++();
		Breuk operator++(int);
		bool operator==(const Breuk &) const;
		bool operator!=(const Breuk &) const;
		bool operator<(const Breuk &) const;
		friend ostream& operator<<(ostream &, const Breuk &);
		friend istream& operator>>(istream &, Breuk &);

	private:
		int teller;
		int noemer;
		void normaliseer();
		friend void zet_op_gelijke_noemer(Breuk &, Breuk &);	
		friend bool is_stambreuk(Breuk);	
};

#endif