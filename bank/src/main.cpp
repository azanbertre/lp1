#include <iostream>
#include "account.h"
#include "agency.h"
#include "client.h"

int main(int argc, char const *argv[])
{

    Agency ag("Agency1",  "123456");

    Client c1("Name1", "123");
    Client c2("Name2", "456");

    Account acc1(c1, ag);
    Account acc2(c2, ag);

    std::cout << "Conta:\t" << acc1.agency.number << "\t" << acc2.agency.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    std::cout << "\nDepositando 1000 & 300" << std::endl;
    acc1.deposit(1000);
    acc2.deposit(300);

    std::cout << "Conta:\t" << acc1.agency.number << "\t" << acc2.agency.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    std::cout << "\nTransferência de 600" << std::endl;

    acc1.transfer(600, acc2);

    std::cout << "Conta:\t" << acc1.agency.number << "\t" << acc2.agency.number << std::endl;
    std::cout << "Saldo:\t" << acc1.balance << "\t" << acc2.balance << std::endl;

    return 0;
}