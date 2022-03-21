#include "List.hpp"

int main(){
    int A[] = {1,2,3,4,5};
    int sizeA = sizeof(A) / sizeof(int);

    List myList1(A, sizeA);
    
    myList1.printList();

    List myList2(myList1);

    myList2.printList();

    int B[] = {1,2,3};
    int sizeB = sizeof(B) / sizeof(int);
    List myList3(B, sizeB);

    myList1 = myList3;

    myList1.printList();
    myList3.printList();


}