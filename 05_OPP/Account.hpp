#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account {
    // attributes
private:
    std::string name {"deauflt"};
    double balance {0.0};
public:
    //constructor
    Account() = default;
    Account(std::string name_var, double balance_var)
        :name{name_var}, balance{balance_var} {}

    // methods
    bool deposit(double input); 
    bool withdraw(double input);
    void printInfo();

    void set_balance(double bal){balance = bal;}
    double getBalance(){return balance;}
};

#endif