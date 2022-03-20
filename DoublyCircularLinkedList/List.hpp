#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

// Doubly circular linked list

class List{
private:
    class Node{
    public:
        int data;
        Node * next;
        Node * prev;
    };

    Node* m_head;
    Node* m_tail;

public:
    /*** Constructors ***/
    // no args constructor
    List();
    // args constructor
    List(int A[], int lstSize);
    // copy constructor
    List(const List &rhs);
    // move constructor

    
    /*** Destructor ***/
    ~List();


    void printList();

    int countList();

    Node* getHead(){return m_head;};
    Node* getTail(){return m_tail;};
};

#endif