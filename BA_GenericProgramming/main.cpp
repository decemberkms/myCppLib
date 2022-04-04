#include <iostream>

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}

template <class T>
T min(T a, T b){
    return (a > b) ? b : a;
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    std::cout << a << " " << b << std::endl;
}


int main(){

    char a {'a'};
    char b {'b'};

    std::cout << max<char>(a, b) << std::endl;
    std::cout << min<char>(a, b) << std::endl;

    int c {10};
    func<char, int>(a,c);
    func(a,c);
    return 0;
}