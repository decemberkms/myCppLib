#include "SLL.hpp"


int main(){
    int A[] = {1,2,3,4,5,6,7};
    int size_n = sizeof(A)/sizeof(int);

    SLL myList1(A, size_n);
    myList1.printSLL(); 

    myList1.insertSLL(0, 100);
    myList1.printSLL(); 
    myList1.insertSLL(1, 200);
    myList1.printSLL(); 
    myList1.insertSLL(9, 300);
    myList1.printSLL(); 

    myList1.deleteSLL(0);
    myList1.printSLL(); 

    myList1.printSLLrec(myList1.getFirst());

    return 0;
}