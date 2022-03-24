#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include "Node.hpp"

// Doubly circular linked list

class List{
private:
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
    List(List &&rhs);
    
    
    /*** Destructor ***/
    ~List();

    
    /*** Overloaded oeprators ***/
    // copy assignment operator
    List& operator=(const List& rhs);
    //move assignment operator
    List& operator=(List &&rhs);    

    
    /*** Functions ***/
    void insertList(int index, int key);
    void insertListLast(int key);

    int deleteList(int index);

    void deleteDuplinSortedList();

    void printList();
    void printReList();

    int countList() const;
    int sumList();

    int maxList();
    int minList();

    bool ifSorted();
    
    Node* searchList(int value);

    void reverseEleList();

    friend void concatList(List &first, List &second); 
    // void mergeSLL(SLL &latter); // latter will be null pointer

    Node* getHead(){return m_head;};
    Node* getTail(){return m_tail;};
};

#endif