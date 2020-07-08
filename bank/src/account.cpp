#include "account.h"

size_t Account::accountCount;

Account::Account(Client _client, Agency _agency) : client(_client), agency(_agency) {
    this->balance = 0.0f;
    this->accountCount += 1;
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