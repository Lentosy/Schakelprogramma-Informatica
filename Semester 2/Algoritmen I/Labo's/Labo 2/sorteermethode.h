#ifndef __SORTEERMETHODE
#define __SORTEERMETHODE
#include "sortvector.h"
#include "chrono.h"
#include <iostream>
#include <iomanip>
using std::move;
using std::swap;
using std::endl;
using std::cout;
using std::setw;
#include <algorithm>

/** class Sorteermethode
    \brief abstracte klasse van methodes die een vector sorteren
*/
template <typename T>
class Sorteermethode {
	public:
/// \fn operator() sorteert de vector gegeven door het argument
		virtual void operator()(vector<T> & v) const = 0;

/// \fn meet(int kortste, int langste, ostream& os) schrijft naar os een overzicht (met de nodige ornamenten)
/// met de snelheid van de opgegeven sorteermethode *this. Er wordt 1 lijn uitgedrukt voor elke mogelijke
/// grootte. Deze groottes zijn kleinste, 10*kleinste, 100*kleinste,
/// enzovoorts, tot aan grootste.
/// Op een lijn staat de snelheid van de methode toegepast op
/// (1) een random tabel
/// (2) een al gesorteerde tabel.
/// (3) een omgekeerd gesorteerde tabel.

/// Deze functie werkt alleen als T een toekenning van een int toelaat,
/// zodat bv.
///    T a=5;
/// geldig is.
		void meet(const int kortste, const int langste, ostream& os) {
			Chrono klok;
			const int kolombreedte=12;
			int tabelgrootte=kortste;
			os<<setw(kolombreedte)<<"lengte"
			  <<setw(kolombreedte)<<"random"
			  <<setw(kolombreedte)<<"gesorteerd"
			  <<setw(kolombreedte)<<"omgekeerd"
			  <<"\n";
			while (tabelgrootte <= langste) {
				os<<setw(kolombreedte)<<tabelgrootte;
				Sortvector<T> sv(tabelgrootte);//random volgorde
				klok.start();
				operator()(sv);
				klok.stop();
				os<<setw(kolombreedte)<<klok.tijd();
				klok.start();
				operator()(sv);
				klok.stop();
				os<<setw(kolombreedte)<<klok.tijd();
				sv.draai_om();
				klok.start();
				operator()(sv);
				klok.stop();
				os<<setw(kolombreedte)<<klok.tijd();
				os<<"\n";
				tabelgrootte*=10;
			}
		};



};
#endif
