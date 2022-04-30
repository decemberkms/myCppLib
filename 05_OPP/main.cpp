#include "Account.hpp"
#include <iostream>

int main(){
    // Account min_accout; // default constructor
    // parameter - >()
    Account min_accout("Min", 2000.0); 
    Account pee_account("Pee", 300.0);
    Account default_account;
    Account *pointer_accout = new Account("Pointer", 1000.0);

    min_accout.printInfo();
    pee_account.printInfo();
    default_account.printInfo();
    pointer_accout->printInfo();
    delete pointer_accout;

    min_accout.deposit(100.0);
    min_accout.printInfo();

    
    return 0;
}