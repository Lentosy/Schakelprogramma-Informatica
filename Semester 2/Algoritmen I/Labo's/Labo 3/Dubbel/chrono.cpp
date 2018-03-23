#include "chrono.h"
#include <ctime>
void Chrono::start(){
   begin = clock();
}

void Chrono::stop(){
   end = clock();
}

double Chrono::time() const{
   return static_cast<double>(end - begin) / CLOCKS_PER_SEC;
}
