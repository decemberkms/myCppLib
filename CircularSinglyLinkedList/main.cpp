#include "CSLL.hpp"

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    int size_z = sizeof(A) / sizeof(int);

    CSLL myCList1(A,size_z);

    myCList1.printCSLL();

    return 0;
}