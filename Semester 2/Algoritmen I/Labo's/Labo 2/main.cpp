#include "sortvector.cpp"

#include "sortmethod.h"
#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "sedgewickshellsort.cpp"
#include "shellshellsort.cpp"
#include "stdsort.cpp"

#include "sequenceorder.h"
#include "csvdata.h"
#include <ctime>

const int smallest = 10;    // minimum array size for comparing
							// (BUG) 1 not allowed because (1 - 1 = 0, used in ShellShellSort). An array of 0 elements cannot exist
const int biggest = 10000;	// maximum array size for comparing

int main(int argc, char * argv[]) {

	srand(time(0));

	STDSort<int> stdsort;
	InsertionSort<int> isort;
	SedgewickShellSort<int> sedgeshellsort;
	ShellShellSort<int> shellshellsort;
	
	vector<Sortmethod<int>*> sortmethods = {&stdsort, &isort, &sedgeshellsort, &shellshellsort};
	
	/* Compare each sorting algorithm with different array orders*/
	vector<SequenceOrder>  sequenceOrders = {SequenceOrder::Random, SequenceOrder::Ascending, SequenceOrder::Descending};
	
	for(SequenceOrder& sequenceOrder : sequenceOrders){
		Sortmethod<int>::compare(sortmethods, sequenceOrder, smallest, biggest);
	}
		
}
