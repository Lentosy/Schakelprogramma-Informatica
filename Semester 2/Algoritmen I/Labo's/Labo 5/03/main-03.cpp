#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../graaf.cpp"
#include "../sudoku.cpp"

int main(void){
	Sudoku s("input-03.txt");
	s.genereerOutput("output-03.txt");
	return 0;
}
