#ifndef account_h
#define account_h

#include <string>
#include "client.h"
#include "agency.h"

class Account {
    public:
        Client client;
        Agency agency;
        double balance;
        static size_t accountCount;

        bool withdraw(double value);
        void deposit(double value);
        bool transfer(double value, Account &account);

        Account(Client _client, Agency _agency);
};

#endif