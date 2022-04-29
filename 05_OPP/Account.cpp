#include "Account.hpp"

bool Account::deposit(double input){
    balance += input;
    std::cout << "Deposit" << std::endl;
    return true;
}

bool Account::withdraw(double input){
    balance -= input;
    std::cout << "Withdraw" << std::endl;
    return true;
}

void Account::printInfo(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}