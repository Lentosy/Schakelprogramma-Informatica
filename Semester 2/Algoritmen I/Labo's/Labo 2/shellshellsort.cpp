#include "shellsort.h"
#include <algorithm>
using namespace std;

template<class T>
class ShellShellSort : public ShellSort<T> {
	public:
		void operator()(vector<T> & v) const {
			// n/2, n/4, n/8, ..., 2, 1 [altijd resultaat flooren]
			int size = v.size();
			vector<int> increments;
			while(size > 1) {
				size = floor(size / 2);
				increments.push_back(size);
			}

			reverse(begin(increments), end(increments));

			int series[size];

			for(int i = 0; i < increments.size(); i++) {
				series[i] = increments[i];
			}

			shell_sort(v, series, size);
		}
};
