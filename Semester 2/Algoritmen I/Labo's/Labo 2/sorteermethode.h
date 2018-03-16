#ifndef __SORTEERMETHODE
#define __SORTEERMETHODE
#include "sortvector.h"
#include "chrono.h"
#include "volgorde.h"
#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <algorithm>
using std::move;
using std::swap;
using std::endl;
using std::cout;
using std::setw;
using std::string;

/** class Sorteermethode
    \brief abstracte klasse van methodes die een vector sorteren
*/
template <typename T>
class Sorteermethode {
	public:
/// \fn operator() sorteert de vector gegeven door het argument
		virtual void operator()(vector<T> & v) const = 0;
		/**
		* Geeft de naam van de sorteermethode terug
		*/
		virtual string getName() const = 0;

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

		/**
		* Deze static functie zal verschillende sorteermethodes vergelijken op basis van de volgorde. De volgorde heeft drie mogelijke waarden:
		*	- Random
		*	- Stijgend
		*	- Dalend
		*
		* Verder worden er tabellen aangemaakt met verschillende grootte.
		* De functie begint met een tabelgrootte 'kleinste' en blijft vergelijkingen uitvoeren tot de limit 'grootste' bereikt is met sprongen van (* 10).
		*
		* \param[in] sorteermethodes	Een vector van verschillende sorteermethodes
		* \param[in] volgorde			De volgorde van de vector die gesorteerd zal worden
		* \param[in] kleinste 			De kleinste tabelgrootte
		* \param[in] grootste           De limiet van de tabelgrootte
		*/
		static void vergelijk(vector<Sorteermethode<int>*> &sorteermethodes, Volgorde volgorde, const int kleinste, const int grootste) {
			
			switch(volgorde){
				case 0: cout << "RANDOM VOLGORDE" << endl; break;
				case 1: cout << "STIJGENDE VOLGORDE (GESORTEERD)" << endl; break;
				case 2: cout << "DALENDE VOLGORDE (OMGEKEERD GESORTEERD)" << endl; break;
			}
				
			Chrono klok;
			const int naamkolombreedte=20;
			const int kolombreedte = 12;
			/* OUTPUT */ cout << setw(naamkolombreedte) << "Naam algoritme";
			int tabelgrootte = kleinste;
			while(tabelgrootte <= grootste){
				/* OUTPUT */ cout << setw(kolombreedte) << tabelgrootte;
				tabelgrootte *= 10;
			}
			/* OUTPUT */ cout << endl;
			
			
			for(int i = 0; i < sorteermethodes.size(); i++) {
				Sorteermethode<T>* sorteermethode = sorteermethodes[i];			
				/* OUTPUT */ cout << setw(naamkolombreedte) <<  sorteermethode->getName();
				tabelgrootte = kleinste;
				while(tabelgrootte <= grootste) {
						
					// geen switch nodig voor random aangezien we toch sowieso de default constructor moeten aanroepen (die de elementen random plaatst)
					Sortvector<int> sv(tabelgrootte); 
					switch(volgorde) {
						case 1: // STIJGEND
							{
								sv.vul_range();						
							}
							break;
						case 2: // DALEND
							{
								sv.vul_omgekeerd();
							}
							break;
					}
					
					klok.start();
					sorteermethode->operator()(sv);
					klok.stop();
					cout << setw(kolombreedte) << klok.tijd();
					tabelgrootte *= 10;
				}
				/* OUTPUT */ cout << endl;
			}
			/* OUTPUT */ cout << endl;
		}
};


#endif
