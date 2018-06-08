#include "../sudoku.cpp"

int main(void){
	Sudoku s("input-03.txt");

	if(s.isGeldig()){
		std::cout << "Geldig\n";
	}
	return 0;
}
