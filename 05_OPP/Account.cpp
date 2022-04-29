#include "Account.hpp"

bool Account::deposit(double input){
    balance += input;
    std::cout << "Deposit" << std::endl;
    return true;
}

bool Account::withdraw(double input){
    if (balance - input >= 0){
        balance -= input;
        std::cout << "Withdraw done" << std::endl;
        return true;
    } else {
        std::cout << "Not enough balance" << std::endl;
        return false;
    }
}

void Account::printInfo(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}