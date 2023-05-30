#ifndef AUTOSTRADA
#define AUTOSTRADA

#include "Drum.h"

class Autostrada : public virtual Drum {
    std::size_t benzi;
protected:
    [[nodiscard]] std::size_t coeficient_cost_de_baza() const override;
public:
    Autostrada(std::string nume, double lungime, std::size_t tronsoane, std::size_t benzi);
    Autostrada(const Autostrada &other);
};

#endif //AUTOSTRADA
