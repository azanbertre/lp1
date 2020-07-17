#ifndef establishment_h
#define establishment_h

#include <string>
#include "product.h"
#include "vector_market.h"

class Establishment {
    public:
        std::string name;
        vector_market<Product*> products;
        vector_market<Product*> purchases;

        Establishment(std::string _name);
        ~Establishment();

        void list();
        void stats();
        void load_products(std::string filename);
        void dump_products(std::string filename);
        bool sell(Product* product);
        bool restock(Product* product, int quantity);
        Product* get_product_by_code(std::string code);
};

#endif