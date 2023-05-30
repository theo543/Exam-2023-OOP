#ifndef DRUMEUROPEAN
#define DRUMEUROPEAN

#include "Drum.h"

class DrumEuropean : public virtual Drum {
    std::size_t tari;
protected:
    [[nodiscard]] std::size_t cost_extra() const override;
public:
    DrumEuropean(std::string nume, double lungime, std::size_t tronsoane, std::size_t tari);
    DrumEuropean(const DrumEuropean &other);
};


#endif //DRUMEUROPEAN
