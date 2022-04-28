#include "Account.hpp"

bool Account::deposit(double input){
    balance += input;
    return true;
}

bool Account::withdraw(double input){
    balance -= input;
    return true;
}

void Account::printInfo(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}