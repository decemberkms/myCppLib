#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

void test2(){
    cout << "\n -----------Test2-------------" << endl;

    int x {100};
    
    auto l = [x] () mutable { // constructor is called
        x += 100;
        cout << x << endl;
    };

    l();
    cout << x << endl; // 200  / operator () called

    l(); 
    cout << x << endl; // 300 / operator () called
}

void test4(){
    cout << "\n -----------Test4-------------" << endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [=] () mutable { //captuer by value
        x += 100;
        y += 100;
        cout << x << endl;
        cout << y << endl;
    };

    l();
    
    cout << "\n";
    cout << x << endl;
    cout << y << endl;
}

void test5(){
    cout << "\n -----------Test5-------------" << endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [&] () mutable { //captuer by value
        x += 100;
        y += 100;
        cout << x << endl;
        cout << y << endl;
    };

    l();
    
    cout << "\n";
    cout << x << endl;
    cout << y << endl;
}



int main() {

    int y {10};

    auto l = [y] (int x) {cout << x + y << endl;};

    l(1);

    test2();
    test4();
    test5();

    return 0;
}