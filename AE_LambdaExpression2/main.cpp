#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

// lambda as function parameter
using namespace std;

void print_if (std::vector<int> nums, bool (*predicate) (int)){
    for (int i: nums)
        if (predicate(i))
            std::cout << i << std::endl;
}

void foo(std::function<void(int)> l){
    l(10);
}

void foo( void (*l)(int)){
    l(10);
}

void foo(auto l){
    l(10);
}

std::function<void (int)> foo(){
    return [] (int x) { std::cout << x;};
}

void (*foo(auto l))(int){
    return [] (int x) { std::cout << x;};
}

auto foo(auto l){
    return [] (int x) { std::cout << x;};
}

int main(){

    std::vector<int> nums {1,2,3,4,5,6};

    print_if(nums, [] (auto x) {return x % 2 == 0;});
    print_if(nums, [] (auto x) {return x % 2 != 0;});
    

    return 0;
}