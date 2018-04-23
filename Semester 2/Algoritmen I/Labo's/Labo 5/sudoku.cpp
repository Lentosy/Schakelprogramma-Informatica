#include "sudoku.h"
#include "graaf.cpp"
#include <iostream>
#include <vector>
#include <fstream>

/*
* Default constructor. De bestandsnaam moet een sudoku voorstellen (9 x 9 matrix met getallen)
*/
Sudoku::Sudoku(const char * filename){
	leesBestand(filename);
	maakConnecties();
}

/*
* Controleert of de sudoku een geldige oplossing bevat. Indien dit niet het geval is zal deze functie zeggen waar de fouten zitten.
*/
bool Sudoku::isGeldig() const{
	bool isGeldig = true;
	//per knoop checken ofdat er andere knopen zijn die verbonden zijn met deze knoop ofdat ze dezelfde waarde hebben
	for(int i = 0; i < aantalKnopen(); i++){
		int huidigeWaarde = knoopdatavector[i]; // de waarde van het vakje dat we aan het bekijken zijn
		// alle knopen vergelijken die met de huidige knoop verbonden zijn en controleren op duplicate waarden
		std::map<int, int>::const_iterator it = knopen[i].begin();
		while(it != knopen[i].end()){
			if(huidigeWaarde == knoopdatavector[it->first]){
				isGeldig = false;
				std::cout << "Fout gevonden: index=" << i << "  gevonden waarde=" <<knoopdatavector[it->first] << std::endl;
			}
			it++;
		}   		
	}	
	return isGeldig;
}

/*
* Leest het bestand en maakt voeg de knoop toe aan de graaf
*/
void Sudoku::leesBestand(const char * filename){
	std::ifstream input(filename);	
	int x;	
	while(input >> x){
		voegKnoopToe(x);
	}
	input.close();
}

/*
* Deze functie maakt verbindingen met elke knoop die niet dezelfde waarde als deze knoop
*/
void Sudoku::maakConnecties(){
	for(int i = 0; i < 9; i++){
		maakRijConnecties(i * 9);
	}
	
	for(int i = 0; i < 9; i++){
		maakKolomConnecties(i);
	}
	
	int indices[] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
	for(int i : indices){
		maakMatrixConnecties(i);
	}
}
/*
* Connecties maken op rij
*/
void Sudoku::maakRijConnecties(int i){
	for(int j = i; j < i + 9; j++){ // j = [i, i + 9]
		for(int k = j + 1; k < i + 9; k++){ // k = [j + 1, i + 9]
			voegVerbindingToe(j, k);
		}
	}
}

/*
* Connecties maken op kolom
*/
void Sudoku::maakKolomConnecties(int i){
	for(int j = i; j < 81; j += 9){
		for(int k = j + 9; k < 81; k+= 9){
			voegVerbindingToe(j, k);
		}
	}	
}

/*
* Positieve modulo ( -1 % 3 = 2)
*/
int mod(int a, int b){
	int r = a % b;
	if(r < 0){
		r += b;
	}
	return r;
}

/*
* Connecties maken op de submatrices (3X3)
*/
void Sudoku::maakMatrixConnecties(int i){
	
	std::vector<int> indices_to_connect = {  i     , i + 1 , i + 2 , 
										     i + 9 , i + 10, i + 11, 
										     i + 18, i + 19, i + 20};

	/* 
		Connect the top row with the 2 x 2 matrices that doesnt contain the row and column the node at index j is in
		e.g.
			0 	1	2
			3	4	5
			6	7	8
			
		When j = 0, connect 0 to 4, 5, 7 and 8
		when j = 2, connect 2 to 3, 4, 6 and 7
	
	*/
	for(int j = 0; j < 3; j++){
		int l = mod(j - 1, 3); // left row
		int r = mod(j + 1, 3); // right row
		for(int k = 1; k < 3; k++){
			voegVerbindingToe(indices_to_connect[j], indices_to_connect[r + (k * 3)]);
			voegVerbindingToe(indices_to_connect[j], indices_to_connect[l + (k * 3)]);
		}
	}

	/*
		Connect the second row with the 1 x 1 matrices that doesnt contain the row and column the nade at index j is in.
		e.g.
			0 	1	2
			3	4	5
			6	7	8
			
		When j = 3, connect 3 with 7 and 8
		when j = 5, connect 5 with 6 and 7
	*/
	for(int j = 3; j < 6; j++){
		int l = mod(j - 1, 3); // left row
		int r = mod(j + 1, 3); // right row
		
		voegVerbindingToe(indices_to_connect[j], indices_to_connect[r + 6]);		
		voegVerbindingToe(indices_to_connect[j], indices_to_connect[l + 6]);
	}
}





