#ifndef provider_h
#define provider_h

#include <string>
#include "product.h"
#include "vector_market.h"

class Provider {
    public:
        std::string name;
        vector_market<Product*> products;

        Provider(std::string _name);
        ~Provider();

        void list();
        void load_products(std::string filename);
        void dump_products(std::string filename);
        bool pass(Product* product, int quantity);
        Product* get_product_by_name(std::string name);
};

#endif