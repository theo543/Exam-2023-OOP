/*
 * Negrescu Theodor
 * Grupa 151
 * Clang++ 16.0.0
 * Tutore MARIUS MICLUTA-CAMPEANU
 */

#include "Contract.h"

std::size_t Contract::next_unique_id = 0;

Contract::Contract() : unique_id(next_unique_id), company_name("PLACEHOLDER"), company_CIF("PLACEHOLDER") {
    next_unique_id++;
}

Contract::Contract(std::string company_name, std::string company_CIF) : unique_id(next_unique_id), company_name(std::move(company_name)), company_CIF(std::move(company_CIF)) {
    next_unique_id++;
}

Contract::Contract(const Contract &other) : unique_id(next_unique_id), company_name(other.company_name), company_CIF(other.company_CIF) {
    next_unique_id++;
}

Contract &Contract::operator=(const Contract &other) {
    this->company_name = other.company_name;
    this->company_CIF = other.company_CIF;
    return *this;
}

const std::string &Contract::get_company_name() const {
    return company_name;
}

const std::string &Contract::get_company_CIF() const {
    return company_CIF;
}
