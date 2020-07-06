#ifndef account_h
#define account_h

#include <string>

class Account {
    public:
        std::string number;
        std::string owner;
        double balance;

        bool withdraw(double value);
        void deposit(double value);
        bool transfer(double value, Account &account);

        Account(std::string _owner, std::string _number);
};

#endif