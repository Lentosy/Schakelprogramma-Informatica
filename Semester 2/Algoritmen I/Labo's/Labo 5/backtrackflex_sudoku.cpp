#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "backtrackflex_sudoku.h"


// Constructor
BacktrackflexSudoku::BacktrackflexSudoku() {}



// vult de sudoku op met het nieuwe element
// overschrijft de methode voegToeAanDeeloplossing in de normale klasse Backtrackflex
void BacktrackflexSudoku::voegToeAanDeeloplossing(const std::pair<int, int>& element) {
	this->sudoku.setWaardeVoorVakje(element);
	this->laatstOpgevuldeElement = element;
	deeloplossing.push_back(&element);
}

// zet het laatste opgevulde element terug op 0
// overschrijft de methode verwijderUitDeeloplossing in de normale klasse Backtrackflex
void BacktrackflexSudoku::verwijderUitDeeloplossing() {
	this->sudoku.setWaardeVoorVakje(laatstOpgevuldeElement);
	deeloplossing.resize(deeloplossing.size() - 1);
}


// Geeft de volgende deeloplosing terug
std::vector<std::pair<int, int>>& BacktrackflexSudoku::geefVerdere(){
	
	int volgendLeegVakje = this->sudoku.geefIndexVanVolgendLeegVakje();
	std::vector<int>* mogelijkheden = this->sudoku.geefmogelijkhedenVoor(volgendLeegVakje);

	//volgende lijnen zijn vrij inefficiënt, kan beter voor zorgen dat geefmogelijkhedenVoor() een vector<pair<int, int>> terruggeeft
	// maar da ligt nie in de scope van de sudoku klasse imo
	std::vector<std::pair<int, int>> * mogelijkhedenparen = new std::vector<std::pair<int, int>>(mogelijkheden->size());
	for(int i = 0; i < mogelijkheden->size(); i++){
		const std::pair<int, int> paar (volgendLeegVakje, mogelijkheden->operator[](i));
		mogelijkhedenparen->push_back(paar);
	}
	
	return *mogelijkhedenparen;
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
	lengteVanDeDeeloplossing = this->sudoku.geefAantalLegeVelden();
}




