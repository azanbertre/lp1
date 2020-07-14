#ifndef company_h
#define company_h

#include <string>

class Company {
    private:
        std::string name;
        std::string cnpj;

    public:
        Company(std::string _name, std::string _cnpj);
        void set_name(std::string _name);
        std::string get_name();
        void set_cnpj(std::string _cnpj);
        std::string get_cnpj();
};

#endif