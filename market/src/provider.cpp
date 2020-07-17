#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "provider.h"

Provider::Provider(std::string _name) : name(_name) {
    this->load_products("fornecedor.csv");
}

Provider::~Provider() {
    this->dump_products("fornecedor.csv");
}

bool Provider::pass(Product* product, int quantity) {
    product->quantity -= quantity;
    return true;
}

Product* Provider::get_product_by_name(std::string name) {
    size_t count = this->products.size();
    for (size_t i = 0; i < count; i++) {
        if (name == this->products.get(i)->name) {
            return products.get(i);
        }
    }

    return nullptr;
}

void Provider::dump_products(std::string filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    // add headers
    file << "PRODUTO,QUANTIDADE" << std::endl;

    for (size_t i = 0; i < this->products.size(); i++) {
        Product* p = this->products.get(i);
        file << p->name << "," << p->quantity << std::endl;
    }
    file.close();
}

void Provider::load_products(std::string filename) {
    std::ifstream file(filename, std::ios::app);
    if (!file.is_open()) {
        return;
    }

    size_t count = 0;
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);

        // ignore header
        if (count == 0) {
            count += 1;
            continue;
        }

        if (line.size() == 0) {
            continue;
        }

        std::stringstream s(line);
        std::string t;

        std::vector<std::string> data;
        while (std::getline(s, t, ',')) {
            data.push_back(t);
        }

        std::string name = data[0];
        std::string quantity = data[1];

        this->products.push(new Product(name, (unsigned) std::stoi(quantity)));
    }
}