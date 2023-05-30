#include "DrumNational.h"

#include <utility>

DrumNational::DrumNational(std::string nume, double lungime, std::size_t tronsoane, std::size_t judete) : Drum(std::move(nume), lungime, tronsoane), judete(judete) {}

DrumNational::DrumNational(const DrumNational &other) = default;
