#include "../sudoku.cpp"
#include "../backtrackflex_sudoku.cpp"

int main(void) {
	try {
		Sudoku sudoku("input-04.txt");	

		BacktrackflexSudoku btf;
		btf.setSudoku(sudoku);
		btf.losOp(false);
	
		sudoku.teken("output-04.txt");
	} catch(GraafExceptie ge) {
		std::cout << ge.what();
	}

	return 0;
}
