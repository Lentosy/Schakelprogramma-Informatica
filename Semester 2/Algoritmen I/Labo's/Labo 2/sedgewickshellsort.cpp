#include "shellsort.h"

/** class SedgewickShellSort
*	\brief Een implementatie van ShellSort dat gebruik maakt van de Sedgewick reeks
*/
template<class T>
class SedgewickShellSort : public ShellSort<T> {
		void operator()(vector<int> &v) const {

			int series[]= {1,5,19,41,109,209,505,929,2161,3905,8929,16001,36289,64769,146305,260609,587521,
			               1045505,2354689,4188161,9427969,16764929,37730305,67084289,150958081,268386305,603906049,
			               1073643521
			              };
			int size = 28;

			shell_sort(v, series, size);

		}
		
		string get_name() const{
			return "Sedgewick Shell Sort";
		}
};


