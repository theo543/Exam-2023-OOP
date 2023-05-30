#ifndef DRUMNATIONAL
#define DRUMNATIONAL

#include "Drum.h"

class DrumNational : public Drum {
    std::size_t judete;
public:
    DrumNational(std::string nume, double lungime, std::size_t tronsoane, std::size_t judete);
    DrumNational(const DrumNational &other);
};


#endif //DRUMNATIONAL
