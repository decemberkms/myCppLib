#include "List.hpp"

int main(){
    int A[] = {1,2,3,4,5};
    int sizeL = sizeof(A) / sizeof(int);

    List myList1(A, sizeL);

    myList1.printList();

    std::cout << myList1.countList() << std::endl;
    std::cout << myList1.getHead()->next->data << std::endl;

    List myList2(myList2);
    



}