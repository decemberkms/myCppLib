#include "SLL.hpp"

SLL::SLL(){
    first = nullptr;
}

SLL::SLL(int A[], int n){
    Node *temp, *last;
    
    // Create first node
    first = new Node;
    first->data = A[0];
    first->next = nullptr;

    // set last = first;
    last = first;

    //Create nodes
    for (int i = 1; i < n; ++i){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;

        // point last's next to temp
        last->next = temp;
        // set last = temp
        last = temp;
    }
    std::cout << "|Singly linked list| created" << std::endl;
}

SLL::~SLL(){
    Node *p = first;

    while(first){
        first = first->next;
        delete p;
        p = first;
    }
    std::cout << "|Singly linked list| deleted" << std::endl;
}

Node *SLL::getFirst(){
    return first;
}


void SLL::printSLL(){
    Node *p = first;

    while(p != nullptr){
        std::cout << p->data << " -> ";
        p = p->next;
    }
    std::cout << "\\0" << std::endl;
}

void SLL::printSLLrec(Node *p){
    if (p != nullptr){
        std::cout << p->data << "->";
        SLL::printSLLrec(p->next);
    }

}

int SLL::countSLL(){
    Node *p = first;
    int count = 0;

    while(p){
        ++count;
        p = p->next;    
    }

    return count;
}

bool SLL::insertSLL(int index, int x){
    Node *temp, *p = first;
    
    // sanity check
    if (index < 0 || index > countSLL()){
        std::cout << "Invalid operation" << std::endl;
        return false;
    }
    
    // create temp node for new node
    temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    // put the new node into the position
    if (index == 0){
        temp->next = first;
        first = temp;
    } else{
        for (int i = 0; i < index -1; ++i)
            p = p->next;
        
        temp->next = p->next;
        p->next = temp;
    }
    return true;
}

int SLL::deleteSLL(int index){
    index++;
    Node *p, *q =nullptr;

    int x = -1;

    // sanity check
    if (index < 0 || index > countSLL()){
        std::cout << "Invalid operation" << std::endl;
        return -1;
    }

    if (index == 1){
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else{
        p = first;

        for (int i = 0; i < index - 1; ++i){
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;

        delete p;
    }

    return x;
}



int SLL::sumSLL(){
    Node *p = first;
    int sum = 0;

    while (p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}