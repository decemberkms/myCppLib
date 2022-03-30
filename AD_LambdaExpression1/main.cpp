#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

//stateless lambda expressions
using namespace std;

int main(){
    [] () {cout << "Hi" << endl;}();
    [] (int x) { std::cout << x;};
    [] (int x, int y) { cout << x + y << endl;};

    auto l = [] () {cout << "Hi Min" <<endl;};
    l();

    auto l2 = [] (int x) { cout << x << endl;};
    l2(10);

    auto l3 = [] (int x, int y) -> int {return x + y;};
    //  auto l3 = [] (int x, int y) {return x + y;}; // more common
    cout << l3(1,2) << endl;


    int x { 10 };

    [] (int x) { std::cout << x;}(100);


    const int n {3};
    int nums[n] {10,20,30};

    auto sum = [] (int nums[], int n) { 
        int sum{0};
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        return sum;
    };
    cout << endl;
    cout << sum(nums, n);
    cout << endl;
    ///////////////////
    int test_score1 {75};

    auto bonus = [] (int &score, int bonus){ // even reference can be used
        score += bonus;
    };
    cout << test_score1 << endl;
    bonus(test_score1, 10);
    cout << test_score1 << endl;
    ///////////////////

    int x1 = 10000;
    auto l4 = [] (int *x) { cout << *x;};
    l4(&x1);
    cout << endl;



    /////////////////////
    int num1{10};
    float num2{20.5};
    auto l5 = [] (auto x) {cout << x*x << endl;}; // even auto for parameter
    l5(num1);
    l5(num2);



    

    return 0;
}