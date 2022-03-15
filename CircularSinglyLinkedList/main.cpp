#include "CSLL.hpp"

int main(){
    int A[] = {1,2,3,4};
    int size_z = sizeof(A) / sizeof(int);

    CSLL myCList1(A,size_z);

    myCList1.printCSLL();
    std::cout << myCList1.countCSLL() << std::endl;
    std::cout << myCList1.sumCSLL() << std::endl;
    std::cout << myCList1.MaxCSLL(myCList1.getHead()) << std::endl;
    std::cout << myCList1.MinCSLL(myCList1.getHead()) << std::endl;

    myCList1.insertCSLL(4, 10);
    myCList1.insertCSLL(0, 11);
    myCList1.insertCSLL(6, 12);
    myCList1.printCSLL();

    return 0;
}