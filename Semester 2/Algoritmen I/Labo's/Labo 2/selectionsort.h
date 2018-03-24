#ifndef __SELECTIONSORT
#define __SELECTIONSORT

/** class SelectionSort
    \brief implements Selection Sort
*/

template <class T>
class SelectionSort : public Sortmethod<T> {
    public: 
		void operator()(vector<T> & v) const;
		string get_name() const;
};




#endif
