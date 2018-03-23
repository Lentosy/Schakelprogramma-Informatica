#ifndef __DOUBLEMAP
#define __DOUBLEMAP

#include <map>
using std::map;
using std::ostream;

/*
* This class inherits from map. 
* They key is an unsigned int which exists in the file, the value is the double value of the key
*/
class DoublesMap : public map<unsigned int, unsigned int> {
	public:
		void add(unsigned int);
		bool check_doubles();
		friend ostream& operator<<(ostream &out, const DoublesMap & doublesMap);
};


#endif

