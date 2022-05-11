#include <iostream>
#include <vector>

class Account {
private:
    int balance;
public:
    virtual void withdraw(){
        std::cout << "Account" << std::endl;
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


int main(){
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    Account *p4 = new Trust();
    
    p1->withdraw();
    p2->withdraw();
    p3->withdraw();
    p4->withdraw();

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    return 0;
}