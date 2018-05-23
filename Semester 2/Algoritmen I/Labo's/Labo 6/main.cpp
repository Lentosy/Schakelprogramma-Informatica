#include <iostream>
#include <fstream>
#include "hashfunctie.cpp"
#include "hashtabel.cpp"

const std::string BESTAND = "woordenlijst.txt";
const int size = 574427;

int main(void){
	std::ifstream data(BESTAND);
	std::string woord;
	
	hashtabel<std::string, hashing::slechtehash> slechtehashtabel(size);
	hashtabel<std::string, hashing::hornerhash> hornerhashtabel(size);
	hashtabel<std::string, hashing::berthash> berthash(size);
	while(data >> woord){
		slechtehashtabel.voegToe(woord);
		hornerhashtabel.voegToe(woord);
		berthash.voegToe(woord);
	}
	std::cout << "Gemiddelde efficiëntie van opzoeken bij slechte hash : " << slechtehashtabel.berekenEfficientie() << "\n";
	std::cout << "Gemiddelde efficiëntie van opzoeken bij horner hash : " << hornerhashtabel.berekenEfficientie() << "\n";
	std::cout << "Gemiddelde efficiëntie van opzoeken bij bert hash : " << berthash.berekenEfficientie() << "\n";
	data.close();	
	return 0;
}
