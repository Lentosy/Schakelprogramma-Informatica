#ifndef __BACKTRACKFLEX_SUDOKU_H
#define __BACKTRACKFLEX_SUDOKU_H
#include <stdio.h>
#include "backtrackflex.h"
#include "sudoku.h"

/*
* Bij backtrackflex<int> : 
* Een deeloplossing: ik heb een aantal lege vakjes, er zijn 5 ingevuld, deeloplossing bevat deze 5 getallen.
*
* bv sudoku met 4 vakjes:
*		[3][4]
*		[7][ ]
* deeloplossing = {3, 4, 7}
*
* Betere manier, behou ook de plaats van de vakjes in de deeloplossing, dus backtrackflex<pair<int, int>>
*
*/

class BacktrackflexSudoku : public Backtrackflex<std::pair<int, int>> {
	public:
	    BacktrackflexSudoku();
		void setSudoku(Sudoku& s);
	protected:
	    bool controle();
	    void verwerk();
	    vector<std::pair<int, int>>& geefVerdere();
	private:
		Sudoku sudoku;
		int lengteVanDeDeeloplossing; // De deeloplossing moet uiteindelijk deze lengte hebben
};
#endif
