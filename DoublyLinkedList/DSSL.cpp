#include "DSLL.hpp"
#include <iostream>


DSLL::DSLL(int *A, int size_a){
    first = new Node;
    first->data = A[0];
    first->prev = nullptr;
    first->next = nullptr;

    last = first;

    for (int i = 1; i < size_a; ++i){
        Node *temp = new Node;
        temp->prev = last;
        temp->data = A[i];
        temp->next = last->next;

        last->next = temp;
        last = temp;
    }
    std::cout << "|Doubly Singly linked list| created" << std::endl;
}

DSLL::~DSLL(){
    Node *p = first;

    while(first){
        first = first->next;
        delete  p;
        p = first;
    }
    std::cout << "|Doubly Singly linked list| deleted" << std::endl;
}

int DSLL::countDSLL(){
    Node* p = first;
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

int DSLL::sumDSLL(){
    Node* p = first;
    int sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void DSLL::printDSSL(){
    Node *p = first;
    
    while(p){
        std::cout << p->data << " -> ";
        p = p->next;
    }
        std::cout << "\\0" << std::endl;
}

void DSLL::insertDSLL(int index, int x){
// index instruction 
//  (1) (2) (3) (4)
// 0   1   2   3   4
    
    if (index < 0 || index > countDSLL()){
        std::cout << "Invalid operation: out of range" << std::endl;
        exit(0);
    }

    if (index == 0){
        Node *temp = new Node;
        temp->data = x;
        temp->next = first;
        temp->prev = nullptr;

        first->prev = temp;

        first = temp;
    } else {
        Node *p = first;
        Node *temp = new Node;
        temp->data = x;

        for (int i = 0; i < index - 1; ++i){
            p = p->next;
        }

        temp->next = p->next;
        temp->prev = p;

        if (p->next)
            p->next->prev = temp;
        p->next = temp;
    }
}

int DSLL::deleteDSLL(int index){
// index instruction 
//  (1) (2) (3) (4)
//   1   2   3   4  
    int x = -1;
    
    if (index < 1 || index > countDSLL()){
        std::cout << "Invalid operation: out of range" << std::endl;
        exit(0);
    }

    if (index == 1){
        Node* p = first;
        first = first->next;
        x = p->data;
        delete p;  

        if (first)
            first->prev = nullptr;  
    } else {
        Node* p = first;

        for (int i = 0; i < index - 1; ++i)
            p = p->next;

        p->prev->next = p->next;
        if (p->next)  // check if the next of p is valid
            p->next->prev = p->prev;

        x = p->data;
        delete p;       
    }
    return x;
}

void DSLL::reverseLink(){
    Node* p = first;
    Node* temp;
    
    last = first;

    while (p){
        temp = p->next; // swap the values in the class. simple
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if (p != nullptr && p->next == nullptr){
            first = p;

        }
    }
}










