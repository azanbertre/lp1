#include "account.h"

Account::Account(std::string _owner, std::string _number) : number(_number), owner(_owner) {
    this->balance = 0.0f;
}

bool Account::withdraw(double value) {
    if (this->balance - value < 0) {
        return false;
    }
    this->balance -= value;
    return true;
}

void Account::deposit(double value) {
    this->balance += value;
}

bool Account::transfer(double value, Account &account) {
    if (this->withdraw(value)) {
        account.deposit(value);
        return true;
    }
    return false;
}