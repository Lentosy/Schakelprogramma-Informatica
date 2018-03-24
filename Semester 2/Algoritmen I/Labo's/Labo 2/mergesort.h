#ifndef __MERGESORT
#define __MERGESORT

/** class MergeSort
    \brief implements Merge Sort
*/

template <class T>
class MergeSort : public Sortmethod<T> {
    public: 
		void operator()(vector<T> & v) const;
		string get_name() const;
		void merge_sort(vector<T> v, int l, int r, vector<T> h) const;
};




#endif
