#include <iostream>
#include "Rechthoek.cpp"
#include "GekleurdeRechthoek.cpp"
#include "Vierkant.cpp"
#include "GekleurdVierkant.cpp"


int main(void){
	Rechthoek r1;
	r1.print();
	cout << "  Oppervlakte: " << r1.oppervlakte() << endl
		 << "  Omtrek: " << r1.omtrek() << endl;

	Rechthoek r2(4, 6);
	r2.print();
	cout << "  Oppervlakte: " << r2.oppervlakte() << endl
		 << "  Omtrek: " << r2.omtrek() << endl;

    GekleurdeRechthoek gr1;
    gr1.print();
	cout << "  Oppervlakte: " << gr1.oppervlakte() << endl
		 << "  Omtrek: " << gr1.omtrek() << endl;

	GekleurdeRechthoek gr2(5, 7);
	gr2.print();
	cout << "  Oppervlakte: " << gr2.oppervlakte() << endl
		 << "  Omtrek: " << gr2.omtrek() << endl;

    GekleurdeRechthoek gr3(6, 9, "rood");
    gr3.print();
	cout << "  Oppervlakte: " << gr3.oppervlakte() << endl
		 << "  Omtrek: " << gr3.omtrek() << endl;

    Vierkant v1;
    v1.print();
    cout << "  Oppervlakte: " << v1.oppervlakte() << endl
		 << "  Omtrek: " << v1.omtrek() << endl;

	Vierkant v2(10);
    v2.print();
    cout << "  Oppervlakte: " << v2.oppervlakte() << endl
		 << "  Omtrek: " << v2.omtrek() << endl;


	GekleurdVierkant gv1;
    gv1.print();
    cout << "  Oppervlakte: " << gv1.Vierkant::oppervlakte() << endl
		 << "  Omtrek: " << gv1.Vierkant::omtrek() << endl;

	GekleurdVierkant gv2(12);
    gv2.print();
    cout << "  Oppervlakte: " << gv2.Vierkant::oppervlakte() << endl
		 << "  Omtrek: " << gv2.Vierkant::omtrek() << endl;

	GekleurdVierkant gv3(15, "geel");
    gv3.print();
    cout << "  Oppervlakte: " << gv3.Vierkant::oppervlakte() << endl
		 << "  Omtrek: " << gv3.Vierkant::omtrek() << endl;
		 
}