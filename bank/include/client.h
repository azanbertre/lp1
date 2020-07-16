#ifndef client_h
#define client_h

#include <string>

class Client {
    private:
        std::string name;
        std::string cpf;
        static size_t clientCount;

    public:
        Client();
        Client(std::string _name, std::string _cpf);
        void setName(std::string _name);
        std::string getName();
        void setCPF(std::string _cpf);
        std::string getCPF();
};

#endif