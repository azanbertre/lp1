#ifndef app_h
#define app_h

#include <string>
#include "establishment.h"
#include "provider.h"
#include "client.h"

class app {
    public:
        Establishment establishment;
        Provider provider;
        Client* current_client;

        app();

        int run(int argc, char* argv[]);

        void login();
        void list_products();
        void list_provider_products();
        void list_purchases();
        void total_earned();
        void add_balance();
        void show_bag();
        void buy_product();
        void restock();
};

bool open_establishment_menu(app* app);
bool open_client_menu(app* app);
bool handle_menus(app* app);

#endif