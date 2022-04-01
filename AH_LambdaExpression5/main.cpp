#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    string name;
    int age;
public:
    Person() = default;
    Person(string name, int age): name{name}, age{age} {}
    Person(const Person &obj) = default;
    ~Person() = default;
    string get_name() const {return name;}
    void set_name(string name) {this->name = name;}
    int get_age() const {return age;}
    void set_age(int age) {this->age = age;}

    // all the same 
    auto change_person1() {return [this] (string new_name, int new_age) {name = new_name; age= new_age;};} 
    auto change_person2() {return [=] (string new_name, int new_age) {name = new_name; age= new_age;};} // depricated in c++20
    auto change_person3() {return [&] (string new_name, int new_age) {name = new_name; age= new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &rhs){
    os << "[Person: " << rhs.name << ":" << rhs.age << "]";
    return os;
}


void test8(){
    cout << "\n------Test8---------" << endl;
    Person person("Min", 10);
    cout << person << endl;

    auto change_person1 = person.change_person1();
    change_person1("Pee", 7);
    cout << person << endl;

    auto change_person2 = person.change_person2();
    change_person2("Cha", 5);
    cout << person << endl;

}


class Lambda{
private:
    int y;
public:
    Lambda(int y): y{y}{};
    
    void operator() (int x) const {
        cout << x + y << endl;
    };
};

class People {
private:
    std::vector<Person> people;
    int max_people;
public:
    People(int max = 10): max_people{max}{};
    People(const People &p) =default;
    void add(string name, int age){
        people.emplace_back(name, age);
    }
    void set_max_people(int max){
        max_people = max;
    }
    int get_max_people() const{
        return max_people;
    }

    std::vector<Person> get_people(int max_age){
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(), people.end(), std::back_inserter(result), 
        [this, &count, max_age] (const Person &p){return p.get_age() > max_age && ++count <= max_people;});
        return result;
    }

};

int main(){
    test8();

    int y {100};
    Lambda lambda1(y);
    auto lambda2 = [y] (int x) {cout << x + y << endl;};

    lambda1(200); 
    lambda2(200);

    return 0;
}