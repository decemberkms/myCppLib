#include "DSLL.hpp"

int main(){

    int A[] = {1,2,3,4};
    int size_a = sizeof(A) / sizeof(int);

    DSLL myList1(A, size_a);
    myList1.printDSSL();

    // myList1.insertDSLL(0,5);
    // myList1.printDSSL();
    // myList1.insertDSLL(1,10);
    // myList1.printDSSL();
    // myList1.insertDSLL(6,100);
    // myList1.printDSSL();

    // myList1.deleteDSLL(1);
    // myList1.printDSSL();
    // myList1.deleteDSLL(3);
    // myList1.printDSSL();
    // myList1.deleteDSLL(2);
    // myList1.printDSSL();

    myList1.reverseLink();
    myList1.printDSSL();

    return 0;
}