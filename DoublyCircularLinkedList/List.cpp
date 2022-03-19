#include "List.hpp"

using namespace  std;

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

List::~List(){
    cout << "|List destructor| Deleted - head address: " << m_head << endl;
    Node* temp = m_head;
    cout << m_head->data << endl;

    if (m_head->next == m_head)
        delete m_head;

    do {
        cout << m_head->data << endl;
        
        m_head = m_head->next;
        delete m_head;
        temp = m_head;
    } while(m_head->next != m_head);
  
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