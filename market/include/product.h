#ifndef product_h
#define product_h

#include <string>

class Product {
    public:
        std::string code;
        std::string name;
        std::string measure;
        std::string currency;
        double price;
        unsigned int quantity;

        Product(std::string _name, unsigned int _quantity);
        Product(std::string _code, std::string _name, std::string _measure, std::string _currency, double _price, unsigned int _quantity);
        ~Product();
};

#endif