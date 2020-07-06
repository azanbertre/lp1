#include <iostream>
#include "account.h"

int main(int argc, char const *argv[])
{
    Account acc1("Test", "01");
    Account acc2("Test2", "02");

    std::cout << "Conta:\t" << acc1.number << "\t" << acc2.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    std::cout << "\nDepositando 1000 & 300" << std::endl;
    acc1.deposit(1000);
    acc2.deposit(300);

    std::cout << "Conta:\t" << acc1.number << "\t" << acc2.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    std::cout << "\nTransferência de 600" << std::endl;

    acc1.transfer(600, acc2);

    std::cout << "Conta:\t" << acc1.number << "\t" << acc2.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    return 0;
}