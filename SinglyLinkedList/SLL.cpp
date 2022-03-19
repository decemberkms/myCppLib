#include "SLL.hpp"

SLL::SLL(){
    first = last = nullptr;
       std::cout << "|Singly linked list| no args constuctor (first address: " << first  << ")" << std::endl;
}

SLL::SLL(int A[], int n){
    Node *temp;
    
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
    std::cout << "|Singly linked list| args constructor (first address: " << first << ")" << std::endl;
}

SLL::SLL(const SLL &source){  // copy constructor
    std::cout << "|Singly linked list| Copy constuctor (first address - rhs: " << source.first << ")"<< std::endl;
    // free memory for alreay exist
   
    Node *p_old = first;

    // std::cout << "First data " << p->data << std::endl;
    if (p_old){
        while(first){
            first = first->next;
            delete p_old;
            p_old = first;
        }
    }
    //
  
    Node *temp;

    first = new Node;
    first->data = source.first->data;
    first->next = source.first->next;
    
    last = first;
    
    Node *p = source.first;
    source.countSLL();
    p = p->next;
    
    //Create nodes
    for (int i = 1; i < source.countSLL(); ++i){
        temp = new Node;
        temp->data = p->data;
        temp->next = nullptr;

        p = p->next;
        // point last's next to temp
        last->next = temp;
        // set last = temp
        last = temp;
    }
    std::cout << "|Singly linked list| Copy constuctor (first address - lsh: " << first << ")"<< std::endl;
    
    
}

SLL::SLL(SLL &&rhs) noexcept  // move consturcot
    : first{nullptr}, last{nullptr} {
        
    std::swap(first, rhs.first);
    std::swap(last, rhs.last);    
    std::cout << "|Singly linked list| Move constuctor (first address - rhs: " <<  rhs.first << ")" << std::endl;
    std::cout << "|Singly linked list| Move constuctor (first address - lhs: " <<  first << ")" << std::endl;    
}

SLL& SLL::operator= (const SLL &rhs){ // copy assignment operator
    std::cout << "|Singly linked list| copy assignment operator (first address - rhs: " <<  rhs.first << std::endl;
    Node *temp;

    first = new Node;
    first->data = rhs.first->data;
    first->next = rhs.first->next;
    
    last = first;
    
    Node *p = rhs.first;
    rhs.countSLL();
    p = p->next;
    
    //Create nodes
    for (int i = 1; i < rhs.countSLL(); ++i){
        temp = new Node;
        temp->data = p->data;
        temp->next = nullptr;

        p = p->next;
        // point last's next to temp
        last->next = temp;
        // set last = temp
        last = temp;
    }
    std::cout << "|Singly linked list| copy assignment operator (first address - lhs: " << first << std::endl;
    return *this;
}

SLL& SLL::operator= (SLL &&rhs){ // move assignment operator
    std::cout << "|Singly linked list| Move assignment operator (first address - rhs: " << rhs.first << std::endl;
    if(this == &rhs) return *this;
    
    first = rhs.first;
    last = rhs.last;

    rhs.first = nullptr;
    rhs.last = nullptr;
    // std::swap(first, rhs.first);
    // std::swap(last, rhs.last); 
    std::cout << "|Singly linked list| Move assignment operator (first address - lhs: " << first << std::endl;
    return *this;
}

SLL::~SLL(){
    Node *p = first;

    std::cout << "|Singly linked list| deleted for the first addess: " << p << std::endl;
    // std::cout << "First data " << p->data << std::endl;

    while(first){
        first = first->next;
        delete p;
        p = first;
    }
    
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
        std::cout << p->data << " -> ";
        SLL::printSLLrec(p->next);
    }
    // std::cout << "\\0" << std::endl;
}

int SLL::countSLL() const {
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
        std::cout << "|Singly linked list| Insert - first address: " << first << std::endl;
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

void SLL::insertLastSLL(int x){
    
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if (first == nullptr) {
        first = last = temp;
        std::cout << "|Singly linked list| Insert - first address: " << first << std::endl;
    }
    else {
        last->next = temp;
        last = temp;
    } 
}

void SLL::insertInSortedSLL(int x){
    Node *q;
    Node *p = first;
    
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if (first == nullptr){
        first = temp;
    } else{
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == first){
            temp->next = first;
            first = temp;
        } else{
            temp->next = q->next;
            q->next = temp;
        }    
    }
}

bool SLL::ifSortedSLL(){
    int x = INT8_MIN;
    Node *p = first;
    
    while(p){
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void SLL::deleteDuplinSortedSLL(){
    Node *p = first;
    Node *q = first->next;

    while (q){
        if (p->data != q->data){
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            std::cout << q->data << " is deleted (duplicate)" << std::endl;
            delete q;
            q = p->next;
        }
    }
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

int SLL::MaxSLL(Node *p){
    // std::cout << &first << std::endl;
    // std::cout << &p << std::endl;
    int max = INT8_MIN;

    while(p){
        if (p->data > max)
            max = p->data;
        p = p->next;
    }    
    return max;
};

int SLL::MinSLL(Node *p){
    int min = INT8_MAX;

    while(p){
        if (p->data < min)
            min = p->data;
        p = p->next;
    }    
    return min;
}

void SLL::reverseEleSLL(){
    Node *p = first;
    int i = 0;
    int A[countSLL()];

    while(p){
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first;
    i--;

    while(p){
        p->data = A[i--];
        p = p->next;
    }
}
    
void SLL::reverseLinkSLL(){
    // sliding pointers 
    Node *p = first;
    Node *q = nullptr;
    Node *r = nullptr;

    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
}

void SLL::reverseLinkSLLrec(Node *q, Node* p){
    if (p){
        SLL::reverseLinkSLLrec(p, p->next);
        p->next = q;
    } else
        first = q;
}

void SLL::concatSLL(SLL &later){
    Node *p = first;

    while(p->next){
        p = p->next;
    }
    p->next = later.getFirst();  

    Node *z = later.first; // remove latter
    while(later.first){
        later.first = nullptr;
        z = z->next;
        later.first = z;
    }
}

void SLL::mergeSLL(SLL &latter){
    Node *ending;
    Node *p = this->getFirst();
    Node *q = latter.getFirst();

    Node *third;

    if(p->data < q->data){
        third = ending = p;
        p = p->next;
        third->next = nullptr;        
    } else {
        third = ending = q;
        q = q->next;
        third->next = nullptr;
    }

    while (p && q) {
        if (p->data < q->data){
            ending->next = p;
            ending = p;
            p = p->next;
            ending->next = nullptr;
        } else {
            ending->next = q;
            ending = q;
            q = q->next;
            ending->next = nullptr;
        }
    }

    if (p) ending->next = p;
    if (q != nullptr) ending->next = q;

    this->first = third;
    
    Node *z = latter.first; //remove latter
    while(latter.first){
        latter.first = nullptr;
        z = z->next;
        latter.first = z;
    }    
}

bool SLL::isLoop(){
    Node *p = first;
    Node *q = first;

    do {
        p = p->next;
        q = q->next;

        q = q != nullptr ? q->next : nullptr;
        
    } while( p && q && p != q);

    return p == q ? true : false;
}

Node *SLL::searchSLL(int key){  
    Node *p = first;
    while (p){
        if(p->data == key){
            std::cout << "The key has been found in the list" << std::endl;
            return p;
        }
        p = p->next;
    }
    std::cout << "The key is not in the list" << std::endl;
    return nullptr;
}

Node *SLL::searchSLLrec(Node *p, int key){
    if (p == nullptr){
        std::cout << "The key is not in the list" << std::endl;
        return nullptr;
    }
    if (p->data == key){
        std::cout << "The key has been found in the list" << std::endl;
        return p;
    }
    return SLL::searchSLLrec(p->next, key);       
}



