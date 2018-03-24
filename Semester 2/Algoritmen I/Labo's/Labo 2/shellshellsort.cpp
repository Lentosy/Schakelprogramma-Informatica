#include "shellsort.h"

/** class ShellShellSort
*	\brief Een implementatie van ShellSort dat gebruik maakt van de Shell reeks
*/
template<class T>
class ShellShellSort : public ShellSort<T> {
	public:
		void operator()(vector<T> & v) const {
			//FLOOR [ N / 2^k ]
			vector<int> vhulp;
			int n = v.size();
			
			while(n > 1){
				n = floor(n / 2);
				vhulp.push_back(n);
			}
			
			int size = vhulp.size();
			int series[size - 1]; // indien size = 1, dan runtime error, dus geen size 1 pls

			for(int i = size - 1; i >= 0; i--){ // add in reverse order
				series[size - i] = vhulp[i];
			}
	
			
			shell_sort(v, series, size);
	
		}
		
		string get_name() const{
			return "Shell Shell Sort";
		}
};



