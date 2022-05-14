#include <iostream>
#include <memory>
#include <vector>

int main(){

    std::unique_ptr<int> p1 = std::make_unique<int>(100);

    std::cout << *p1 << std::endl;
    std::cout << p1.get() << std::endl;

    std::vector<std::unique_ptr<int>> myvec1;

    myvec1.push_back(std::move(p1)); //move the owndership

    if (p1)
        std::cout << *p1 << std::endl;
    std::cout << p1.get() << std::endl;
    std::cout << *myvec1.at(0) << std::endl;



    return 0;
}