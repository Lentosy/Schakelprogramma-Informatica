#ifndef __SUDOKU_H
#define __SUDOKU_H
#include "graaf.h"


class Sudoku : public GraafMetKnoopdata<RichtType::ONGERICHT, int> {
	public:
		Sudoku();
		Sudoku(const char * filename);
		
		// set een bepaald getal op een vakje.
		// argument is pair waarbij paar->first de index is, en pair->second het getal dat moet 
		// geplaatst worden i
		void setWaardeVoorVakje(const std::pair<int, int>& paar);
		
		// geeft het aantal lege velden (velden met waarde = 0) terug
		int geefAantalLegeVelden() const;
		
		// geeft index van het eerste lege vakje (van links naar rechts) terug
		int geefIndexVanVolgendLeegVakje() const;
		
		// controleert of de sudoku zich in een opgeloste staat bevindt.
		bool isGeldig() const;
	
		// geeft een pointer naar een vector terug dat alle mogelijkheden bevat voor een bepaald vakje.
		std::vector<int>* geefmogelijkhedenVoor(int i) const;
	
	
	private:
		void leesBestand(const char *);
		void maakConnecties();
		void maakRijConnecties(int);
		void maakKolomConnecties(int);
		void maakMatrixConnecties(int);
};
#endif
