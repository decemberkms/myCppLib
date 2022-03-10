#ifndef _SLL_H_
#define _SLL_H_

#include "Node.hpp"

class SLL{
private:
    Node *first;

public:
    SLL(){first = nullptr;}
    ~SLL();

    void print();
    bool insert();
    
};


#endif 