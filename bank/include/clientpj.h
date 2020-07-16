#ifndef clientpj_h
#define clientpj_h

#include <string>

class ClientPJ {
    private:
        std::string social;
        std::string cnpj;
        static size_t clientPJCount;

    public:
        ClientPJ();
        ClientPJ(std::string _social, std::string _cnpj);
        void setSocial(std::string _social);
        std::string getSocial();
        void setCNPJ(std::string _cnpj);
        std::string getCNPJ();
};

#endif