#ifndef __QUICKSORT
#define __QUICKSORT

/** class QuickSort
    \brief implements Quick Sort
*/

template <class T>
class QuickSort : public Sortmethod<T> {
    public: 
		void operator()(vector<T> & v) const;
		string get_name() const;
	private:
		void quick_sort(vector<T> & v, int l, int r) const;

};




#endif
