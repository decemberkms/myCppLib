#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec {1,2,3};
    std::vector<int>::iterator it = vec.begin();

    while (it != vec.end()) {
        std::cout << *it << " ";
        ++it;
    }

    for (auto it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << " ";        
    }

    return 0;
}