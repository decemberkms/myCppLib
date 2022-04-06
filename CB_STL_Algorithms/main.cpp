#include <iostream>
#include <algorithm>
#include <vector>

struct Square_Functor {
    void operator()(int x){
        std::cout << x * x << " ";
    }
};


void square2(int x){
    std::cout << x * x * x << " ";
}

int main(){
    std::vector<int> vec{1,2,4,5,6,3};
    
    std::vector<int>::iterator find_it = std::find(vec.begin(), vec.end(),5);
    find_it--;
    if (find_it != vec.end())
        std::cout << *find_it << std::endl;

    Square_Functor square;
    
    std::cout << std::endl;
    std::vector<int> vec1 {1,2,3,4};
    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;
    std::for_each(vec1.begin(), vec1.end(), square2);

    
    std::cout << std::endl;
    std::for_each(vec1.begin(), vec1.end(), 
        [](int x) { std::cout << x* x * x * x << " ";});
    
    return 0;
}