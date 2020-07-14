#include <sstream>
#include <fstream>
#include "../include/client.h"

Client::Client() {
    this->balance = 0;
};

Client::Client(std::string _name) : name(_name) {
    this->balance = 0;
}

Client::~Client() {
    this->dump_bag();
}

void Client::add_balance(double value) {
    this->balance += value;
}

bool Client::buy(Product* product) {
    if (product->price > this->balance) {
        return false;
    }

    if (this->bag.size() <= 0) {
        Product* p = new Product(product->code, product->name, product->measure, product->currency, product->price, 1);
        this->bag.push_back(p);
    } else {
        bool found = false;
        for (size_t i = 0; i < this->bag.size(); i++) {
            if (this->bag[i]->code == product->code) {
                found = true;
                this->bag[i]->quantity += 1;
                break;
            }
        }
        if (!found) {
            Product* p = new Product(product->code, product->name, product->measure, product->currency, product->price, 1);
            this->bag.push_back(p);
        }
    }

    this->balance -= product->price;

    return true;
}

void Client::dump_bag() {
    std::stringstream ss;
    std::string filename;

    ss << this->name << ".txt";
    ss >> filename;

    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    for (size_t i = 0; i < this->bag.size(); i++) {
        Product* product = this->bag[i];

        std::stringstream ss;
        std::string price_string;
        ss << product->price;
        ss >> price_string;

        if (price_string.find(".") == std::string::npos) {
            price_string.append(".0");
        }

        file << product->code << "," << product->name << "," << product->measure << ",\"" << product->currency << " " << price_string.replace(price_string.find("."), 1, ",") << "\"" << ",1" << std::endl;
    }

    file.close();
}