#ifndef __SORTVECTOR
#define __SORTVECTOR

#include <vector>
using std::vector;
template<class T>
class Sortvector : public vector<T> {
	public:
		zoek_k(int k){
			if(k is klein of size()-k is klein){
				zoek_k_klein(k);
			}else{
				zoek_k_groot(k);
			}
		}
	protected:
		zoek_k_klein(int k);
		zoek_k_groot(int k);
};

#endif
