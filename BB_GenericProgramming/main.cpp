#include <iostream>
#include <utility>
#include "Item.hpp"



int main(){

    Item<double> myItem1("Computer", 10.0);
    std::cout << myItem1 << std::endl;

    std::pair<std::string, int> p1 {"Minsung", 10};
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;

    return 0;
}