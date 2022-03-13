#include "SLL.hpp"
#include <iomanip>

int main(){
    // int A[] = {1,2,3,4,5,6,7};
    // int size_n = sizeof(A)/sizeof(int);

    // SLL myList1(A, size_n);
    // myList1.printSLL(); 

    // myList1.insertSLL(0, 100);
    // myList1.printSLL(); 
    // myList1.insertSLL(1, 200);
    // myList1.printSLL(); 
    // myList1.insertSLL(9, 300);
    // myList1.printSLL(); 

    // myList1.deleteSLL(0);
    // myList1.printSLL(); 
    // // myList1.~SLL();
    // myList1.printSLLrec(myList1.getFirst());

    // std::cout << std::endl;
    // std::cout << myList1.MaxSLL(myList1.getFirst()) << std::endl;
    // std::cout << myList1.MinSLL(myList1.getFirst()) << std::endl;
    // myList1.printSLL(); 

    // myList1.searchSLL(2);
    // myList1.printSLL();
    
    // myList1.searchSLLrec(myList1.getFirst(), 3);
    // myList1.printSLL();


    SLL myList2;
    for (int i = 0; i < 10; ++i)       
           myList2.insertLastSLL(i);
    myList2.printSLL();
    
    std::cout << std::boolalpha << myList2.ifSortedSLL() << std::endl;

    return 0;
}