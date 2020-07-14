#ifndef client_h
#define client_h

#include <string>
#include <vector>
#include "product.h"

class Client {
    public:
        std::string name;
        std::vector<Product*> bag;
        double balance;

        Client();
        ~Client();
        Client(std::string _name);
        bool buy(Product* product);
        void add_balance(double value);
        void dump_bag();
};

#endif