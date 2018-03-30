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
using namespace pugi;
using namespace std;
const char* node_types[] =
{
    "null", "document", "element", "pcdata", "cdata", "comment", "pi", "declaration"
};

//bezoekt een (deel)boom met een visitor in preorder
void DEZBezoekpre(pugi::xml_node n,std::function<void(pugi::xml_node)> bezoekKnoop=[](pugi::xml_node){}){
    bezoekKnoop(n);
    for (auto&& k:n.children())
        DEZBezoekpre(k,bezoekKnoop);
};

//verwijdert knopen uit de deelboom die aan de voorwaarde voldoen, maar NIET de wortel
void verwijderUitBoom(xml_node n, function<bool(xml_node)> moetweg){
    DEZBezoekpre(n,[&moetweg](xml_node nn){
        xml_node kind = nn.first_child();
        while(kind){
            xml_node broer = kind.next_sibling();
            if (moetweg(kind))
                nn.remove_child(kind);
            kind = broer;
        }
    });
};


void schrijfPugiboom(pugi::xml_node n){
    DEZBezoekpre(n,[](pugi::xml_node nn){
        std::cout << node_types[nn.type()] << ": '" << nn.name()<<"'";
	    if (nn.value() && strlen(nn.value()) !=0){
	        std::cout<< ", waarde='" << nn.value();	    	
		}
		std::cout<<"\n";
	    if (nn.attributes_begin() != nn.attributes_end()){
	        std::cout<<"  Attributen:\n    ";
	    	for (auto&& att : nn.attributes()){
	    		std::cout << " " << att.name() << "=" << att.value();            		
			}
			std::cout<<"\n";
        };
    });
};

void simpleSimple(pugi::xml_node n){
	
}

int main()
{
	// aanmaken pugi object default constructor
    pugi::xml_document doc;
    // bestand openen en parsen met pugi
    if (!doc.load_file("mondial.xml")){
    	return -1;
	}
	schrijfSimple(doc):
	//uitschrijven boom
    //schrijfPugiboom(doc);
    // end::traverse[]
}






















