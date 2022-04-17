#include <iostream>
#include <map>
#include <string>
#include <algorithm> // double linked list

template <typename T>
void print_b(const T &vec){
    std::cout << "[";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}
// associative contaiter - map/set
// sequence container - array/vector/list(forward list)/deque

// void print_c(const std::map<std::string, int> &m)

int main(){
    std::map<std::string, int> m1 {
        {"Minsung", 34},
        {"Pee", 29}
    };

    m1["Haha"] = 11;
    m1["Pee"] = 30;
    m1.at("Minsung") = 35;
    m1.insert(std::pair<std::string, int>("ss", 10));
    m1.insert(std::make_pair("Joe", 5));
    m1.erase("Haha");
    std::cout << m1.max_size() << std::endl;
    
    m1.count("Minsung");
    m1.clear();
    m1.empty();

    return 0;
}