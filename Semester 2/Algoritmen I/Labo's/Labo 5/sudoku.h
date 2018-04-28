#ifndef __SUDOKU_H
#define __SUDOKU_H
#include "graaf.h"


class Sudoku : private GraafMetKnoopdata<RichtType::ONGERICHT, int> {
	public:
		Sudoku();
		Sudoku(const char *);
		bool isGeldig() const;
		int geefAantalLegeVelden() const;
	private:
		void leesBestand(const char *);
		void maakConnecties();
		void maakRijConnecties(int);
		void maakKolomConnecties(int);
		void maakMatrixConnecties(int);
};
#endif
