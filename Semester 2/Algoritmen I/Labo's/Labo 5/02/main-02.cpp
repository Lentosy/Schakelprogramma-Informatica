#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../graaf.cpp"
#include "../sudoku.cpp"

int main(void){
	Sudoku sudoku("input-02.txt");
	sudoku.genereerOutput("output-02.txt");
	return 0;
}
