#include "CSLL.hpp"

CSLL::CSLL(){
    head = nullptr;
}

CSLL::CSLL(int *A, int n){
    Node *temp;
    Node *tail;
 
    // Create first node
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;

    //Create nodes
    for (int i = 1; i < n; ++i){
        temp = new Node;
        temp->data = A[i];
        temp->next = tail->next; // tail->next == head

        // point last's next to temp
        tail->next = temp;
        // set last = temp
        tail = temp;       
    }
    std::cout << "|Circularly Singly linked list| created" << std::endl;
}

CSLL::~CSLL(){
    Node *p = head;

    while(p->next != head){
        p = p->next;
    }

    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head){
        delete head;
        head = nullptr;
    }
    std::cout << "|Circularly Singly linked list| deleted" << std::endl;
}

Node *CSLL::getHead(){
    return head;
}

void CSLL::printCSLL(){
    Node *p = head;
    std::cout << "Head starts -> ";
    do {
         std::cout << p->data << " -> ";
         p = p->next;
    } while(p != head);
    std::cout << "back to Head "<<std::endl;

}

// void CSLL::printCSLLrec(Node *p){
//     if (p != nullptr){
//         std::cout << p->data << " -> ";
//         CSLL::printCSLLrec(p->next);
//     }
//     // std::cout << "\\0" << std::endl;
// }

// int CSLL::countCSLL(){
//     Node *p = first;
//     int count = 0;

//     while(p){
//         ++count;
//         p = p->next;    
//     }

//     return count;
// }

// bool CSLL::insertCSLL(int index, int x){
//     Node *temp, *p = first;
    
//     // sanity check
//     if (index < 0 || index > countCSLL()){
//         std::cout << "Invalid operation" << std::endl;
//         return false;
//     }
    
//     // create temp node for new node
//     temp = new Node;
//     temp->data = x;
//     temp->next = nullptr;

//     // put the new node into the position
//     if (index == 0){
//         temp->next = first;
//         first = temp;
//     } else{
//         for (int i = 0; i < index -1; ++i)
//             p = p->next;
        
//         temp->next = p->next;
//         p->next = temp;
//     }
//     return true;
// }

// int CSLL::deleteCSLL(int index){
//     index++;
//     Node *p, *q =nullptr;

//     int x = -1;

//     // sanity check
//     if (index < 0 || index > countCSLL()){
//         std::cout << "Invalid operation" << std::endl;
//         return -1;
//     }

//     if (index == 1){
//         p = first;
//         first = first->next;
//         x = p->data;
//         delete p;
//     } else{
//         p = first;

//         for (int i = 0; i < index - 1; ++i){
//             q = p;
//             p = p->next;
//         }

//         q->next = p->next;
//         x = p->data;

//         delete p;
//     }

//     return x;
// }

// void CSLL::insertLastCSLL(int x){
    
//     Node *temp = new Node;
//     temp->data = x;
//     temp->next = nullptr;

//     if (first == nullptr)
//         first = last = temp;
//     else {
//         last->next = temp;
//         last = temp;
//     } 
// }

// void CSLL::insertInSortedCSLL(int x){
//     Node *q;
//     Node *p = first;
    
//     Node *temp = new Node;
//     temp->data = x;
//     temp->next = nullptr;

//     if (first == nullptr){
//         first = temp;
//     } else{
//         while(p && p->data < x) {
//             q = p;
//             p = p->next;
//         }
//         if(p == first){
//             temp->next = first;
//             first = temp;
//         } else{
//             temp->next = q->next;
//             q->next = temp;
//         }    
//     }
// }

// bool CSLL::ifSortedCSLL(){
//     int x = INT8_MIN;
//     Node *p = first;
    
//     while(p){
//         if (p->data < x)
//             return false;
//         x = p->data;
//         p = p->next;
//     }
//     return true;
// }

// void CSLL::deleteDuplinSortedCSLL(){
//     Node *p = first;
//     Node *q = first->next;

//     while (q){
//         if (p->data != q->data){
//             p = q;
//             q = q->next;
//         } else {
//             p->next = q->next;
//             std::cout << q->data << " is deleted (duplicate)" << std::endl;
//             delete q;
//             q = p->next;
//         }
//     }
// }

// int CSLL::sumCSLL(){
//     Node *p = first;
//     int sum = 0;

//     while (p){
//         sum += p->data;
//         p = p->next;
//     }
//     return sum;
// }

// int CSLL::MaxCSLL(Node *p){
//     // std::cout << &first << std::endl;
//     // std::cout << &p << std::endl;
//     int max = INT8_MIN;

//     while(p){
//         if (p->data > max)
//             max = p->data;
//         p = p->next;
//     }    
//     return max;
// };

// int CSLL::MinCSLL(Node *p){
//     int min = INT8_MAX;

//     while(p){
//         if (p->data < min)
//             min = p->data;
//         p = p->next;
//     }    
//     return min;
// }

// void CSLL::reverseEleCSLL(){
//     Node *p = first;
//     int i = 0;
//     int A[countCSLL()];

//     while(p){
//         A[i] = p->data;
//         p = p->next;
//         i++;
//     }

//     p = first;
//     i--;

//     while(p){
//         p->data = A[i--];
//         p = p->next;
//     }
// }
    
// void CSLL::reverseLinkCSLL(){
//     // sliding pointers 
//     Node *p = first;
//     Node *q = nullptr;
//     Node *r = nullptr;

//     while(p){
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }
// }

// void CSLL::reverseLinkCSLLrec(Node *q, Node* p){
//     if (p){
//         CSLL::reverseLinkCSLLrec(p, p->next);
//         p->next = q;
//     } else
//         first = q;
// }

// void CSLL::concatCSLL(CSLL &later){
//     Node *p = first;

//     while(p->next){
//         p = p->next;
//     }
//     p->next = later.getFirst();  

//     Node *z = later.first; // remove latter
//     while(later.first){
//         later.first = nullptr;
//         z = z->next;
//         later.first = z;
//     }
// }

// void CSLL::mergeCSLL(CSLL &latter){
//     Node *ending;
//     Node *p = this->getFirst();
//     Node *q = latter.getFirst();

//     Node *third;

//     if(p->data < q->data){
//         third = ending = p;
//         p = p->next;
//         third->next = nullptr;        
//     } else {
//         third = ending = q;
//         q = q->next;
//         third->next = nullptr;
//     }

//     while (p && q) {
//         if (p->data < q->data){
//             ending->next = p;
//             ending = p;
//             p = p->next;
//             ending->next = nullptr;
//         } else {
//             ending->next = q;
//             ending = q;
//             q = q->next;
//             ending->next = nullptr;
//         }
//     }

//     if (p) ending->next = p;
//     if (q != nullptr) ending->next = q;

//     this->first = third;
    
//     Node *z = latter.first; //remove latter
//     while(latter.first){
//         latter.first = nullptr;
//         z = z->next;
//         latter.first = z;
//     }    
// }

// bool CSLL::isLoop(){
//     Node *p = first;
//     Node *q = first;

//     do {
//         p = p->next;
//         q = q->next;

//         q = q != nullptr ? q->next : nullptr;
        
//     } while( p && q && p != q);

//     return p == q ? true : false;
// }

// Node *CSLL::searchCSLL(int key){  
//     Node *p = first;
//     while (p){
//         if(p->data == key){
//             std::cout << "The key has been found in the list" << std::endl;
//             return p;
//         }
//         p = p->next;
//     }
//     std::cout << "The key is not in the list" << std::endl;
//     return nullptr;
// }

// Node *CSLL::searchCSLLrec(Node *p, int key){
//     if (p == nullptr){
//         std::cout << "The key is not in the list" << std::endl;
//         return nullptr;
//     }
//     if (p->data == key){
//         std::cout << "The key has been found in the list" << std::endl;
//         return p;
//     }
//     return CSLL::searchCSLLrec(p->next, key);       
// }



