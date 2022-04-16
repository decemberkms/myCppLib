#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_a(vector<int> vec){
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec.at(i) << std::endl; // bounce checking
}


void print_b(const std::vector<int> &vec){
    std::cout << "[";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

int main() {

    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 (10, 9);

    // print_a(vec2);

    // cout << vec2.capacity() << endl;
    // cout << vec2.max_size() << endl;
    // vec2.push_back(1100);
    // cout << vec2.capacity() << endl;
    // vec2.pop_back();
    // print_a(vec2);
    // cout << vec2.capacity() << endl;

    // std::vector<int>::iterator it = std::find(vec1.begin(), vec1.end(), 4);
    // // vec1.insert(it, 10); // once used, invalidated
    // print_a(vec1);
    // // cout << vec2.capacity() << endl;
    // vec1.insert(it, vec2.begin(), vec2.end());
    // print_a(vec1);
    // print_b(vec2);
    // cout << vec1.capacity() << endl;
    // vec1.shrink_to_fit();
    // cout << vec1.capacity() << endl;
    // vec1.reserve(100);
    // cout << vec1.capacity() << endl;
    
    
    // print_b(vec1);
    // vec1.erase(vec1.begin(), vec1.end());
    print_b(vec1);
    print_b(vec2);

    // std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    // std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
        // [] (int x) {return x % 2 == 0;});
    
    // print_b(vec2);

    std::vector<int> vec3;

    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
        std::back_inserter(vec3),
            [] (int x, int y) {return x * y;});
    print_b(vec3);    

    return 0;
}
