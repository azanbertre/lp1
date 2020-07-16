#include "../include/clientpj.h"

size_t ClientPJ::clientPJCount;

ClientPJ::ClientPJ() {};

ClientPJ::ClientPJ(std::string _social, std::string _cnpj) : social(_social), cnpj(_cnpj) {
    this->clientPJCount += 1;
}

void ClientPJ::setSocial(std::string _social) {
    this->social = _social;
}

std::string ClientPJ::getSocial() {
    return this->social;
}

void ClientPJ::setCNPJ(std::string _cnpj) {
    this->cnpj = _cnpj;
}

std::string ClientPJ::getCNPJ() {
    return this->cnpj;
}