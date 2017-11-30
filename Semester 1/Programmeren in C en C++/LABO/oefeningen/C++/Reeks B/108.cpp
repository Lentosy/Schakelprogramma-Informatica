#include <memory>
#include <iostream>
using namespace std;

void schrijf(const string *s, int aantal){
	for(int i = 0; i < aantal - 1; i++){
		cout << s[i] << " - ";
	}
	cout << s[aantal-1];
	cout << endl;
}

void verwijder(string *s, int aantal, int volgnr){
	if(volgnr < aantal){
		for(int i = volgnr; i < aantal - 1; i++){
			s[i] = s[i+1];
		}
	}
}

int main(){
	unique_ptr<string> pnamen[] = {make_unique<string>("Rein"),
								   make_unique<string>("Ada"),
								   make_unique<string>("Eppo")};

	schrijf(pnamen, 3);
	verwijder(pnamen, 3, 0);
	schrijf(pnamen, 3);
	return 0;
}