#ifndef _SAVINGS_ACCOUNT_H
#define _SAVINGS_ACCOUNT_H
#include "Account.hpp"

class Savings_Account: public Account {
public:
    Savings_Account();
    ~Savings_Account();

    void deposit(double amount){
        std::cout << "Savings Account deposit called" << std::endl;
    }

    void withdraw(double amount){
        std::cout << "Savings Account withdraw called" << std::endl;
    }

};


#endif
