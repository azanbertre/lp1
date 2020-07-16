#include "client.h"

size_t Client::clientCount;

Client::Client() {};

Client::Client(std::string _name, std::string _cpf) : name(_name), cpf(_cpf) {
    this->clientCount += 1;
}

void Client::setName(std::string _name) {
    this->name = _name;
}

std::string Client::getName() {
    return this->name;
}

void Client::setCPF(std::string _cpf) {
    this->cpf = _cpf;
}

std::string Client::getCPF() {
    return this->cpf;
}