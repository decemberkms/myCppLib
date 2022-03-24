#include "List.hpp"
#include <vector>

int main(){
    int A[] = {100,20,3,11,22,1,32,23};
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
    myList2.printList();
    myList2.insertListLast(2);
    myList2.printList();
    myList2.insertListLast(3);
    // myList2.printList();

    // myList2.insertList(1,2);

    myList1.printList();

    // myList1.printList();
    // myList1.deleteList(8);
    // myList1.printList();
    // std::cout << myList1.getHead()->data << std::endl;
    // std::cout << myList1.getTail()->data << std::endl;
    // myList2.searchList(12213);
    myList1.printList();
    myList1.printReList();
    myList1.printList();


}