#include <iostream>
#include "doublesmap.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;


/*
* Adds an unsigned int with its double to the map. 
*/
void DoublesMap::add(unsigned int i){
	insert({i, i * 2});	
}

/*
* Checks wether or not a double exist
*  1. Get the last added key
*  2. Check if any of the first n values are smaller than the value of last_key, if so the half of the values do not exist and we erase them from the map
*  3. Now check if the first_value is equal to the last_key, if yes: first_value / 2 (the original number in the file) has a double. Also remove this from the map
*  
*  See uitwerking.png for visual
*
*  Examples 	 map 1		   	 map 2
*				10 : 20		  	20 : 40	
*				11 : 22			22 : 44
*				12 : 24			45 : 90
*				13 : 26
*				14 : 28
*				15 : 30
*				20 : 40
*
*	for map 1: The key '20' is equal to the first value '20', the number 10 has a double in the file, the entry '10 : 20' also gets removed from the map
*	for map 2: The key '45' is bigger than '40' and '44', both these entries need to be removed and have no double in the file
*/
bool DoublesMap::check_doubles(){	
	bool result = false;
	// 1.
		// reverse iterator to get the last key (no need to iterate but i need to get the element somehow)
	reverse_iterator it_key = rbegin();
	unsigned int last_key = it_key->first;
	if(last_key % 2 == 0){
		// normal iterator to get all the values smaller than last_key
		iterator it_val = begin();
	
		// 2.
			// get all the values that are smaller than last_key and remove these as they have no doubles
		if (last_key > it_val->second){ 
			while(it_val != end() && it_val->second < last_key){
				erase(it_val);
				it_val++;
			}
		}
		
		// 3.
			// reset value iterator to beginning
		it_val = begin();
		unsigned int first_value = it_val->second;
		if(last_key == first_value){
			erase(it_val);
			result = true; // at last, there exists a double
		}
	}
	
	return result;

}

/*
* Prints the current content of the map
*/
ostream& operator<<(ostream & stream, DoublesMap & doublesMap){
	cout << "printing map..." << endl;
	for(auto const & it : doublesMap){
		cout << it.first << " : " << it.second << endl;
	}

}
