#ifndef DRUMEUROPEANAUTOSTRADA
#define DRUMEUROPEANAUTOSTRADA

#include "DrumEuropean.h"
#include "Autostrada.h"

class DrumEuropeanAutostrada : public DrumEuropean, public Autostrada {
public:
    DrumEuropeanAutostrada(const std::string& nume, double lungime, std::size_t tronsoane, std::size_t tari, std::size_t benzi);
    DrumEuropeanAutostrada(const DrumEuropeanAutostrada &other);
};


#endif //DRUMEUROPEANAUTOSTRADA
