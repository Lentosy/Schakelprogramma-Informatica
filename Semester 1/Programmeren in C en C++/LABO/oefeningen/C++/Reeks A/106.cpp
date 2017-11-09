#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Persoon{
	string naam;
	int leeftijd;   // leeftijd in jaar
	int lengte; // lengte in centimeter
};

template <typename T>
T grootste (T array[], int lengte);

void initialiseer(Persoon &p, string naam, int leeftijd, int lengte);
void print(Persoon p);

int main(void){
	double getallen[5] = {5.5, 7.7, 2.2, 9.9, 9.8};
	string woorden[3] = {"geloof", "hoop", "de liefde"};
	Persoon samuel;
	Persoon jente;
	Persoon idris;
	initialiseer(samuel, "Samuel", 12, 152);
	initialiseer(jente, "Jente", 22, 181);
	initialiseer(idris, "Idris", 42, 173);
	Persoon personen[3] = {samuel, jente, idris};

	cout << grootste(getallen, 5) << endl;
	cout << "De grootste van de drie is " << grootste(woorden, 3) << "." << endl;
	//todo grootste persoon
	return 0;
}

template <typename T>
T grootste (T array[], int lengte){
	T max = array[0];
	for(int i = 1; i < lengte; i++){
		if(max < array[i]){
			max = array[i];
		}
	}
	return max;
}

void initialiseer(Persoon &p, string naam, int leeftijd, int lengte){
	p.naam = naam;
	p.leeftijd = leeftijd;
	p.lengte = lengte;
}

void print(Persoon p){
	int centimeter = p.lengte % 100;
	int meter = (p.lengte - centimeter ) / 100;

	cout << "Naam: " << p.naam 
	<< " (" << p.leeftijd << ", " 
	<< meter << "m" << centimeter << ")" 
	<< endl;
}