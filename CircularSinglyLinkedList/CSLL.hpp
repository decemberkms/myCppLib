#ifndef _CSLL_H_
#define _CSLL_H_

#include "Node.hpp"
#include <iostream>

class CSLL{
private:
    Node *head;

public:
    CSLL();
    CSLL(int A[], int n);

    ~CSLL();

    void printCSLL();
    // void printCSLLrec(Node *p);
    
    // bool insertCSLL(int index, int x);
    // void insertLastCSLL(int x);
    // void insertInSortedCSLL(int x);
    // int deleteCSLL(int index);
    
    // bool ifSortedCSLL();
    // void deleteDuplinSortedCSLL();
    
    // int countCSLL();
    // int sumCSLL();

    // int MaxCSLL(Node *p);
    // int MinCSLL(Node *p);

    // void reverseEleCSLL();
    // void reverseLinkCSLL();
    // void reverseLinkCSLLrec(Node *q, Node* p);

    // void concatCSLL(CSLL &latter); // latter will be null pointer
    // void mergeCSLL(CSLL &latter); // latter will be null pointer

    // bool isLoop();

    // Node *searchCSLL(int key);
    // Node *searchCSLLrec(Node *p, int key);

    Node *getHead();

};


#endif 