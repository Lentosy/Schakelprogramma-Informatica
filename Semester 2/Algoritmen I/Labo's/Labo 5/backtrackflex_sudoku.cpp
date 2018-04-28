#include <iostream>
#include <vector>
#include <fstream>
#include "backtrackflex_sudoku.h"


// Constructor
BacktrackflexSudoku::BacktrackflexSudoku() {}


/*
* Geeft de volgende deeloplosing terug
*/
vector<std::pair<int, int>>& BacktrackflexSudoku::geefVerdere(){

}

/*
* Schrijft de deeloplossing uit in volgend formaat {x1:y1, x2:y2, ..., xn:yn}
* met xn de index van een vakje en yn de waarde die op dat vakje moet komen
*/
void BacktrackflexSudoku::verwerk(){
	std::cout << "De huidige deeloplossing is: {";
	std::vector<const std::pair<int, int>*>::const_iterator iterator = deeloplossing.begin();
	while(iterator != deeloplossing.end()){
		const std::pair<int, int> * p = *iterator++;
		std::cout << p->first << ":" << p->second << ", ";
	}
	std::cout << "}\n";	
}

/*
* Controleert of de deeloplossing volledig is
*/
bool BacktrackflexSudoku::controle(){
	return lengteVanDeDeeloplossing == deeloplossing.size();
}

void BacktrackflexSudoku::setSudoku(Sudoku& s){
	this->sudoku = s;
	lengteVanDeDeeloplossing = s.geefAantalLegeVelden();
}




