#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

// template classes are typically completely contained in header files

template <typename T1>
class Item {
    friend std::ostream &operator<<(std::ostream &os, const Item &rhs){
        os << rhs.name << ": " << rhs.value;
        return os;
    }
private:
    std::string name;
    T1 value;
public:
    Item(std::string name_val, T1 value_val)
        :name{name_val}, value{value_val}{}
    std::string get_name() const {return name;}
    T1 get_value() const {return value;}
};

#endif

