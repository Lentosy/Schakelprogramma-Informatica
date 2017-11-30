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

void verwijder_om_de_drie(set<string> &s);
void print_set(const set<string> &s);


int main(void){
	
	set<string> woorden = { "joyfullest","petrel","dibbles","rock","intimidated","dietetics's","drudge","sleepy","ferrule","washable","incarcerations","samaritans","precarious","patinae","deviants","runaround","seacoast's","biscuit","wm's","tames","extravagances","hairier","vane's","orientation's","gambolled","tannhäuser's","danes","monitoring","tromping","sumo's","soundly","dramas","warhead","understatement","slaphappier","chins","microcomputers","cancun","vermilion","tannery's","twigs","agronomist's","advertisers","subsistence's","unhappiness's","sets","danced","favorably","pratfalls","cottontails"};

	print_set(woorden);
	verwijder_om_de_drie(woorden);
	print_set(woorden);
	return 0;
}

void verwijder_om_de_drie(set<string> &s){
	int index = 0;
	set<string>::iterator it = s.begin();
	while(it != s.end()){
		if(index % 3 == 0){
			
		}
	}


}

void print_set(const set<string> &s){
	set<string>::const_iterator it = s.begin();

	while(it != s.end()){
		cout << *it++ << " - " ;
	}
	cout << endl;
}


