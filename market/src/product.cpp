#include "../include/product.h"

Product::Product(std::string _code, std::string _name, std::string _measure, std::string _currency, double _price, unsigned int _quantity) :
    code(_code), name(_name), measure(_measure), currency(_currency), price(_price), quantity(_quantity) {}

Product::~Product() {};