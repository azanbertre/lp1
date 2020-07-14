#ifndef establishment_h
#define establishment_h

#include <string>
#include <vector>
#include "product.h"

class Establishment {
    public:
        std::string name;
        std::vector<Product*> products;
        std::vector<Product*> purchases;

        Establishment(std::string _name);
        ~Establishment();

        void list();
        void stats();
        void load_products(std::string filename);
        void dump_products(std::string filename);
        bool sell(Product* product);
        Product* get_product_by_code(std::string code);
};

#endif