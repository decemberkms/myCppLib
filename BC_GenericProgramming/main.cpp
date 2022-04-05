#include "Array.hpp"
#include <string>

int main(){
    // Array<int, 5> nums;
    // std::cout << nums << std::endl;
    
    // nums.fill(0);
    // std::cout << nums << std::endl;

    // nums[0] = 1000;
    // std::cout << nums << std::endl;

    // Array<int, 100> num2(1);
    // std::cout << num2 << std::endl;

    Array<std::string, 10> strings(std::string("Min"));
    std::cout << strings << std::endl;
    strings[0] = std::string{"Pee"};
    std::cout << strings << std::endl;

    strings.fill(std::string("Haha"));
    std::cout << strings << std::endl;

    return 0;
}