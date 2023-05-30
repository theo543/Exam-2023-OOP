#include "DrumEuropeanAutostrada.h"

DrumEuropeanAutostrada::DrumEuropeanAutostrada(const std::string& nume, double lungime, std::size_t tronsoane, std::size_t tari, std::size_t benzi)
    : Drum(nume, lungime, tronsoane), DrumEuropean(nume, lungime, tronsoane, tari), Autostrada(nume, lungime, tronsoane, benzi) {}
