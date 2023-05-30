#include <utility>
#include "DrumEuropean.h"

std::size_t DrumEuropean::cost_extra() const {
    return tari * 500;
}

DrumEuropean::DrumEuropean(std::string nume, double lungime, std::size_t tronsoane, std::size_t tari) : Drum(std::move(nume), lungime, tronsoane), tari(tari) {}
DrumEuropean::DrumEuropean(const DrumEuropean &other) = default;
