#ifndef __SORTEERMETHODE
#define __SORTEERMETHODE
#include "chrono.h"
#include "sequenceorder.h"
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
using std::logic_error;
/** class Sorteermethode
    \brief abstracte klasse van methodes die een vector sorteren
*/
template <class T>
class Sortmethod {
	public:
/// \fn operator() sorteert de vector gegeven door het argument
		virtual void operator()(vector<T> & v) const = 0;
		/**
		* Geeft de naam van de sorteermethode terug
		*/
		virtual string get_name() const = 0;

		/**
		* Deze static functie zal verschillende sorteermethodes vergelijken op basis van de volgorde. De volgorde heeft drie mogelijke waarden:
		*	- Random
		*	- Stijgend
		*	- Dalend
		*
		* Verder worden er tabellen aangemaakt met verschillende grootte.
		* De functie begint met een arraysize 'kleinste' en blijft vergelijkingen uitvoeren tot de limit 'grootste' bereikt is met sprongen van (* 10).
		*
		* \param[in] sorteermethodes	Een vector van verschillende sorteermethodes
		* \param[in] volgorde			De volgorde van de vector die gesorteerd zal worden
		* \param[in] kleinste 			De kleinste arraysize
		* \param[in] grootste           De limiet van de arraysize
		*/
		static void compare(vector<Sortmethod<T>*> &sortmethods, SequenceOrder sequenceOrder, const int smallest, const int biggest) {
			const int columnwidth=20;

			printSequenceOrder(sequenceOrder);
			printHeaderRow(smallest, biggest, columnwidth); /* Naam algoritme    10    100    1000 ...... */
			
			for(int i = 0; i < sortmethods.size(); i ++) {
				try {
					Chrono klok;
					Sortmethod<T> * sortmethod = sortmethods[i];
					cout << "\t";
					/* OUTPUT */ cout << setw(columnwidth) <<  sortmethod->get_name();
					int arraysize = smallest;
					while(arraysize <= biggest) {
						// geen switch nodig voor random aangezien we toch sowieso de
						// default constructor moeten aanroepen (die de elementen random plaatst)
						Sortvector<int> sv(arraysize);
						switch(sequenceOrder) {
							case 1: {
								sv.vul_range();
								break;
							}
							case 2: {
								sv.vul_omgekeerd();
								break;
							}
						}

						/* sorteermethode tijdsregistratie */
						klok.start();
						sortmethod->operator()(sv);
						klok.stop();
						if(sv.is_gesorteerd()){
							/* OUTPUT */ cout << setw(columnwidth / 2) << klok.tijd();
							
						} else {
							/* OUTPUt */ cout << setw(columnwidth / 2) << "N.S.";
						}

						
						arraysize *= 10;
					} // end while
					/* OUTPUT */ cout << endl;
				} catch(logic_error e) {
					cout << setw(20) << e.what() << endl;
				}
			} // end for
			/* OUTPUT */ cout << endl;
		};
	private:
		static void printSequenceOrder(SequenceOrder sequenceOrder) {
			switch(sequenceOrder) {
				case 0:
					cout << "RANDOM SEQUENCE" << endl;
					break;
				case 1:
					cout << "ASCENDING SEQUENCE (SORTED)" << endl;
					break;
				case 2:
					cout << "DESCENDING SEQUENCE (INVERSE SORTED)" << endl;
					break;
			}
		};

		static void printHeaderRow(const int smallest, const int biggest, const int columnwidth) {
			cout << "\t";
			cout << setw(columnwidth) << "Name of algorithm";
			int arraysize = smallest;
			while(arraysize <= biggest) {
				cout << setw(columnwidth / 2) << arraysize;
				arraysize *= 10;
			}
			cout << endl;

			cout << "\t";
			for(int i = 0; i < columnwidth; i++) {
				cout << "-";
			}
			arraysize = smallest;
			while(arraysize <= biggest) {
				for(int i = 0;  i < columnwidth/ 2; i++) {
					cout << "-";
				}
				arraysize *= 10;
			}
			cout << endl;
		};
};


#endif
