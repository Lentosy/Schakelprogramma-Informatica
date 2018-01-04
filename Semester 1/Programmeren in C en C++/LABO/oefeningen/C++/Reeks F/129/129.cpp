#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "bestand_niet_lang_genoeg.h"
using namespace std;

string regel_uit_bestand(string bestandsnaam, int volgnr){
	ifstream stream;
	stream.open(bestandsnaam, ios::in);
	if(!stream){
		throw string(bestandsnaam + " kon niet geopend worden\n");
	}
	string lijn;
	getline(stream, lijn);
	if(lijn.compare(0, 7, "VERHAAL")){
		throw bestandsnaam.c_str();	
	}

	int huidigelijn = 1;
	while(!stream.fail()){
		getline(stream, lijn);
		if(huidigelijn == volgnr){
			cout << lijn;
		}
		huidigelijn ++;

	}

	if(huidigelijn < volgnr){
		throw bestand_niet_lang_genoeg(bestandsnaam);
	}


}

int main(){
	vector<string> bestandsnamen({"niks","een","twee","drie","vier",
	"vijf","zes","zeven","acht","negen","tien","elf","twaalf"});
	vector<int> nrs({8,5,2,10,7,3,8,4,1,1,6,2,4});

	string bestanden_niet_gevonden = "";
	string bestanden_niet_lang_genoeg = "";
	string bestanden_zonder_woord_verhaal = "";
	string eerste_woorden = "";
	for(int i=0; i<bestandsnamen.size(); i++){
		try{
			cout << regel_uit_bestand(bestandsnamen[i]+".txt",nrs[i]) << endl;
		}catch(const string s){
			bestanden_niet_gevonden += s;
			bestanden_niet_gevonden += " ";
		}catch(const char *s){
			bestanden_zonder_woord_verhaal += s;
			bestanden_zonder_woord_verhaal += " ";
		}catch(const bestand_niet_lang_genoeg b){
			bestanden_niet_lang_genoeg += b.what();
			bestanden_niet_lang_genoeg += " ";
		}
		catch(...){
	
		}

		
	}
	cout<<endl<<endl<<"BESTANDEN NIET GEVONDEN:"<<endl;
	cout<<bestanden_niet_gevonden;
	cout<<endl<<"BESTANDEN NIET LANG GENOEG:"<<endl;
	cout<<bestanden_niet_lang_genoeg<<endl;
	cout<<endl<<"BESTANDEN ZONDER STARTWOORD  VERHAAL :"<<endl;
	cout<<bestanden_zonder_woord_verhaal<<endl;
	cout<<"dit waren de woorden die er wel als eerste stonden:"<<endl<<endl;
	cout<<eerste_woorden<<endl<<endl;
	return 0;
}
