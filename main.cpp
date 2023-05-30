#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

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

void trim_newline(std::string &str) {
    while(str.ends_with('\n') || str.ends_with('\r'))
        str.pop_back();
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
            trim_newline(nume);
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
            trim_newline(companie);
            trim_newline(CIF);
            drumuri.back()->add_contract(Contract{companie, CIF}, tronson);
        }
    }
    {
        double lungime_totala = 0, lungime_autostrazi = 0;
        for (const auto &d: drumuri) {
            lungime_totala += d->getLungime();
            auto *a = dynamic_cast<Autostrada *>(&*d);
            if (a) {
                lungime_autostrazi += a->getLungime();
            }
        }
        println("Lungimea totala = " + std::to_string(lungime_totala) + " km");
        println("Lungimea autostrazilor = " + std::to_string(lungime_autostrazi) + " km");
    }
    {
        std::string CIF_reziliat;
        print("CIF de reziliat = ");
        std::cin >> CIF_reziliat;
        trim_newline(CIF_reziliat);
        for (auto &d: drumuri) {
            d->delete_CIF(CIF_reziliat);
        }
    }
    {
        std::string nume_drum;
        print("Nume drum de calculat costul total = ");
        std::cin >> nume_drum;
        trim_newline(nume_drum);
        const auto drum = std::find_if(drumuri.begin(), drumuri.end(), [&nume_drum] (const auto &d) -> bool {
            return d->getNume() == nume_drum;
        });
        if(drum == drumuri.end()) {
            println("Drumul nu a fost gasit!");
        } else {
            println("Cost total al drumului = " + (*drum)->pretty_print_cost());
        }
    }
    return 0;
}
