#ifndef DRUM
#define DRUM

#include <string>
#include <vector>
#include <optional>
#include "Contract.h"

class Drum {
    std::string nume;
    double lungime;
    std::size_t tronsoane;
    std::vector<std::optional<Contract>> contracte;
protected:
    [[nodiscard]] virtual std::size_t coeficient_cost_de_baza() const;
    [[nodiscard]] virtual std::size_t cost_extra() const;
public:
    Drum(std::string nume, double lungime, std::size_t tronsoane);
    Drum(const Drum &other);
    [[nodiscard]] const std::string &getNume() const;
    [[nodiscard]] double getLungime() const;
    [[nodiscard]] std::string pretty_print_lungime() const;
    [[nodiscard]] std::size_t getTronsoane() const;
    void add_contract(const Contract &c, std::size_t tronson);
    [[nodiscard]] bool tronson_are_contract(std::size_t tronson) const;
    void delete_CIF(const std::string &CIF);
    [[nodiscard]] double total_cost() const;
    virtual ~Drum() = 0; // just to make this class abstract
};

#endif //DRUM
