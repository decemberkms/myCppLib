#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person& rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) :name{name}, age{age}{}
    Person(const Person& rhs) :name{rhs.name}, age{rhs.age}{}
    ~Person() = default;

    std::string get_name() const {return name;}
    void set_name(std::string name) {this->name = name;}
    int get_age() const {return age;}
    void set_age(int age) {this->age = age;}
};

std::ostream &operator<<(std::ostream &os, const Person &rhs){
    os << "[Person: " << rhs.name << ", "<< rhs.age << "]";
    return os;
}

void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func){
// void filter_vector(const std::vector<int> &vec, auto func){ // c++ 20
    cout << "[";
    for (int i: vec){
        if (func(i))
            std::cout << i << " ";
    }
    cout << "]" << endl;
}


int main(){

    Person me{"Min", 10};
    cout << me << endl;

    auto l4 = [] (Person p){
        cout << p << endl;
    };

    l4(me);

    auto l5 = [] (const Person &p){
        cout << p << endl;
    };

    l5(me);

    auto l6 = [] (Person &p){
        p.set_age(6);
        p.set_name("Pee");
        cout << p << endl;
    };

    l6(me);
    cout << me << endl;


    cout << endl;

    vector<int> nums {10, 20, 30, 40, 50, 60 ,70};

    filter_vector(nums, [] (int x) {return x > 50;});

    filter_vector(nums, [] (int x) {return x < 30;});





    vector<Person> friend_list {
        {"Min", 10},
        {"Pee", 6},
        {"King", 4}
    };

    std::sort(friend_list.begin(), friend_list.end(), [] (const Person &p1, const Person &p2){
        return p1.get_name() < p2.get_name();
    });

    std::for_each(friend_list.begin(), friend_list.end(), [] (const Person& p) {
        cout << p << endl;
    });






    return 0;
}