#include <iostream>

class Holder
{
private:
    int *m_data;
    size_t m_size;

public:
    Holder(int size) // Constructor
    {
        std::cout << "No args constructor " << std::endl;
        m_data = new int[size];
        m_size = size;
    }

    Holder(const Holder &other)
    {
        std::cout << "Copy Constructor" << std::endl;
        m_data = new int[other.m_size];                               // (1)
        std::copy(other.m_data, other.m_data + other.m_size, m_data); // (2)
        m_size = other.m_size;
    }

    Holder(Holder &&other) noexcept // <-- rvalue reference in input
        : m_data{other.m_data}, m_size{other.m_size}{
        std::cout << "Move Constructor" << std::endl;
        // m_data = other.m_data; // (1)
        // m_size = other.m_size;
        other.m_data = nullptr; // (2)
        other.m_size = 0;
    }

    Holder &operator=(const Holder &other)
    {
        std::cout << "Copy Assignment" << std::endl;
        if (this == &other)
            return *this; // (1)
        delete[] m_data;  // (2)
        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
        return *this; // (3)
    }

    Holder &operator=(Holder &&other) // <-- rvalue reference in input
    {
        std::cout << "Move Assignment" << std::endl;
        if (this == &other) return *this;

        delete[] m_data; // (1)

        m_data = other.m_data; // (2)
        m_size = other.m_size;

        other.m_data = nullptr; // (3)
        other.m_size = 0;

        return *this;
    }

    ~Holder() // Destructor
    {   
        std::cout << "Destructor is is calledother.m_size" << std::endl;
        delete[] m_data;
    }
};

Holder createHolder(int size)
{
    return Holder(size);
}

int main()
{
    Holder h1(1000);                // regular constructor
    Holder h2(h1);                  // copy constructor (lvalue in input)
    Holder h3 = createHolder(2000); // move constructor (rvalue in input) (1)

    std::cout << std::endl;

    h2 = h3;                // assignment operator (lvalue in input)
    h2 = Holder(10); // move assignment operator (rvalue in input)

    return 0;
}