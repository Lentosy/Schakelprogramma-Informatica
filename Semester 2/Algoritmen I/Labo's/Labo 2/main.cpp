#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "sortvector.cpp"
#include "sedgewickshellsort.cpp"
#include "shellshellsort.cpp"
#include "csvdata.h"
#include <algorithm>
#include <ctime>
using namespace std;

const int n = 10000; // aantal elementen


const int kortste = 1    ; // minimum voor meet functie
const int langste = 10000; // maximum voor meet functie

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

	Sortvector<int> sv(n);
	sv.vul_random_zonder_dubbels();

	/* INSERTION SORT */
	InsertionSort<int> isort;
	cout << "INSERTION SORT" << endl;
	isort.meet(kortste, langste, cout);

	/* SEDGEWICK SHELL SORT */
	SedgewickShellSort<int> sedgeshellsort;
	cout << "SEDGEWICK SHELL SORT" << endl;
	sedgeshellsort.meet(kortste, langste, cout);

	/* SHELL SHELL SORT*/
	ShellShellSort<int> shellshellsort;
	cout << "SHELL SHELL SORT" << endl;
	shellshellsort.meet(kortste, langste, cout);

}



