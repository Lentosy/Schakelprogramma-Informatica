#include "../sudoku.cpp"
#include "../backtrackflex_sudoku.cpp"

int main(void) {
	try {
		Sudoku sudoku("input-04.txt");
		BacktrackflexSudoku btf;
		btf.setSudoku(sudoku);
		// volgende lijn pas oproepen indien geefVerdere geïmplementeerd is
		btf.losOp(false);
	} catch(GraafExceptie ge) {
		std::cout << ge.what();
	}

	return 0;
}
