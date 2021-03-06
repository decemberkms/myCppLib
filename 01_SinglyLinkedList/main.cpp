#include "SLL.hpp"
#include <iomanip>
#include <vector>

SLL myFunc1(int *A, int size_var){   
    return SLL(A, size_var);
}

int main(){
    int A[] = {1,2,3,4,5,6,7};
    int size_n = sizeof(A)/sizeof(int);

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
    myList2.insertLastSLL(1);
    myList2.insertLastSLL(3);
    myList2.insertLastSLL(5);
    myList2.printSLL();
    
    // std::cout << std::boolalpha << myList2.ifSortedSLL() << std::endl;

    SLL myList3;
    myList3.insertLastSLL(2);
    myList3.insertLastSLL(4);
    myList3.insertLastSLL(6);
    myList3.printSLL();

    // myList2.concatSLL(myList3);
    // myList2.printSLL();

    
//     myList3.printSLL();
//     myList3.deleteDuplinSortedSLL();
//     myList3.printSLL();
   
//     myList2.reverseEleSLL();
//     myList2.printSLL();
    
//     myList2.reverseEleSLL();
//     myList2.printSLL();
    
//     Node *p = nullptr;

//     myList2.reverseLinkSLLrec(p, myList2.getFirst());
//     myList2.printSLL();

    // std::cout << std::endl;
    // myList2.printSLL();
    // myList3.printSLL();

    // myList2.mergeSLL(myList3);
    // myList2.printSLL();
/** error because two linked lists are combined then try to delete two at once
 * 
**/
    // std::cout << myList2.countSLL() << std::endl;
    // std::cout << myList2.isLoop() << std::endl;

    // SLL myList4 = myList3;
    // myList4.printSLL();
    SLL myList5 = myFunc1(A,size_n);
    myList5.printSLL();
    
    std::cout << "Address of list 5: " << myList5.getFirst() << std::endl;
    
    myList5 = myList2;

    std::cout << "Address of list 2: " << myList2.getFirst() << std::endl;
    std::cout << "Address of list 5: " << myList5.getFirst() << std::endl;
    
    myList5.printSLL();
    myList2.printSLL();

    std::vector<SLL> myVec;
    myVec.reserve(10);
    myVec.push_back(SLL(A, size_n));
    myVec.at(0).printSLL();
    myVec.push_back(SLL(myList2));
    myVec.at(1).printSLL();
    
    return 0;
}