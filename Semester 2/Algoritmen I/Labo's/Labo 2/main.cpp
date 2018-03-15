#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "sortvector.cpp"
#include "sedgewickshellsort.cpp"
#include "shellshellsort.cpp"
#include "sorteermethode.h"
#include "volgorde.h"
#include "csvdata.h"
#include <ctime>
using namespace std;

const int kleinste = 10;     // minimum voor meet functie -> (BUG) 1 niet toegelaten want (1 - 1 = 0), kan geen array aanmaken van 0 elementen
const int grootste = 100000; // maximum voor meet functie


template<class T>
void is_gesorteerd(Sortvector<T> & v) {
	if(v.is_gesorteerd()) {
		cout << "het is gesorteerd" << endl;
	} else {
		cout << "het is niet gesorteerd" << endl;
	}
}

int main(int argc, char * argv[]) {

	srand(time(0));

	InsertionSort<int> isort;
	SedgewickShellSort<int> sedgeshellsort;
	ShellShellSort<int> shellshellsort;
	
	vector<Sorteermethode<int>*> s = {&isort, &sedgeshellsort, &shellshellsort};
	vector<Volgorde> volgordes = {Volgorde::Random, Volgorde::Stijgend, Volgorde::Dalend};
	/* Elk sorteeralgoritme in sorteermethode met elkaar vergelijken voor verschillende volgordes */
	for(int i = 0; i < volgordes.size(); i++){
		Sorteermethode<int>::vergelijk(s, volgordes[i], kleinste, grootste);
	}
	
	
}



