#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "establishment.h"

Establishment::Establishment(std::string _name) : name(_name) {
    this->load_products("estoque.csv");
}

Establishment::~Establishment() {
    this->dump_products("estoque.csv");
}

bool Establishment::restock(Product* product, int quantity) {
    product->quantity += quantity;
    return true;
}

bool Establishment::sell(Product* product) {
    product->quantity -= 1;

    std::ofstream file("caixa.csv");
    if (!file.is_open()) {
        return false;
    }

    if (this->purchases.size() <= 0) {
        Product* p = new Product(product->code, product->name, product->measure, product->currency, product->price, 1);
        this->purchases.push(p);
    } else {
        bool found = false;
        for (size_t i = 0; i < this->purchases.size(); i++) {
            if (this->purchases.get(i)->code == product->code) {
                found = true;
                this->purchases.get(i)->quantity += 1;
                break;
            }
        }
        if (!found) {
            Product* p = new Product(product->code, product->name, product->measure, product->currency, product->price, 1);
            this->purchases.push(p);
        }
    }

    for (size_t i = 0; i < this->purchases.size(); i++) {
        Product* p = this->purchases.get(i);

        std::stringstream ss;
        std::string price_string;
        ss << p->price;
        ss >> price_string;

        if (price_string.find(".") == std::string::npos) {
            price_string.append(".0");
        }

        file << p->code << "," << p->name << "," << p->measure << ",\"" << p->currency << " " << price_string.replace(price_string.find("."), 1, ",") << "\"" << "," << p->quantity << std::endl;
    }
    file.close();

    return true;
}

Product* Establishment::get_product_by_code(std::string code) {
    size_t count = this->products.size();
    for (size_t i = 0; i < count; i++) {
        if (code == this->products.get(i)->code) {
            return products.get(i);
        }
    }

    return nullptr;
}

void Establishment::dump_products(std::string filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    // add headers
    file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

    for (size_t i = 0; i < this->products.size(); i++) {
        Product* p = this->products.get(i);

        std::stringstream ss;
        std::string price_string;
        ss << p->price;
        ss >> price_string;

        if (price_string.find(".") == std::string::npos) {
            price_string.append(".0");
        }

        file << p->code << "," << p->name << "," << p->measure << ",\"" << p->currency << " " << price_string.replace(price_string.find("."), 1, ",") << "\"" << "," << p->quantity << std::endl;
    }
    file.close();
}

void Establishment::load_products(std::string filename) {
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

        std::stringstream s_price(data[3].append(".").append(data[4]));

        std::string code = data[0];
        std::string name = data[1];
        std::string measure = data[2];

        char _;
        s_price >> _;

        std::string currency;
        s_price >> currency;

        double price;
        s_price >> price;

        std::string quantity = data[5];

        this->products.push(new Product(code, name, measure, currency, price, (unsigned) std::stoi(quantity)));
    }
}