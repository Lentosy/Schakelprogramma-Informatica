#include "../sudoku.cpp"
#include "../backtrackflex.h"


int main(void){
	Sudoku sudoku("input-04.txt");
	sudoku.schrijf(std::cout);
	
	
	Backtrackflex btf;
	return 0;
}
