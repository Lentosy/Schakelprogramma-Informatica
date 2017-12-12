#ifndef RECHTHOEK_H
#define RECHTHOEK_H

using namespace std;

class Rechthoek {
	public:
		Rechthoek() : Rechthoek(1, 1) {};
		Rechthoek(int h, int b) : hoogte(h), breedte(b) {};
		void print() const;
		int oppervlakte() const;
		int omtrek() const;
	protected:
		int hoogte;
	private:
		int breedte;
};


#endif