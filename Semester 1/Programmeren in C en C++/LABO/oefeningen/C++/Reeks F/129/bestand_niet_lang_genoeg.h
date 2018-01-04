#ifndef BESTAND_NIET_LANG_GENOEG_H
#define BESTAND_NIET_LANG_GENOEG_H
#include <stdexcept>
using namespace std;

class bestand_niet_lang_genoeg : public runtime_error {
	public:
		bestand_niet_lang_genoeg(): runtime_error("Bestand is niet lang genoeg") {};
		bestand_niet_lang_genoeg(const string &what) : runtime_error(what) {};
		
};

#endif