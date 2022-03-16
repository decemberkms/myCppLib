#ifndef _DSLL_H_
#define _DSLL_H_
#include "Node.hpp"

class DSLL{
private:
    Node *first, *last;
public:
    DSLL(){first = nullptr;};
    DSLL(int *A, int size_a);
    ~DSLL();

    int countDSLL();
    int sumDSLL();
    
    void printDSSL();

    void insertDSLL(int index, int x);
    void deleteDSLL(int index);

    

    Node* getFirst(){return this->first;};

};


#endif 
