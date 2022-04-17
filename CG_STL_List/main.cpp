#include <iostream>
#include <list>
#include <algorithm> // double linked list
#include <forward_list> // singly linked list // only front


template <typename T>
void print_b(const T &vec){
    std::cout << "[";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

int main() {

    std::list<int> li {1,2,3};

    std::list<int> li2 (10, 100);

    print_b(li2);

    std::cout << li2.size() << std::endl;
    std::cout << li2.max_size() << std::endl;

    li2.push_back(20);
    li2.push_front(30);
    li2.emplace_back(99);
    li2.emplace_front(999);

    auto it = std::find(li2.begin(), li2.end(), 99);
    li2.insert(it, 3023);
    

    print_b(li2);
    li2.resize(3);
    print_b(li2);
    
    return 0;
}