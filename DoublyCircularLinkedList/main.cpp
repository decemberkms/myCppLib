#include "List.hpp"
#include <vector>

int main(){
    int A[] = {0,11,22,33};
    int sizeA = sizeof(A) / sizeof(int);

    List myList1(A, sizeA);
    
    // myList1.printList();

    // List myList2(myList1);

    // myList2.printList();

    // int B[] = {1,2,3};
    // int sizeB = sizeof(B) / sizeof(int);
    // List myList3(B, sizeB);

    // myList1 = myList3;

    // myList1.printList();
    // myList3.printList();
    List myList2;
    // myList1.insertList(0, 10);
    // myList1.insertList(1, 100);
    // myList1.insertList(0, 2000);
    // myList1.insertList(0, 3000);
    // myList1.insertList(0, 4000);
    // std::cout << myList1.getHead()->data << std::endl;
    // std::cout << myList1.getTail()->data << std::endl;
    myList2.insertListLast(1);
    myList2.insertListLast(2);
    myList2.insertListLast(3);
    // myList2.printList();

    // myList2.insertList(1,2);

    

    // myList1.printList();
    // myList1.deleteList(8);
    // myList1.printList();
    // std::cout << myList1.getHead()->data << std::endl;
    // std::cout << myList1.getTail()->data << std::endl;
    // myList2.searchList(12213);
    
    // concatList(myList1, myList2);


    // myList1.printList();
    // myList1.printList();
    // myList2.printList();
    // List myList3 = concatList(myList1, myList2);

    // myList3.printList();
    
    
    myList1.printList();
    myList2.printList();

    List myList4 = mergeList(myList1, myList2);
    myList4.printList();
    List myList5 = mergeList(myList2, myList1);
    myList5.printList();

    // myList4.printReList();
    myList5.reverseEleList();
    myList5.printList();
}