#include <iostream>
#include <set>
#include <algorithm> // double linked list
#include <unordered_set>

// set like Python - ordered, no duplicates


// operator < -> must be in a class

template <typename T>
void print_b(const T &vec){
    std::cout << "[";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}


int main(){
    std::set<int> s1 {1,2,3,4,5};
    std::set<int> s2 {1,4,4,3,2,2,1,1,2,3,4,5};

    print_b(s1);
    print_b(s2);
    
    auto result = s1.insert(10); // std::pair<iterator, bool> = first- the element, second - done or not
    print_b(s1);

    std::cout << *result.first << std::endl;
    std::cout << result.second << std::endl;


    s1.erase(3);
    print_b(s1);

    auto it = s1.find(10); // different from algorithm's find - faster
    s1.erase(it);
    print_b(s1);

    int num = s1.count(1);
    s1.clear();
    s1.empty();
    std::cout << num << std::endl;
    return 0;
}