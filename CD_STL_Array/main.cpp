#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

// doens't decay to a pointer
int main(){

    std::array<int, 10> myArr1 {1,2,3,4,5,6,7};
    // std::array<int, 10> myArr1 {{1,2,3,4,5,6,7}} ; // C++ 11
    
    for (int i = 0; i < myArr1.size(); ++i)
        std::cout << myArr1.at(i) << std::endl; // bounce checking

    std::cout << myArr1.front() << std::endl;
    std::cout << myArr1.back() << std::endl;
    std::cout << myArr1.empty() << std::endl;
    std::cout << myArr1.max_size() << std::endl;
    // std::cout << myArr1.back() << std::endl;
    // std::cout << myArr1.back() << std::endl;
    
    int *data = myArr1.data();

    std::cout << data << std::endl;
    std::cout << *(data + 1) << std::endl;
    
    std::array<int, 10> myArr2 {0};
    myArr1.fill(10);

    myArr1.swap(myArr2);

    for (int i = 0; i < myArr1.size(); ++i)
        std::cout << myArr1.at(i) << std::endl; // bounce checking

    std::sort(myArr2.begin(), myArr2.end());
    // std::accumulate(myArr2.begin(), myArr2.end(), 0);
    
    return 0;
}