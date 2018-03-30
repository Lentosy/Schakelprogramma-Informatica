#ifndef __REKENMACHINE
#define __REKENMACHINE

#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <functional>

#include "mijnstack.h"

using std::function;
using std::string;
using std::istream;
using std::ostream;

using std::map;

class Rekenmachine {
	public:
		Rekenmachine() : stop(false) {} 
		friend ostream & operator<<(ostream & out, Rekenmachine & r);
		friend istream & operator>>(istream & in, Rekenmachine & r);
		bool should_stop();
	private:
	    static map<string, function<void(Mijnstack<double>&)>> operaties;
	    Mijnstack<double> resultaten;
	    bool stop;
};

map<string, function<void(Mijnstack<double>&)>> Rekenmachine::operaties={
    {"+",[](Mijnstack<double>& ms){
            double arg2 = ms.top();
            ms.pop();
            ms.top() += arg2;
         }
	},
    {"-",[](Mijnstack<double>& ms){
            double arg2 = ms.top();
            ms.pop();
            ms.top() -= arg2;
         }
	},
    {"*",[](Mijnstack<double>& ms){
            double arg2 = ms.top();
            ms.pop();
            ms.top() *= arg2;
         }
	},
    {"/",[](Mijnstack<double>& ms){
            double arg2 = ms.top();
            ms.pop();
            ms.top() /= arg2;
         }
	},
    {"V",[](Mijnstack<double>& ms){
            ms.top() = sqrt(ms.top());
         }
	},
    {"s",[](Mijnstack<double>& ms){
            ms.top() *= ms.top();
         }
	},
    {"c",[](Mijnstack<double>& ms){
            ms.pop();
         }
	},
	{"cos",[](Mijnstack<double>& ms){
			ms.top() = std::cos(ms.top());
		}
	}
};

#endif
