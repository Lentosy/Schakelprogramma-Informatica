#include "sortvector.cpp"

#include "sortmethod.h"
#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "sedgewickshellsort.cpp"
#include "tokudashellsort.cpp"
#include "shellshellsort.cpp"
#include "stdsort.cpp"
#include "selectionsort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "countingsort.cpp"
#include "bucketsort.cpp"

#include "sequenceorder.h"
#include "csvdata.h"
#include <ctime>

const int smallest = 10;    // minimum array size for comparing
// (BUG) 1 not allowed because (1 - 1 = 0, used in ShellShellSort). An array of 0 elements cannot exist
const int biggest = 100000;	// maximum array size for comparing, >= 20000 gives stack overflow on quick sort (sorted array)

int main(int argc, char * argv[]) {
	srand(time(0));

	STDSort<int> stdsort;
	InsertionSort<int> isort;
	SedgewickShellSort<int> sedgeshellsort;
	ShellShellSort<int> shellshellsort;
	TokudaShellSort<int> tokudashellsort;
	SelectionSort<int> selectionsort;
	MergeSort<int> mergesort;
	QuickSort<int> quicksort;
	CountingSort<int> countingsort;
	BucketSort<int> bucketsort;
	

	vector<Sortmethod<int>*> sortmethods = {/*&stdsort,
	                                        &isort,
	                                        &tokudashellsort,
	                                        &sedgeshellsort,
	                                        &shellshellsort,
	                                        &selectionsort,
	                                        &mergesort,*/
	                                        //&quicksort,
	                                        &countingsort,
	                                        &bucketsort
	                                       };

	/* Compare each sorting algorithm with different array orders*/

	vector<SequenceOrder>  sequenceOrders = {SequenceOrder::Random, SequenceOrder::Ascending, SequenceOrder::Descending};

	for(SequenceOrder& sequenceOrder : sequenceOrders) {
		Sortmethod<int>::compare(sortmethods, sequenceOrder, smallest, biggest);
	}

}
