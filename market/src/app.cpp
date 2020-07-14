#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/app.h"

app::app() : establishment("Supermarket") {
    this->current_client = nullptr;
};

int app::run(int argc, char* argv[]) {
    while (true) {
        bool cnt = handle_menus(this);
        if (!cnt) {
            break;
        }
    }

    this->establishment.dump_products("estoque.csv");

    return 0;
}

void app::login() {
    std::cout << "Client name: " << std::ends;

    std::string name;
    std::getline(std::cin, name);

    std::cout << "\n" << std::endl;

    this->current_client = new Client(name);
}

void app::list_products() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "List of products\n" << std::endl;

    size_t count = this->establishment.products.size();
    for (size_t i = 0; i < count; i++) {
        std::string qnt = "Qnt: ";
        if (this->establishment.products[i]->quantity < 10) {
            qnt = "Qnt:  ";
        }
        std::cout << qnt << this->establishment.products[i]->quantity << " | " <<
            this->establishment.products[i]->name << " - " << this->establishment.products[i]->currency <<  " " <<
            this->establishment.products[i]->price << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void app::list_purchases() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "List of purchases\n" << std::endl;

    size_t count = this->establishment.purchases.size();
    for (size_t i = 0; i < count; i++) {
        std::string qnt = "Qnt: ";
        std::cout << qnt << this->establishment.purchases[i]->quantity << " | " <<
            this->establishment.purchases[i]->name << " - " << this->establishment.purchases[i]->currency <<  " " <<
            this->establishment.purchases[i]->price << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void app::total_earned() {
    std::cout << "--------------------------------------------" << std::endl;

    double total = 0;

    size_t count = this->establishment.purchases.size();
    for (size_t i = 0; i < count; i++) {
        total += (this->establishment.purchases[i]->price * this->establishment.purchases[i]->quantity);
    }
    std::cout << "Total earned until now is: R$ " << total << "\n" << std::endl;
}

void app::add_balance() {
    std::cout << "Amount: " << std::ends;

    std::string amount;
    std::getline(std::cin, amount);

    std::cout << "\n" << std::endl;

    std::stringstream ss(amount);
    double value;
    ss >> value;

    this->current_client->add_balance(value);
}

void app::buy_product() {
    std::cout << "Product code to buy: " << std::ends;

    std::string code;
    std::getline(std::cin, code);

    std::cout << "\n" << std::endl;

    Product* product = this->establishment.get_product_by_code(code);

    if (product->quantity <= 0) {
        std::cout << "Sorry, we don't have anymore of " << product->name << std::endl;
    } else if (product->price > this->current_client->balance) {
        std::cout << "Sorry, you don't have enough balance." << std::endl;
    } else {
        this->establishment.sell(product);
        this->current_client->buy(product);
        std::cout << "You bought 1 " << product->measure << " of " << product->name << "!!!" << std::endl;
    }
}

void app::show_bag() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << this->current_client->name << "'s bag\n" << std::endl;

    size_t count = this->current_client->bag.size();
    for (size_t i = 0; i < count; i++) {
        std::cout << this->current_client->bag[i]->quantity << " x " << this->current_client->bag[i]->name << " - " << this->current_client->bag[i]->currency <<  " " <<
            this->current_client->bag[i]->price << std::endl;
    }

    std::cout << "\n" << std::endl;
}

bool handle_menus(app* app) {
    if (app->current_client == nullptr) {
        return open_establishment_menu(app);
    } else {
        return open_client_menu(app);
    }

    // impossible
    return false;
}

bool open_establishment_menu(app* app) {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Supermarket 1.0" << "\n\n" << std::endl;
    std::cout << "Select an action below: " << "\n\n" << std::endl;
    std::cout << "1) Login as client" << "\n" << std::endl;
    std::cout << "2) List products" << "\n" << std::endl;
    std::cout << "3) List purchases" << "\n" << std::endl;
    std::cout << "4) Total earned" << "\n" << std::endl;
    std::cout << "0) End" << "\n\n" << std::endl;
    std::cout << "Type here: " << std::ends;

    std::string choice;
    std::getline(std::cin, choice);

    // skip 1 line to show response
    std::cout << "\n" << std::endl;

    if (!std::isdigit(choice[0])) {
        std::cout << "Invalid option... Try again" << std::endl;
        return true;
    }

    int selected = std::stoi(choice);

    // terminate
    if (selected == 0) {
        std::cout << "Terminating..." << std::endl;
        return false;
    } else if (selected == 1) {
        app->login();
    } else if (selected == 2) {
        app->list_products();
    } else if (selected == 3) {
        app->list_purchases();
    } else if (selected == 4) {
        app->total_earned();
    } else {
        std::cout << "Option doesn't exist..." << std::endl;
    }

    // true means open menu again
    return true;
}

bool open_client_menu(app* app) {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Welcome " << app->current_client->name << "!!!" << std::endl;
    std::cout << "Your balance at the moment is (" << app->current_client->balance << ")\n\n" << std::endl;
    std::cout << "Select an action below: " << "\n\n" << std::endl;
    std::cout << "1) Buy" << "\n" << std::endl;
    std::cout << "2) Add balance" << "\n" << std::endl;
    std::cout << "3) See bag" << "\n" << std::endl;
    std::cout << "4) List products" << "\n\n" << std::endl;
    std::cout << "0) Close" << "\n\n" << std::endl;
    std::cout << "Type here: " << std::ends;

    std::string choice;
    std::getline(std::cin, choice);

    std::cout << "\n" << std::endl;

    if (!std::isdigit(choice[0])) {
        std::cout << "Invalid option... Try again" << std::endl;
        return true;
    }

    int selected = std::stoi(choice);
    if (selected == 0) {
        std::cout << "Closing..." << "\n\n" << std::endl;
        app->current_client->dump_bag();
        app->current_client = nullptr;
    } else if (selected == 1) {
        app->buy_product();
    } else if (selected == 2) {
        app->add_balance();
    } else if (selected == 3) {
        app->show_bag();
    } else if (selected == 4) {
        app->list_products();
    } else {
        std::cout << "Option doesn't exist..." << std::endl;
    }

    return true;
}