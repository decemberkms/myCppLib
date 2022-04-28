#include "Account.hpp"
#include <iostream>

int main(){
    // Account min_accout; // default constructor
    // parameter - >()
    Account min_accout("Min", 2000.0); 
    Account pee_account("Pee", 300.0);
    Account default_account;
    
    min_accout.printInfo();
    pee_account.printInfo();
    default_account.printInfo();
    return 0;
}