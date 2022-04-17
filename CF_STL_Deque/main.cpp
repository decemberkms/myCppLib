#include <iostream>
#include <deque>
#include <algorithm>

void print_b(const std::deque<int> &vec){
    std::cout << "[";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

int main(){

    std::deque<int> d {1,2,3,4,5};
    std::deque<int> d1 (10, 100);

    d.push_front(100);
    print_b(d);
    std::cout <<     d.max_size() << std::endl;

    d.pop_back();
    d.pop_front();

    d.emplace_back(0);
    d.emplace_front(99);
    print_b(d);
    return 0;
}