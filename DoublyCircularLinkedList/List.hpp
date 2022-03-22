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

    // void deleteDuplinSortedSLL();

    void printList();

    int countList() const;
    int sumList();

    int maxList();
    int minList();

    // bool isSorted();

    // Node* searchSLL(int key);


    Node* getHead(){return m_head;};
    Node* getTail(){return m_tail;};
};

#endif