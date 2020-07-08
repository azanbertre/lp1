#ifndef client_h
#define client_h

#include <string>

class Client {
    public:
        std::string name;
        std::string cpf;
        static size_t clientCount;

        Client(std::string _name, std::string _cpf);
};

#endif