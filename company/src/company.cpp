#include "../include/company.h"

Company::Company(std::string _name, std::string _cnpj) : name(_name), cnpj(_cnpj) {}

void Company::set_name(std::string _name) {
    this->name = _name;
}

std::string Company::get_name() {
    return this->name;
}

void Company::set_cnpj(std::string _cnpj) {
    this->cnpj = _cnpj;
}

std::string Company::get_cnpj() {
    return this->cnpj;
}