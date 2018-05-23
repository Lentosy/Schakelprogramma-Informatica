#include <cstdlib>
namespace hashing{
	int slechtehash(const std::string& s,int n){
	    return s.size() % n;
	};
	
	int hornerhash(const std::string& woord,int n) {
	   unsigned int horner=0;
	   for (int i = 0; i < woord.size(); i++)
	     horner=(horner*256 + woord[i]);
	   return horner % n;
	};
	
	int berthash(const std::string& woord, int n){
		
		
		
	}
}


