#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account {
    // attributes
private:
    std::string name {"deauflt"};
    double balance {0.0};
    static int num_accounts;

public:
    static int get_num_accounts();

    //constructor
    // Account() = default;

    // Account(std::string name_var)
    //     :name{name_var}, balance{0} {}

    // Account()
    //     :Account {"None", 0} {
    //         std::cout << "No arg!" << std::endl;
    //     }
    // //delegating constructor
    // Account(std::string name_var)
    //     :Account {name_var, 0} {}
    
    // simplifying constructor with default values
    Account(std::string name_var = "None", double balance_var = 0)
        :name{name_var}, balance{balance_var} {
            ++num_accounts;
        }

    //copy constructor // if not provid - default memberwise copy 
    Account(const Account &rhs)
        :Account {rhs.name, rhs.balance}{
    }

    //destructor
    ~Account(){
        --num_accounts;
    };

    // methods
    bool deposit(double input); 
    bool withdraw(double input);
    void printInfo();

    void set_balance (double bal) {balance = bal;}
    double getBalance() const {return balance;}

    void set_name(std::string name_var){name = name_var;}
    std::string getName() const {return name;}

    // operator overloading
    /// copy assignment
    Account &operator=(const Account &rhs);
    Account &operator=(Account &&rhs);
    
    Account operator-() const;
    Account operator++(); // pre
    Account operator++(int); // post 
    bool operator!() const;
    
    Account operator+(const Account &rhs);
    Account operator-(const Account &rhs) const;
    bool operator==(const Account &rhs) const;
    bool operator<(const Account &rhs) const;
    
};

#endif