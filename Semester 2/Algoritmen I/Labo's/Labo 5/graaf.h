#ifndef __GRAAF_H
#define __GRAAF_H

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <exception>
#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
//Deze header bevat de code voor de klassen:
//
//
//    Graaf<RichtType>: basisklasse met grafen zonder tak- of knoopdata
//    GraafMetTakdata<RichtType,TakDatatype>
//    GraafMetKnoopdata<RichtType,KnoopDatatype>
//    GraafMetKnoopEnTakdata<RichtType,KnoopDatatype,Takdatatype>
//
//
//Evenals de bijbehorende klasse van GraafExcepties.
/**********************************************************************

   Class: Graaf
   
   beschrijving: Graaf is de basisklasse voor een hiërarchie van ijlegraafklassen.
                  Deze hiërarchie zal klassen bevatten voor grafen met data behorend bij
                  knopen en/of takken. Deze data worden opgeslagen in vectoren,
                  zodat kan worden opgezocht op index.
        Ad knopen:      Deze zijn opeenvolgend genummerd. Knopen kunnen niet individueel verwijderd worden.
                        Wel kunnen alle knopen samen verwijderd worden (door wis()), en kunnen knopen
                        één voor één toegevoegd worden.
        Ad verbindingen: Deze kunnen naar hartenlust toegevoegd en verwijderd worden. Als een
                        verbinding wordt verwijderd, wordt het nummer op de stack van
                        vrijgekomenVerbindingsnummers gezet. Worden verbindingen toegevoegd,
                        dan worden eerst deze vrijgekomen nummers opnieuw gebruikt, alvorens nieuwe nummers
                        worden toegevoegd. hoogsteVerbindingsnummer kan nooit verkleinen, en de
                        vector met takdata zal altijd hoogsteVerbindingsnummer elementen bevatten.

        Tekenen met GraphViz: etiketten mogen, bij uitschrijven geen aanhalingsteken bevatten.
                        code is nog niet grondig getest.
                        
***************************************************************************/

enum RichtType { GERICHT, ONGERICHT }; 


class GraafExceptie : public std::logic_error {
public:
    GraafExceptie(const std::string &boodschap_) : std::logic_error(boodschap_) {}
};

std::ostream &operator<<(std::ostream &os, const GraafExceptie& exc){
    return os << exc.what();
}


template<RichtType RT>
class Graaf{
	public:
		typedef std::map<int, int>  Knoop;      // beeldt knoopnummer (van buur) af op verbindingsnummer
	
	    // Construeert een graaf met gegeven RichtType en aantal knopen (default 0), zonder verbindingen.
	    Graaf(int n=0);
	    // Geeft true indien het richttype GERICHT is, false indien het ONGERICHT is.
	    bool isGericht() const;
	
	    // Voegt een nieuwe 'lege' knoop toe, d.w.z. zonder verbindingen.
	    // Geeft knoopnummer van toegevoegde knoop terug (begint bij 0).
	    virtual int voegKnoopToe();   
	    
	    // Voegt verbinding toe tussen knoopnummers 'van' en 'naar'.
	    // Gooit GraafExceptie indien verbinding al bestaat of knoopnummers ongeldig zijn.
	    // Geeft verbindingsnummer van toegevoegde verbinding terug (begint bij 0).
	    // Bij ongerichte graaf wordt terugverbinding ook toegevoegd (met zelfde verbindingnummer!)
	    virtual int voegVerbindingToe(int van, int naar); 
	        
	    // Verwijdert de verbinding tussen knoopnummers 'van' en 'naar', incl. de terugverbinding indien ongericht.
	    // Gooit GraafExceptie indien knoopnummers ongeldig zijn.
	    // Geen exceptie indien de verbinding niet bestond.
	    // Andere verbindingen worden niet 'hernummerd'. Er komen dus mogelijks "gaten" in de verbindingsnummers.
	    virtual void verwijderVerbinding(int van, int naar);
	
	    // Geeft het aantal knopen van de graaf.
	    int aantalKnopen() const;
	
	    // Geeft het aantal verbindingen van de graaf. 
	    // Bij ongerichte graaf worden verbindingen NIET dubbel geteld!
	    int aantalVerbindingen() const;
	
	    // Geeft het verbindingsnummer van de verbinding tussen 'van' en 'naar'.
	    // Geeft -1 indien die verbinding niet bestaat.
	    // Gooit een GraafExceptie indien knoopnummers ongeldig zijn.
	    // Opgelet: performantie is O(log(v)) waarbij v aantal verbindingen vanuit 'van' is.
	    int verbindingsnummer(int van, int naar) const; 
	
	    // Verwijdert alle knopen en verbindingen en herstart de verbindingsnummer
	    virtual void wis();
	
	    // Toegang tot de knopen:
	    const Knoop &operator[](int i) const { return knopen[i]; }
	          Knoop &operator[](int i)       { return knopen[i]; }  // deze kan als lvalue gebruikt worden
	
	          
	    // Schrijft de gegevens van de volledige graaf naar outputstream os.
	    //Hulpfuncties schrijfKnoop en schrijfVerbinding.
	    virtual void schrijf(std::ostream &os) const;
	
	    //teken maakt een .dot-bestand met de opgegeven naam en schrijft de graaf naar dit bestand.
	    //knooplabel en taklabel zijn twee hulpfuncties hierbij
	    virtual void teken(const char* bestandsnaam) const;
	protected:
	    //hulpfuncties voor schrijven/tekenen
	    virtual std::string knooplabel(int i) const;
	    virtual std::string taklabel(int i) const;
	    // Schrijft de gegevens van de knoop met knoopnummer k naar outputstream os.
	    virtual void schrijfKnoop(std::ostream &os, int k) const;
	    // Schrijft de gegevens van de verbinding met verbindingsnummer v naar outputstream os.
	    virtual void schrijfVerbinding(std::ostream &os, int v) const;
	
	    
	    //algemene hulpfuncties
	    void controleerKnoopnummer(int k) const;   // throw indien k ongeldig
	    void voegVerbindingToeInDatastructuur(int van, int naar,int verbindingsnummer);
	    void verwijderVerbindingUitDatastructuur(int van, int naar);
	protected:
	    //datavelden
	    std::vector<Knoop>  knopen;
	    int                 hoogsteVerbindingsnummer;
	    RichtType           richttype;
	    std::stack<int>     vrijgekomenVerbindingsnummers;
};


template<RichtType RT>
std::ostream &operator<<(std::ostream& os, const Graaf<RT>& g);

/**********************************************************************

   Class: GraafMetTakdata<RichtType, Takdata>
   
   beschrijving: Deelklasse van Graaf, met data bij elke tak.
   
***************************************************************************/

template<RichtType RT,class Takdata>
class GraafMetTakdata: public virtual Graaf<RT>{
public:
    GraafMetTakdata(int n=0):Graaf<RT>(n){};
    //Noot: toevoegfunctie zonder takdata op te geven kan alleen gebruikt als de klasse
    //      Takdata een defaultconstructor heeft.
    virtual int voegVerbindingToe(int van, int naar); 
    virtual int voegVerbindingToe(int van, int naar, const Takdata&);
    //Noot: verwijderVerbinding wordt ongewijzigd overgenomen van Graaf!

    //TakData vrijgeven (eventueel voor wijziging). Geeft nullpointer als tak niet bestaat
    //Noot: pointers teruggegeven door geefTakdata worden ongeldig
    //door toevoegen van een tak.
    const Takdata* geefTakdata(int van,int naar) const;
          Takdata* geefTakdata(int van,int naar)      ;
    virtual std::string taklabel(int i) const;
    virtual void wis();

          
    // Schrijft de gegevens van de verbinding met verbindingsnummer v naar outputstream os.
    virtual void schrijfVerbinding(std::ostream &os, int v) const;

protected:
    std::vector<Takdata> takdatavector;
};

/**********************************************************************

   Class: GraafMetTakdata<RichtType, Knoopdata>
   
   beschrijving: Deelklasse van Graaf, met data bij elke knoop.
   
***************************************************************************/

template<RichtType RT, class Knoopdata>
class GraafMetKnoopdata:public virtual Graaf<RT>{
public:
    // Construeert een graaf met gegeven RichtType, en lijst van Knoopdata;
    template<class InputIterator>
    GraafMetKnoopdata(InputIterator start,InputIterator eind);
    GraafMetKnoopdata():Graaf<RT>(){};
    
    virtual int voegKnoopToe();   
    virtual int voegKnoopToe(const Knoopdata&);

    const Knoopdata* geefKnoopdata(int knoopnr) const;
          Knoopdata* geefKnoopdata(int knoopnr)      ;
    virtual std::string knooplabel(int i) const{
        std::ostringstream uit;
        uit<<'"'<<i<<":"<<knoopdatavector[i]<<'"';
        return uit.str();
    };

    virtual void wis();
    virtual void schrijfKnoop(std::ostream &os, int k) const;

protected:
    //datavelden
    std::vector<Knoopdata>  knoopdatavector;
};
/**********************************************************************

   Class: GraafMetKnoopEnTakdata<RichtType, Takdata>
   
   beschrijving: Deelklasse van vorige twee.
   
***************************************************************************/

template<RichtType RT, class Knoopdata, class Takdata>
class GraafMetKnoopEnTakdata:public GraafMetKnoopdata<RT,Knoopdata>,
                             public GraafMetTakdata<RT, Takdata>{
public:
    template<class InputIterator>
    GraafMetKnoopEnTakdata(InputIterator start,InputIterator eind):
        GraafMetKnoopdata<RT,Knoopdata>(start,eind){};
    GraafMetKnoopEnTakdata():
        GraafMetKnoopdata<RT,Knoopdata>(){};
    virtual void wis(){
        GraafMetKnoopdata<RT,Knoopdata>::wis();
        this->takdatavector.clear();
    }
};

#endif // __GRAAF_H
