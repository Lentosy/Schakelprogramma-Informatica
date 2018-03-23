#ifndef __CHRONO
#define __CHRONO

#include <ctime>

class Chrono{
    public:
       void start();
       void stop();
//tijd is de tijd verlopen tussen de laatste keer dat stop() is opgeroepen en de laatste keer dat start() is opgeroepen
       double time() const;
    private:
       clock_t begin, end;       
};

#endif
