#ifndef SCHIJF_H
#define SCHIJF_H


#include "Doos.h"



class Schijf {
	public:
		Schijf(){
			a = nullptr;
		}
		Schijf(const Schijf&);
		~Schijf(){
			delete a;
		};

	private:	
		Doos a;
}

#endif;