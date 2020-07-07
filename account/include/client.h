#ifndef client_h
#define client_h

#include <string>

class Client {
    public:
        std::string name;
        std::string cpf;

        Client(std::string _name, std::string _cpf);
};

#endif