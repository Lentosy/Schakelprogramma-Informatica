#ifndef __KALENDER
#define __KALENDER

#include <memory>
#include <vector>
using std::vector;
class Taak {
	public:
		Taak();
		Taak(const Taak&);
		Taak(Taak&&);
		Taak& operator=(const Taak&);
		Taak& operator==(const Taak&&);
};

class Takenlijst : public std::unique_ptr<vector<Taak>> {

};

class Vrijetijd {
	public:
		Vrijetijd();
		Vrijetijd(const Vrijetijd&);
		Vrijetijd(Vrijetijd&&);
		Vrijetijd& operator=(const Vrijetijd&);
		Vrijetijd& operator==(const Vrijetijd&&);
};

class Dag {
	public:
		enum Soort { vrijetijd, werkdag, gemengd };
		Soort deSoort;
		std::unique_ptr<Takenlijst> deTakenlijst;
		std::unique_ptr<Vrijetijd> deVrijetijd;
};

#endif



unique_ptr<T> var1(new T);
var1->blabla;

// p heeft een attribuut van type T*

unique_ptr<T> var2(var1) // gaat niet
unique_ptr<T> var3;
var3 = var1; // gaat niet

var3 = std::move(var1); //gaat wel, kunt ook swap gebruiken. Eindresultaat is dat var3 nu da attribuut van type T* heeft, en var1 heeft niets meer