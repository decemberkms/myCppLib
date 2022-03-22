#include "List.hpp"

using namespace  std;

int List::countList() const{
    Node *temp = m_head;

    if (m_head == nullptr){
        cout << "|List count| Invalid operation" << endl;
        exit(0);
    }
        

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

List::List(List &&rhs){
    cout << "|List constructor| Move - head address (rhs): " << rhs.m_head << endl;
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;

    // if (m_head != nullptr){
    //     for (int i = 0; i < rhs.countList(); ++i){
            
    //     }
    // }
    rhs.m_head = rhs.m_tail = nullptr;
    
    cout << "|List constructor| Move - head address (lhs): " << m_head << endl;
}

List::~List(){
    cout << "|List destructor| Deleted - head address: " << m_head << endl;
    Node* temp = m_head;
    if (m_head == nullptr){
        delete m_head;
    } else {
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
            m_head = m_tail = nullptr;
        }
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

List& List::operator=(List &&rhs){
    cout << "|List assignment| Move - head address (rhs): " << rhs.m_head << endl;
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
        m_head = m_tail = nullptr;
    }

    m_head = rhs.m_head;
    m_tail = rhs.m_tail;

    rhs.m_head = rhs.m_tail = nullptr;
    cout << "|List assignment| Move - head address (lhs): " << m_head << endl;
    return *this;
}

int List::maxList(){
    Node *temp = m_head;
    int max = INT8_MIN;

    do {
        if (temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    } while(temp != m_head);

    return max;
}

int List::minList(){
    Node *temp = m_head;
    int min = INT8_MAX;

    do {
        if (temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    } while(temp != m_head);

    return min;
}

void List::printList(){
    if (m_head == nullptr){
        cout << "|List print| Invalid operation" << endl;
        exit(0);
    }

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

        if (index == countList())
            m_tail = temp;
    }
}

void List::insertListLast(int key){
    //insert only at the end
    // Create a new node with a data

    Node *temp, *p = m_head;
    temp = new Node;
    temp->data = key;

    if (m_head == nullptr){
        temp->next = temp;
        temp->prev = temp;
        m_head = m_tail = temp;
        // m_head = temp;
        // m_head->next = m_head;
        // m_head->prev = m_head;
        // m_head = m_tail;
    } else{
        if (m_head->next == m_head){
            m_tail = temp;

            m_tail->next = m_head;
            m_head->next = m_tail;
            
            m_tail->prev = m_head;
            m_head->prev = m_tail;       
        } else{
            p->prev->next = temp;
            temp->prev = p->prev;

            p->prev = temp;
            temp->next = p;
            
            m_tail = temp;
        }
    }
}

int List::deleteList(int index){
    // index instruction
    // List:    1   2   3   4   5
    // Index:  (1) (2) (3) (4) (5)
    int x = -1; //default value;

    if (m_head == nullptr){
        cout << "|List deletion| Invalid operation - list is already empty" << endl;
        exit(0);
    }

    if (index <= 0 || index > countList()){
        cout << "|List deletion| Invalid operation - index out of range" << endl;
        exit(0);
    }
    
    Node* temp;

    if (index == 1){
        temp = m_head;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        m_head = temp->next;
        x = temp->data;
        delete temp;
    } else{
        temp = m_head;

        for (int i = 0; i < index - 1; ++i){
            temp = temp->next;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        if (temp == m_tail){
            m_tail = temp->prev;
        }
        x = temp->data;
        delete temp;        
    }

    return x;
}



















