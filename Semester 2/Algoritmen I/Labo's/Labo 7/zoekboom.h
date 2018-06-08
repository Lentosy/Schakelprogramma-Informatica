#ifndef __ZOEKBOOM_H
#define __ZOEKBOOM_H

#include <iostream>   // voor test/debugfase
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
#include <fstream>
using std::ostream;
using std::istream;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
#include <sstream>
#include <cassert>
template <class T>
class Knoop;

/**********************************************************************

 Class: Zoekboom

 beschrijving: Binaire zoekboom voor sleutels zonder data.
 Duplicaten of even grote elementen zijn niet toegestaan.

 ***************************************************************************/

template <class T>
class Zoekboom: protected unique_ptr<Knoop<T> > {
		using unique_ptr<Knoop<T> >::unique_ptr;
	public:
		Zoekboom(const Zoekboom &) = delete;
		Zoekboom(Zoekboom &&);
		Zoekboom& operator=(const Zoekboom<T> &) = delete;
		Zoekboom& operator=(Zoekboom<T> &&);


		bool voegToe(const T & sl);  // return false indien sl al aanwezig was in de boom
		Zoekboom<T>* zoek(const T &sl);

		int maxDiepte()const;      // to do
		int gemiddeldeDiepteiepte()const;      // to do

		//teken tekent de zoekboom in het .dotformaat naar het opgegeven bestand
		void teken(const char * bestandsnaam);
		friend ostream& operator<<(ostream & out, const Zoekboom<T> & b) {
			b.schrijf(out);
			out<<" X";
			return out;
		}
		
	protected:
		//hulpfunctie voor teken. Mag alleen opgeroepen worden voor niet-lege deelboom.
		string tekenrec(ostream& uit,int&nullteller);
		void schrijf(ostream & out) const;  // zal inorder uitschrijven;
		// enkel sleutels (zelfs zonder linker/rechterkind -
		// best aan te passen als je structuur wil controleren!)
		// hier nog zonder iterator geimplementeerd
		//teken tekent de boom in een .dot-bestand

		
};

//________________________________________________________________

template <class T>
class Knoop {

		friend class Zoekboom<T>;

	public:
		Knoop(const T & sl):sleutel(sl) {};

	private:
		const T sleutel;
		Zoekboom<T> links,rechts;

};

//////////////////////////////////////////////////////////////////
/////////   GEGEVEN IMPLEMENTATIE                    /////////////

template <class T>
Zoekboom<T>::Zoekboom(Zoekboom && ander):unique_ptr<Knoop<T> >(move(ander)) {
	cout<<" --moveconstructor-- " << endl;
}

template <class T>
Zoekboom<T>& Zoekboom<T>::operator=(Zoekboom<T> && ander) {
	unique_ptr<Knoop<T> >::operator=(move(ander));
	return *this;
}

template <class T>
void Zoekboom<T>::schrijf(ostream & out) const {
	if(*this != nullptr) {
		this->get()->links.schrijf(out);
		out<<this->get()->sleutel<<" ";
		this->get()->rechts.schrijf(out);
	}
}

template <class T>
void Zoekboom<T>::teken(const char * bestandsnaam) {
	//schrijf ookdoen:
	cout << "LETS DRAW BOYS\n";
	this->schrijf(cout);

	std::ofstream uit(bestandsnaam);
	assert(uit);
	int nullteller=0;//nullknopen moeten een eigen nummer krijgen.
	uit<<"digraph {\n";
	if (!*this)
		uit<<"null01 [shape=point];\n";
	else
		tekenrec(uit,nullteller);
	uit<<"}";
};

template <class T>
string Zoekboom<T>::tekenrec(ostream& uit,int&nullteller) {
	std::ostringstream wortelstring;//noot: wortelstring geeft identificatie van de knoop
	//als geen duplicaten zijn toegestaan is de sleutelwaarde oke.
	wortelstring<<'"'<<(*this)->sleutel<<'"';
	uit<<wortelstring.str()<<"[label=\""<<(*this)->sleutel<<"\"]";
	uit<<";\n";
	//een dummylinkerkind moet getekend worden als er geen linker- maar wel een rechterkind is
	string linkskind, rechtskind;
	if (!(*this)->links) {
		std::ostringstream dummy;
		dummy<<"null"<<++nullteller;
		uit<<dummy.str()<<" [ label=dummy style=invis];\n";
		//        dummy<<" [ style=invis ]";
		linkskind=dummy.str();
	} else
		linkskind=(*this)->links.tekenrec(uit,nullteller);
	if (!(*this)->rechts) {
		std::ostringstream dummy;
		dummy<<"null"<<++nullteller;
		uit<<dummy.str()<<" [ label=dummy style=invis];\n";
		//        dummy<<" [ style=invis ]";
		rechtskind=dummy.str();
		//        uit<<rechtskind<<" [shape=point, style=invis];\n";
	} else
		rechtskind=(*this)->rechts.tekenrec(uit,nullteller);
	if((*this)->links || (*this)->rechts) { //bij blad geen dummykinderen tekenen
		uit << wortelstring.str()<<" -> "<<linkskind<<";\n";
		uit << wortelstring.str()<<" -> "<<rechtskind<<";\n";
	};
	return wortelstring.str();
};

///////////////////////////////////////////////////////////////////////////////
//////////////////////AANGEVULDE IMPLEMENTATIE/////////////////////////////////
template<class T>
bool Zoekboom<T>::voegToe(const T &sl) {
	std::cout << "waar loopt het mis";
	Zoekboom<T>* knoopptr = this->zoek(sl);

	return true;
	/* Zoekboom<T>* pointerToNext = this->zoek(sl);
	 if (*pointerToNext == nullptr || (*pointerToNext)->sleutel != sl) {
	     *pointerToNext = Zoekboom(new Knoop<T>(sl));
	     cout << "adding " << sl << endl;
	     return true;
	 }
	 cout << "adding " << sl << " not valid" << endl;
	 return false;*/
	// Feedback: iets mis met zoekfunctie
}

template<class T>
Zoekboom<T>* Zoekboom<T>::zoek(const T& sl) {
	
	if((this) != nullptr && (*this)->sleutel == sl){
		return (this);
	}
	if(sl < (*this)->sleutel) return (*this)->links.zoek(sl);
	
	return (*this)->rechts.zoek(sl);
}



#endif

