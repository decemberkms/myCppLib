#include <iostream>
#include <vector>

class Account {
private:
    int balance;
public:
    virtual void withdraw(){
        std::cout << "Account" << std::endl;
    }

    virtual ~Account(){

    }
};

class Checking : public Account {
public:
    virtual void withdraw(){
        std::cout << "Checking" << std::endl;
    }
};

class Savings : public Account {
public:
    virtual void withdraw(){
        std::cout << "Savings" << std::endl;
    }
};

class Trust : public Account {
public:
    virtual void withdraw(){
        std::cout << "Trust" << std::endl;
    }
};

void do_something(Account &account, double amount) {
    account.withdraw();
}

int main(){
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    Account *p4 = new Trust();
    
    p1->withdraw();
    p2->withdraw();
    p3->withdraw();
    p4->withdraw();


    Account *array[] = {p1, p2, p3, p4};
    for (auto i = 0; i < 4; ++i)
        array[i]->withdraw();
    

    std::vector<Account *> accounts {p1, p2, p3, p4};

    std::cout << "Here" << std::endl;
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw();


    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
    std::cout << "Heredddddddddddddddd" << std::endl;
    do_something(a1, 1000);
    do_something(a2, 1000);
    do_something(a3, 1000);
    do_something(a4, 1000);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    return 0;
}