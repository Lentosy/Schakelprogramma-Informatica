#include "graaf.h"


class Sudoku : public GraafMetKnoopdata<RichtType::ONGERICHT, int> {
	public:
		Sudoku(const char *);
		bool isGeldig() const;
	private:
		void leesBestand(const char *);
		
		void maakConnecties();
		void maakRijConnecties(int);
		void maakKolomConnecties(int);
		void maakMatrixConnecties(int);
};
