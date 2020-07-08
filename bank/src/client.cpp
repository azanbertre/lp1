#include "client.h"

size_t Client::clientCount;

Client::Client(std::string _name, std::string _cpf) : name(_name), cpf(_cpf) {
    this->clientCount += 1;
}