#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <map>
#include <iomanip>
#include <string.h>
#include "containers.h"
using namespace std;

void vul_in_zoveelste_map_beeld_van_sleutel_aan_met_set_van_drie(
		vector<map<string, stack<set<string>>>> v, int index_van_map, string sleutel, string eerste, string tweede, string derde);

bool zoveelste_map_beeldt_woord_af_op_stack_waarvan_bovenste_dit_element_bevat(
	vector<map<string, stack<set<string>>>> v,
	int index,
	string woord,
	string element);

int main(void){
	
	vector<map<string, stack<set<string>>>> v(5);

	vul_in_zoveelste_map_beeld_van_sleutel_aan_met_set_van_drie
		(v, 0, "noot", "do", "re", "mi");

	return 0;
}


template<typename T>
void vul_in_zoveelste_map_beeld_van_sleutel_aan_met_set_van_drie(
		vector<map<string, stack<set<string>>>> v, int index_van_map, string sleutel, string eerste, string tweede, string derde){
	
}



