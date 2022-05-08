#include "Account.hpp"

int Account::num_accounts = 0;

int Account::get_num_accounts(){
    return num_accounts;
}

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

Account &Account::operator=(const Account &rhs){
    if (this == &rhs)
        return *this;
    return *this;
}

Account &Account::operator=(Account &&rhs){
    if (this == &rhs)
        return *this;
    
    return *this;
}


// Account Account::operator-() const{
//     // balance = -balance;
// }
Account Account::operator++(){
    balance++;
} // pre
Account Account::operator++(int){
    balance++;
} // post 
bool Account::operator!() const{

}

Account Account::operator+(const Account &rhs){

}

Account Account::operator-(const Account &rhs) const{

}

// bool Account::operator==(const Account &rhs) const{
//     return (this->balance == rhs.balance);
// }

bool Account::operator<(const Account &rhs) const{
    return (this->balance < rhs.balance);
}

//global function

bool operator==(const Account &lsh, const Account &rhs){
    return (lsh.balance == rhs.balance);
}
Account operator-(const Account &obj){
    // obj.balance = -obj.balance;
}