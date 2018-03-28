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
