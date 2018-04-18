#include "graaf.h"


class Sudoku : private GraafMetKnoopdata<RichtType::ONGERICHT, int> {
	public:
		Sudoku(const char *);
		void genereerOutput(const char *) const;
		bool isGeldig() const;
	private:
		void leesBestand(const char *);
		
		void maakConnecties();
		void maakRijConnecties(int);
		void maakKolomConnecties(int);
		void maakMatrixConnecties(int);
};
