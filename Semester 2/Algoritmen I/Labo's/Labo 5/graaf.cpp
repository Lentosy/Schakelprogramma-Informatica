#include "graaf.h"
//Deze header bevat de code voor de klassen:
//
//
//    Graaf<RichtType>: basisklasse met grafen zonder tak- of knoopdata
//    GraafMetTakdata<RichtType,TakDatatype>
//    GraafMetKnoopdata<RichtType,KnoopDatatype>
//    GraafMetKnoopEnTakdata<RichtType,KnoopDatatype,Takdatatype>
//
//
/**********************************************************************

   Class: GraafMetTakdata<RichtType, Takdata>
   
   Implementatie
   
***************************************************************************/
template<RichtType RT>
std::string Graaf<RT>::knooplabel(int i) const{
    std::ostringstream uit;
    uit<<i;
    return uit.str();
};

template<RichtType RT>
std::string Graaf<RT>::taklabel(int i) const{
    return "";
};

template<RichtType RT>
void Graaf<RT>::controleerKnoopnummer(int k) const{
    if (k<0 || (size_t)k>=knopen.size()){
        std::ostringstream out;
        out << "Ongeldig knoopnummer "<<k
            <<". Moet >= 0 en < "<<knopen.size()<<" zijn.";
        throw GraafExceptie(out.str());
    }
}

template<RichtType RT>
Graaf<RT>::Graaf(int n) : knopen(n), hoogsteVerbindingsnummer(0){};


template<RichtType RT>
bool Graaf<RT>::isGericht() const { return true; }//voor gerichte graaf

template<>
bool Graaf<ONGERICHT>::isGericht() const { return false; }//voor ongerichte graaf


template<RichtType RT>
int Graaf<RT>::voegKnoopToe(){
    int n = knopen.size();
    knopen.resize(n+1); // default constructor voor nieuwe knoop wordt opgeroepen (hier lege map)
    return n;
}


template<RichtType RT>
int Graaf<RT>::voegVerbindingToe(int van, int naar){
    controleerKnoopnummer(van);
    controleerKnoopnummer(naar);

    if (knopen[van].count(naar) > 0)   
    {
        std::ostringstream out;
        out << "verbinding " << van << "-" << naar << " bestaat al"; 
        throw GraafExceptie(out.str());
    }
    else {
        int verbindingsnummer;
        if (!vrijgekomenVerbindingsnummers.empty()){
            verbindingsnummer=vrijgekomenVerbindingsnummers.top();
            vrijgekomenVerbindingsnummers.pop();
        }else
            verbindingsnummer=hoogsteVerbindingsnummer++;
        voegVerbindingToeInDatastructuur(van,naar,verbindingsnummer);
        return verbindingsnummer;
    }
}

template<RichtType RT>//voor gerichte graaf
void Graaf<RT>::voegVerbindingToeInDatastructuur(int van, int naar, int verbindingsnummer){
    knopen[van][naar] = verbindingsnummer;
}

template<>
void Graaf<ONGERICHT>::voegVerbindingToeInDatastructuur(int van, int naar, int verbindingsnummer){
    knopen[van][naar] = verbindingsnummer;
    knopen[naar][van] = verbindingsnummer;
}

template<RichtType RT>
void Graaf<RT>::verwijderVerbinding(int van, int naar){
    controleerKnoopnummer(van);
    controleerKnoopnummer(naar);
    if (knopen[van].find(naar)!=knopen[van].end()){//verbinding bestaat
        vrijgekomenVerbindingsnummers.push(knopen[van][naar]);
        verwijderVerbindingUitDatastructuur(van,naar);
    }
    // (geen exception indien verbinding niet bestaat)
}

template<RichtType RT>
void Graaf<RT>::verwijderVerbindingUitDatastructuur(int van, int naar){
    knopen[van].erase(naar);
}

template<>
void Graaf<ONGERICHT>::verwijderVerbindingUitDatastructuur(int van, int naar){
    knopen[van].erase(naar);
    knopen[naar].erase(van);
}

template<RichtType RT>
int Graaf<RT>::aantalKnopen() const { return knopen.size(); } 

template<RichtType RT>
int Graaf<RT>::aantalVerbindingen() const {
    return hoogsteVerbindingsnummer-vrijgekomenVerbindingsnummers.size();
}

template<RichtType RT>
int Graaf<RT>::verbindingsnummer(int van, int naar) const{
    controleerKnoopnummer(van);
    controleerKnoopnummer(naar);
    Knoop::const_iterator verbindingit = knopen[van].find(naar);
    
    if (verbindingit == knopen[van].end())   
        return -1;
    else 
        return (*verbindingit).second;
}

template<RichtType RT>
void Graaf<RT>::wis(){
    knopen.clear();
    hoogsteVerbindingsnummer = 0;
    while (!vrijgekomenVerbindingsnummers.empty())
        vrijgekomenVerbindingsnummers.pop();
}

template<RichtType RT>
void Graaf<RT>::schrijf(std::ostream &os) const{
    os << "Graaf: " << aantalKnopen() << " knopen en " 
        << aantalVerbindingen() << " verbindingen:" << std::endl;
    for (int k=0; k<aantalKnopen(); k++)
        schrijfKnoop(os, k);
}

template<RichtType RT>
void Graaf<RT>::teken(const char* bestandsnaam) const{
    std::ofstream uit(bestandsnaam);
    assert(uit);
    std::string pijl;
    if (isGericht()){
        uit<<"digraph {\n";
        pijl="->";
    }
    else{
        uit<<"graph {\n";
        pijl="--";
    };
    for (int k=0; k<aantalKnopen(); k++){
        if (knopen[k].empty())
            uit<<knooplabel(k)<<";\n";
        else{
        for (auto& p: this->knopen[k])
            if (isGericht() || p.first >=k)
                uit<<knooplabel(k)<<" "<<pijl<<" "
                   <<knooplabel(p.first)<<taklabel(p.second)<<";\n";
        };
    };
    uit<<"}";
    uit.close();
};


template<RichtType RT>
void Graaf<RT>::schrijfKnoop(std::ostream &os, int k) const{
    os<<"Knoop "<<k<<"::\n";
    for (Knoop::const_iterator it=knopen[k].begin(); it!=knopen[k].end(); ++it)
    {
        os << "  ->" << it->first;
        schrijfVerbinding(os, it->second);
    }
}
    
template<RichtType RT>
void Graaf<RT>::schrijfVerbinding(std::ostream &os, int v) const{
    os << " via verbinding nr. " << v << std::endl;
}

template<RichtType RT>
std::ostream &operator<<(std::ostream &os, const Graaf<RT> &g){
    g.schrijf(os);
    return os;
}

template<RichtType RT,class Takdata>
std::string GraafMetTakdata<RT,Takdata>::taklabel(int i) const{
        std::ostringstream uit;
        uit<<"[label=\""<<takdatavector[i]<<"\"]";
        return uit.str();
    };

template<RichtType RT,class Takdata>
int GraafMetTakdata<RT,Takdata>::voegVerbindingToe(int van, int naar){
    return this->voegVerbindingToe(van,naar,Takdata());
}


template<RichtType RT,class Takdata>
int GraafMetTakdata<RT,Takdata>::voegVerbindingToe(int van, int naar, const Takdata& td){
    bool isnieuwtaknummer=this->vrijgekomenVerbindingsnummers.empty();
    int taknummer=Graaf<RT>::voegVerbindingToe(van,naar);
    if (isnieuwtaknummer)
        takdatavector.push_back(td);
    else
        takdatavector[taknummer]=td;
    return taknummer;
}



template<RichtType RT,class Takdata>
const Takdata* GraafMetTakdata<RT,Takdata>::geefTakdata(int van,int naar) const{
    int taknummer=this->verbindingsnummer(van,naar);
    if (taknummer!=-1)
        return &takdatavector[taknummer];
    else
        return 0;
}

template<RichtType RT,class Takdata>
Takdata* GraafMetTakdata<RT,Takdata>::geefTakdata(int van,int naar){
    int taknummer=this->verbindingsnummer(van,naar);
    if (taknummer!=-1)
        return &takdatavector[taknummer];
    else
        return 0;
}


template<RichtType RT,class Takdata>
void GraafMetTakdata<RT,Takdata>::wis(){
    Graaf<RT>::wis();
    takdatavector.clear();
}

template<RichtType RT,class Takdata>
void  GraafMetTakdata<RT,Takdata>::schrijfVerbinding(std::ostream &os, int v) const{
    os << " via verbinding nr. " << v <<" (Data: "<<takdatavector[v]<<")"<< std::endl;
}


template<RichtType RT, class Knoopdata>
template<class InputIterator>
GraafMetKnoopdata<RT,Knoopdata>::GraafMetKnoopdata(InputIterator start,InputIterator eind)
    :Graaf<RT>(0){
        for(;start!=eind;start++)
            voegKnoopToe(*start);
}

template<RichtType RT, class Knoopdata>
int GraafMetKnoopdata<RT,Knoopdata>::voegKnoopToe(){
    return this->voegKnoopToe(Knoopdata());
}

template<RichtType RT, class Knoopdata>
int GraafMetKnoopdata<RT,Knoopdata>::voegKnoopToe(const Knoopdata& kd){
    int ret=Graaf<RT>::voegKnoopToe();
    knoopdatavector.push_back(kd);
    return ret;
}

template<RichtType RT,class Knoopdata>
const Knoopdata* GraafMetKnoopdata<RT,Knoopdata>::geefKnoopdata(int knoopnummer) const{
    this->controleerKnoopnummer(knoopnummer);
    return &knoopdatavector[knoopnummer];
}

template<RichtType RT,class Knoopdata>
Knoopdata* GraafMetKnoopdata<RT,Knoopdata>::geefKnoopdata(int knoopnummer){
    this->controleerKnoopnummer(knoopnummer);
    return &knoopdatavector[knoopnummer];
}


template<RichtType RT,class Knoopdata>
void GraafMetKnoopdata<RT,Knoopdata>::wis(){
    Graaf<RT>::wis();
    knoopdatavector.clear();
}


template<RichtType RT, class Knoopdata>
void GraafMetKnoopdata<RT,Knoopdata>::schrijfKnoop(std::ostream &os, int k) const{
    os << "knoop " << k <<"(Data: "<<knoopdatavector[k]<< "):" << std::endl;
    for (std::map<int, int>::const_iterator it=this->knopen[k].begin(); it!=this->knopen[k].end(); ++it){
        os << "  ->" << it->first;
        this->schrijfVerbinding(os, it->second);
    }
}


