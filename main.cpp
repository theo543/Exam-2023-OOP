#include <iostream>
#include <vector>
#include <memory>

#include "Drum.h"
#include "DrumNational.h"
#include "DrumEuropean.h"
#include "Autostrada.h"
#include "DrumEuropeanAutostrada.h"

void print(const std::string &str) {
    std::cout<<str;
}

void println(const std::string &str) {
    std::cout<<str<<'\n';
}

int main() {
    std::vector<std::unique_ptr<Drum>> drumuri;
    std::size_t nr_drumuri;
    print("Nr drumuri = ");
    std::cin >> nr_drumuri;
    for(std::size_t x = 0;x<nr_drumuri;x++) {
        {
            std::string nume;
            double lungime;
            std::size_t tronsoane;
            println("Te rog, introdu nume, lungime si nr. tronsoane.");
            std::cin >> nume >> lungime >> tronsoane;
            std::string tip_drum;
            print("Tip drum (DN | DE | A | DEA) = ");
            std::cin >> tip_drum;
            if (tip_drum == "DN") {
                std::size_t judete;
                print("Nr. judete = ");
                std::cin >> judete;
                drumuri.push_back(std::make_unique<DrumNational>(std::move(nume), lungime, tronsoane, judete));
            } else if (tip_drum == "DE") {
                std::size_t tari;
                print("Nr. tari = ");
                std::cin >> tari;
                drumuri.push_back(std::make_unique<DrumEuropean>(std::move(nume), lungime, tronsoane, tari));
            } else if (tip_drum == "A") {
                std::size_t benzi;
                print("Nr. benzi = ");
                std::cin >> benzi;
                drumuri.push_back(std::make_unique<Autostrada>(std::move(nume), lungime, tronsoane, benzi));
            } else if (tip_drum == "DEA") {
                std::size_t tari, benzi;
                print("Nr. tari = ");
                std::cin >> tari;
                print("Nr. benzi = ");
                std::cin >> benzi;
                drumuri.push_back(std::make_unique<DrumEuropeanAutostrada>(std::move(nume), lungime, tronsoane, tari, benzi));
            }
        }
        std::size_t nr_contracte;
        print("Nr. contracte ale drumului = ");
        std::cin >> nr_contracte;
        for(std::size_t y = 0;y<nr_contracte;y++) {
            std::string companie, CIF;
            std::size_t tronson;
            println("Te rog, introdu numele companiei, CIF si nr. tronsonului pentru care este contractul.");
            std::cin >> companie >> CIF >> tronson;
            drumuri.back()->add_contract(Contract{companie, CIF}, tronson);
        }
    }
    for(const auto &d : drumuri) {
        std::cout << d->getNume() << " costa " << d->pretty_print_lungime() << '\n';
    }
    return 0;
}
