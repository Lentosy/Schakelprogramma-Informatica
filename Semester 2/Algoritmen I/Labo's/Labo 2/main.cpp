#include "sortvector.cpp"

#include "sorteermethode.h"
#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "sedgewickshellsort.cpp"
#include "shellshellsort.cpp"
#include "stdsort.cpp"

#include "volgorde.h"
#include "csvdata.h"
#include <ctime>



const int kleinste = 10;     // minimum voor meet functie 
							 // -> (BUG) 1 niet toegelaten want (1 - 1 = 0), kan geen array aanmaken van 0 elementen 
							 // dit gebeurt bij ShellShellSort
const int grootste = 100000; // maximum voor meet functie

int main(int argc, char * argv[]) {

	srand(time(0));

	InsertionSort<int> isort;
	SedgewickShellSort<int> sedgeshellsort;
	ShellShellSort<int> shellshellsort;
	STDSort<int> stdsort;
	
	vector<Sorteermethode<int>*> sorteermethodes = {&isort, &sedgeshellsort, &shellshellsort, &stdsort};
	/* Elk sorteeralgoritme in sorteermethode met elkaar vergelijken voor verschillende volgordes */
	vector<Volgorde> volgordes = {Volgorde::Random, Volgorde::Stijgend, Volgorde::Dalend};
	
	for(Volgorde& v : volgordes){
		Sorteermethode<int>::vergelijk(sorteermethodes, v, kleinste, grootste);
	}
		
}
