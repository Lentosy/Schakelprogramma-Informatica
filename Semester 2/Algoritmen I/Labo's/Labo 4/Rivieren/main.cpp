// voor pugi wordt <tag> waarde </tag>
// voorgesteld als
//  []-> naam tag
//  | heeft
//  | een knoop
// [] -> value() == waarde


/*
Stad Neftejugansk in land Russia ligt aan de river-Ob

Stad Salekhard in land Russia ligt aan de river-Ob

Stad Antwerpen in land Belgium ligt aan de river-Schelde

Stad Gent in land Belgium ligt aan de river-Schelde

Stad Liège in land Belgium ligt aan de river-Maas

Stad Namur in land Belgium ligt aan de river-Maas
*/

#include "pugixml.cpp"
#include <iostream>
#include <functional>
const char* node_types[] = {
	"null", "document", "element", "pcdata", "cdata", "comment", "pi", "declaration"
};

//bezoekt een (deel)boom met een visitor in preorder
void DEZBezoekpre(pugi::xml_node n,std::function<void(pugi::xml_node)> bezoekKnoop=[](pugi::xml_node) {}) {
	bezoekKnoop(n);
	for (auto&& k:n.children())
		DEZBezoekpre(k,bezoekKnoop);
};

//verwijdert knopen uit de deelboom die aan de voorwaarde voldoen, maar NIET de wortel
void verwijderUitBoom(pugi::xml_node n, std::function<bool(pugi::xml_node)> moetweg) {
	DEZBezoekpre(n,[&moetweg](pugi::xml_node nn) {
		pugi::xml_node kind = nn.first_child();
		while(kind) {
			pugi::xml_node broer = kind.next_sibling();
			if (moetweg(kind))
				nn.remove_child(kind);
			kind = broer;
		}
	});
};


void schrijfPugiboom(pugi::xml_node n) {
	DEZBezoekpre(n,[](pugi::xml_node nn) {
		std::cout << node_types[nn.type()] << ": '" << nn.name()<<"'";
		if (nn.value() && strlen(nn.value()) !=0) {
			std::cout<< ", waarde='" << nn.value();
		}
		std::cout<<"\n";
		if (nn.attributes_begin() != nn.attributes_end()) {
			std::cout<<"  Attributen:\n    ";
			for (auto&& att : nn.attributes()) {
				std::cout << " " << att.name() << "=" << att.value();
			}
			std::cout<<"\n";
		};
	});
};

void writeSimple(pugi::xml_node n) {
	std::cout << node_types[n.type()];
	std::cout << std::endl;
	std::cout << node_types[n.first_child().type()];
	std::cout << ": " << n.first_child().first_child().first_child().type();
	/*
	std::cout << node_types[n.type()] << ": '" << n.name() << "'";
	std::cout << ", waarde='" << n.value() << "'";
	for (auto&& k:n.children()) {
		if(k.attributes_begin() != k.attributes_end()) {
			std::cout << "  Attributen:\n";
			for(auto&& att: k.attributes()) {
				std::cout << " " << att.name() << "=" << att.value();
			}
			std::cout << "\n";
		}
	}*/
}

int main() {
	// default constructor xml_document
	pugi::xml_document doc;
	// open file and parse. 'doc' contains the content
	if (!doc.load_file("mondial.xml")) {
		return -1;
	}
	writeSimple(doc);
	//uitschrijven boom
	//schrijfPugiboom(doc);
	// end::traverse[]
}






















