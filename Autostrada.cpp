#include <utility>
#include "Autostrada.h"

std::size_t Autostrada::coeficient_cost_de_baza() const {
    return benzi * 2500;
}

Autostrada::Autostrada(std::string nume, double lungime, std::size_t tronsoane, std::size_t benzi) : Drum(std::move(nume), lungime, tronsoane), benzi(benzi) {}

Autostrada::Autostrada(const Autostrada &other) = default;
