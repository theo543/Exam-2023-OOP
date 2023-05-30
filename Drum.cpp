#include <stdexcept>
#include <utility>
#include "Drum.h"

std::size_t Drum::coeficient_cost_de_baza() const {
    return 3000;
}

std::size_t Drum::cost_extra() const {
    return 0;
}

const std::string &Drum::getNume() const {
    return nume;
}

double Drum::getLungime() const {
    return lungime;
}

std::string Drum::pretty_print_lungime() const {
    double milione_euro = this->total_cost() / 1000;
    return std::to_string(milione_euro) + " milioane Euro";
}

std::size_t Drum::getTronsoane() const {
    return tronsoane;
}

Drum::Drum(std::string nume, double lungime, std::size_t tronsoane) : nume(std::move(nume)), lungime(lungime), tronsoane(tronsoane), contracte(tronsoane, std::nullopt) {
    if(tronsoane == 0) throw std::invalid_argument("Trebuie cel putin un tronson!");
}

Drum::Drum(const Drum &other) : nume(other.nume), lungime(other.lungime), tronsoane(other.tronsoane), contracte(tronsoane, std::nullopt) {}

void Drum::add_contract(const Contract &c, std::size_t tronson) {
    if(contracte[tronson].has_value()) throw std::invalid_argument("Tronson " + std::to_string(tronson) + " deja are contract!");
    contracte[tronson] = c;
}

bool Drum::tronson_are_contract(std::size_t tronson) const {
    return contracte[tronson].has_value();
}

void Drum::delete_CIF(const std::string &CIF) {
    for(auto &c : contracte) {
        if(c.has_value() && c->get_company_CIF() == CIF) {
            c = std::nullopt;
        }
    }
}

double Drum::total_cost() const {
    double total = 0;
    double lungime_tronson = lungime / static_cast<double>(tronsoane);
    for(auto &c : contracte) {
        if(!c.has_value()) continue;
        total += this->coeficient_cost_de_baza() * lungime_tronson + this->cost_extra();
    }
    return total;
}

Drum::~Drum() = default;
