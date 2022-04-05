#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

template <typename T, int N>
class Array{
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr){
        os << "[";
        for (const auto &val: arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
private:
    int size {N};
    T values[N];

public:
    Array() = default;
    Array(T init_val){
        for (auto &ele:values)
            ele = init_val;
    }

    void fill(T val){
        for (auto &ele:values)
            ele = val;
    }

    int get_size() const {
        return size;
    }

    T &operator[](int index){
        return values[index];
    }
};

#endif
