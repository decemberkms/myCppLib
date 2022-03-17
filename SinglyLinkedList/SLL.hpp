#ifndef _SLL_H_
#define _SLL_H_

#include "Node.hpp"
#include <iostream>

class SLL{
private:
    Node *first, *last;

public:
    SLL();
    SLL(int A[], int n);
    SLL(const SLL &source); //copy constructor
    SLL(SLL &&source); // move constructor

    ~SLL();

    void printSLL();
    void printSLLrec(Node *p);
    
    bool insertSLL(int index, int x);
    void insertLastSLL(int x);
    void insertInSortedSLL(int x);
    int deleteSLL(int index);
    
    bool ifSortedSLL();
    void deleteDuplinSortedSLL();
    
    int countSLL() const;  //const member function due to copy constructor - const SLL& source
    int sumSLL();

    int MaxSLL(Node *p);
    int MinSLL(Node *p);

    void reverseEleSLL();
    void reverseLinkSLL();
    void reverseLinkSLLrec(Node *q, Node* p);

    void concatSLL(SLL &latter); // latter will be null pointer
    void mergeSLL(SLL &latter); // latter will be null pointer

    bool isLoop();

    Node *searchSLL(int key);
    Node *searchSLLrec(Node *p, int key);

    Node *getFirst();

};


#endif 