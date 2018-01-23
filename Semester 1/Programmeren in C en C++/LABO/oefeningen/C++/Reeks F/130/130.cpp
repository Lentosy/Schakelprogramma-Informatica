#include "figuren.h"
#include <memory>
#include <fstream>
#include <iomanip>
#include <string>

class Blokkendoos : vector<unique_ptr<Figuur>>{
	private :
		unique_ptr<Figuur> max_opp;
		void schrijf(ostream &) const;
	public:
		Blokkendoos();
		Blokkendoos(const string & bestandsnaam);
		unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
		void push_back(unique_ptr<Figuur>&& figuur);

		friend ostream& operator<< (ostream& out, const Blokkendoos & b){
			b.schrijf(out);
			return out;
		}
};

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte(){

	// zoek index van de grootste in de array
	int volgendegrootste = 0;
	for(int i = 1 ; i < size(); i ++){
		if((*this)[i]->oppervlakte() > (*this)[volgendegrootste]->oppervlakte()){
			volgendegrootste = i;
		}
	}	

	// zet grootste figuur helemaal achteraan in de vector zodat
	(*this)[volgendegrootste].swap((*this)[size() - 1]);
	unique_ptr<Figuur> hulpptr;
	// de figuur in max_opp verwisselen met de waarde in hulpptr(NULL)
	hulpptr.swap(max_opp);
	// verplaats het laatste element(het grootste) naar max_opp
	max_opp.swap((*this)[size() - 1]);
	// resizen is nu geen probleem
	resize(size() - 1);
	return move(hulpptr);
}

void Blokkendoos::push_back(unique_ptr<Figuur> && figuur){
	if(max_opp == nullptr){
		max_opp = move(figuur);
	}else{
		vector<unique_ptr<Figuur>>::push_back(move(figuur));
		if(max_opp->oppervlakte() < ((*this)[size() - 1])->oppervlakte()){
			max_opp.swap(operator[](size() - 1));
		}
	}
}

void Blokkendoos::schrijf(ostream& out) const{
	for(int i = 0; i < size(); i++){
		cout << *(operator[](i)) << endl;
	}
}

Blokkendoos::Blokkendoos(){}
Blokkendoos::Blokkendoos(const string & bestandsnaam){
	ifstream stream;
	stream.open(bestandsnaam, ios::in);
	if(!stream){
		throw string(bestandsnaam + " kon niet geopend worden\n");
	}
	string soort;
	stream >> soort;
	while(!stream.fail()){
		if(soort == "rechthoek"){
			double lengte, breedte;
			stream >> lengte >> breedte;
			push_back(make_unique<Rechthoek>(Rechthoek(lengte, breedte)));
		}else if(soort == "cirkel"){
			int straal;
			stream >> straal;
			push_back(make_unique<Cirkel>(Cirkel(straal)));
		}else if(soort == "vierkant"){
			double zijde;
			stream >> zijde;
			push_back(make_unique<Vierkant>(Vierkant(zijde)));
		}else {
			string c;
			getline(stream, c);
		}

		stream >> soort;		
	}
	stream.close();
}

int main(){
	try{
		Blokkendoos blokkendoos("figuren.txt");

	
	cout << endl << "ALLE FIGUREN: ";
	
	cout << blokkendoos << endl;
	
	
	cout << endl << "DE 3 GROOTSTE, van groot naar klein: " << endl;
	for(int i = 0; i < 3; i ++){
		cout << " figuur met grootste opp: "<< *blokkendoos.geef_figuur_met_grootste_oppervlakte() << endl;
	}

	cout << endl << "DE NIEUWE BLOKKENDOOS BEVAT DEZE 3 NIET MEER: ";
	cout << blokkendoos << endl;
	}catch(const string s){
		cout << s;
	}
	

}