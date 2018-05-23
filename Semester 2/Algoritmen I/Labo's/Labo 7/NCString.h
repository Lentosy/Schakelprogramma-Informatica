#ifndef __NCSTRING_H
#define __NCSTRING_H

#include <string>
using std::string;
class NCString: public string{
public:
    NCString(const NCString&)=delete;
    NCString(NCString&& s):string(std::move(s)){};
    NCString():string(){};
    string& operator=(const string&)=delete;
    NCString& operator=(NCString&& nv){
        string::operator=(move(nv));
        return *this;
    };
    NCString& operator=(const NCString&)=delete;
};

#endif

