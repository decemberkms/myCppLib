#ifndef _SLL_H_
#define _SLL_H_

#include "Node.hpp"
#include <iostream>

class SLL{
private:
    Node *first;

public:
    SLL();
    SLL(int A[], int n);

    ~SLL();

    void printSLL();
    void printSLLrec(Node *p);
    
    bool insertSLL(int index, int x);
    int deleteSLL(int index);
    
    int countSLL();
    int sumSLL();

    int MaxSLL(Node *p);
    int MinSLL(Node *p);

    Node *searchSLL(int key);
    Node *searchSLLrec(Node *p, int key);

    Node *getFirst();
};


#endif 