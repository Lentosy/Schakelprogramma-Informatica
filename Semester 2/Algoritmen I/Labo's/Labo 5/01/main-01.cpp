
#include <iostream>
#include <vector>
#include "../graaf.cpp"

/*
 	http://webgraphviz.com/
*/
int main(void){
	std::vector<std::string> lijst = {"alfa", "beta", "gamma", "delta", "epsilon"};
	GraafMetKnoopdata<RichtType::GERICHT, std::string> g(lijst.begin(), lijst.end());
	
	for(int i = 0; i < lijst.size(); i++){
		g.voegVerbindingToe(i, (i + 1) % lijst.size());
	}

	g.teken("graaf.txt");
	return 0;
}
