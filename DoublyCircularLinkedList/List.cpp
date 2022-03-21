#include "List.hpp"

using namespace  std;

int List::countList() const{
    Node *temp = m_head;

    int count = 0;
    do {
        temp = temp->next;
        count++;
    } while(temp != m_head);

    return count;
}

int List::sumList(){
    Node *temp = m_head;

    int sum = 0;
    do {
        sum = temp->data + sum;
        temp = temp->next;        
    } while(temp != m_head);

    return sum;
}

List::List(){
    m_head = m_tail = nullptr;
    cout << "|List constructor| No args - head address: " << m_head << endl;
}

List::List(int A[], int lstSize){
    Node* temp;

    // Create first node
    m_head = new Node;
    // set data
    m_head->data = A[0];
    // set pointer
    m_head->next = m_head;
    m_head->prev = m_head;
    // set head = tail
    m_tail = m_head;

    // Create nodes
    for (int i = 1; i < lstSize; ++i){
        temp = new Node;
        
        temp->data = A[i];

        temp->next = m_head;
        temp->prev = m_tail;
        
        
        m_tail->next = temp;
        m_tail = temp;
        m_head->prev = m_tail;
    }
    cout << "|List constructor| Args - head address: " << m_head << endl;
}

List::List(const List &rhs){
    Node* temp;
    
    m_head = new Node;
    m_head->data = rhs.m_head->data;
    m_head->next = m_head;
    m_head->prev = m_head;
    m_tail = m_head;

    Node* p = rhs.m_head;
    p = p->next;

    for (int i = 1; i < rhs.countList();++i){
        temp = new Node;
        
        temp->data = p->data;

        temp->next = m_head;
        temp->prev = m_tail;
        
        
        m_tail->next = temp;
        m_tail = temp;   
        m_head->prev = m_tail;
        p = p->next;
    }
 
    cout << "|List constructor| Copy - head address: " << m_head << endl;
}

List::~List(){
    cout << "|List destructor| Deleted - head address: " << m_head << endl;
    Node* temp = m_head;
   
    while (temp->next != m_head){
        temp = temp->next;
    }

    while (temp != m_head){
        temp->next = m_head->next;
        delete m_head;
        m_head = temp->next;
    }
 
    if (temp == m_head){
        delete m_head;
        m_head = nullptr;
    }
}

List& List::operator=(const List& rhs){
    cout << "|List assignment|- rhs: head address: " << rhs.m_head << endl;
    
    if (this == &rhs) return *this;
    // Remove List
    Node* temp_rm = m_head;
   
    while (temp_rm->next != m_head){
        temp_rm = temp_rm->next;
    }

    while (temp_rm != m_head){
        temp_rm->next = m_head->next;
        delete m_head;
        m_head = temp_rm->next;
    }
 
    if (temp_rm == m_head){
        delete m_head;
        m_head = nullptr;
    }
    //////////////////////////////////

    // Assign new list
    Node* temp;
    
    m_head = new Node;
    m_head->data = rhs.m_head->data;
    m_head->next = m_head;
    m_head->prev = m_head;
    m_tail = m_head;

    Node* p = rhs.m_head;
    p = p->next;

    for (int i = 1; i < rhs.countList();++i){
        temp = new Node;
        
        temp->data = p->data;

        temp->next = m_head;
        temp->prev = m_tail;
        
        
        m_tail->next = temp;
        m_tail = temp;   
        m_head->prev = m_tail;
        p = p->next;
    }
    /////////////////////////////

    cout << "|List assignment|- lhs: head address: " << m_head << endl;
    
    return *this;

}

void List::printList(){
    Node *temp = m_head;
    cout << "\n|Head address|: " << temp << endl;
    cout << "|Head starts| -> ";

    do {
         std::cout << temp->data << " -> ";
         temp = temp->next;
    } while(temp != m_head);

    cout << "|Back to head|\n" << endl;

}

void List::insertList(int index, int key){
    // index instruction
    // List:    1   2   3   4   5
    // Index:(0) (1) (2) (3) (4) (5)

    if (index < 0 || index > countList()){
        cout << "|List insertion| Invalid operation" << endl;
        exit(0);
    }

    // Create a new node with a data
    Node *temp, *p = m_head;
    temp = new Node;
    temp->data = key;

    if (index == 0){
        if(m_head == nullptr){
            m_head = temp;
            m_head->next = m_head;
            m_head->prev = m_head;
            m_head = m_tail;
        } else{
            temp->next = m_head;
            m_head->prev = temp;

            temp->prev = m_tail;
            m_tail->next = temp;

            m_head = temp;
        }
    } else {
        for (int i = 0; i < index; ++i)
            p = p->next;
        
        p->prev->next = temp;
        temp->prev = p->prev;

        p->prev = temp;
        temp->next = p;

    }
    
    
}













