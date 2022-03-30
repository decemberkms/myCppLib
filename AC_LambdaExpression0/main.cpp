#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;


struct Square_Functor {
    void operator() (int x){
        std::cout << x * x << " ";
    }   
};

template <typename T>
struct Displayer {
    void operator() (const T& data){
        std::cout << data <<" " ;
    }
};

class Multiplier {
private:
    int num{};
public:
    Multiplier(int n): num{n}{}
    int operator()(int n) const{
        return n * num;
    }
};



int main(){

    // std::for_each(vec1.begin(), vec1.end(), [] (int x) {cout << x << " ";});

    Square_Functor square;
    square(4); // it's not a function. it's an object
        // square.operator()(4) -> display 16

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100); // function object
    d2("Frank"); // function object

    vector<int> vec1 {1,2,3,4,5};

    std::for_each(vec1.begin(), vec1.end(), square);
    // std::for_each(vec1.begin(), vec1.end(), [] (int x) {cout << x << " ";});
    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());


    cout<< "\n";
    Multiplier mult(100);
    vec1 = {1,2,3,4,5,6,7};
    int a1 = mult(10);
    cout << a1 << endl;

    //transform changes the vector!
    // std::transform(vec1.begin(), vec1.end(), vec1.begin() + 3, mult); // need return
    // std::for_each(vec1.begin(), vec1.end(), d1); // ignore return
    // std::transform(vec1.begin(), vec1.end(), vec1.begin(),  [] (int x) {return x*x;});
    // std::for_each(vec1.begin(), vec1.end(), [] (int x) { return x*x;});
    // std::for_each(vec1.begin(), vec1.end(), [] (int x) { cout << x << endl;});
    std::transform(vec1.begin(), vec1.end(), vec1.begin(),  [] (int x) {cout << x << endl;});
    return 0;
}