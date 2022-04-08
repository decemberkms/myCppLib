#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person{
    friend std::ostream &operator<<(std::ostream& os, const Person &obj);
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        :name{name}, age{age} {
            std::cout << "args constructor" << std::endl;
        }

    //copy constructor
    Person(const Person& obj){
        std::cout << "Copy constructor" << std::endl;
        this->name = obj.name; 
        this->age = obj.age;
    }
    
    //move constructor
    Person(Person&& obj) noexcept {
        std::cout << "Move constructor" << std::endl;
        this->name = obj.name; 
        this->age = obj.age;
    }

    ~Person(){
        std::cout << "Destructor " << std::endl;
    }

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }

   
};

std::ostream &operator<<(std::ostream& os, const Person &obj) {
    os << "[Person: " << obj.name << ", "<< obj.age << "]";
    return os;
}

void test_function(){
    std::cout << "\n =================" << std::endl;
    
    std::vector<int> vec {1, 2, 3, 4, 5,1,2,3,4,5,6};
    
    auto loc = std::find(std::begin(vec), std::end(vec), 1);

    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number: " << std::endl; 

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    std::list<Person>::iterator loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});

    if (loc1 != players.end())
        std::cout << "Found the number: " << *loc1 << std::endl;
    else
        std::cout << "Couldn't find the number: " << std::endl; 


    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << "Number accurence: " << num << std::endl;


    int evenN = std::count_if(vec.begin(), vec.end(), [] (int x) {return x % 2 == 0;});
    std::cout << "Number accurence: " << evenN << std::endl;

    int N5 = std::count_if(vec.begin(), vec.end(), [] (int x) {return x > 5;});
    std::cout << "Greater than 5: " << N5 << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 300);

    for (int i = 0; i < vec.size(); ++i){
        std::cout << vec.at(i) << std::endl;
    }


    if (std::all_of(vec.begin(), vec.end(), [] (int x) {return x < 10;}))
        std::cout << "True!" << std::endl;
    else
        std::cout << "False!" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // ::toupper << global scope
    std::cout << "Before transform: " << str1 << std::endl;
}


int main(){

    test_function();

    return 0;
}