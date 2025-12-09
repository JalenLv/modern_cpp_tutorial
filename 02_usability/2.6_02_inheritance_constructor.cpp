#include <iostream>

class Base {
public:
    int value1;
    int value2;

    Base() : value1(1) {}

    // Since C++11
    // You can call a constructor in a constructor
    Base(int value) : Base() { this->value2 = value; }
};

class SubClass : public Base {
public:
    using Base::Base;   // Inheritance constructor
};

int main() {
    Base b(2);
    std::cout << b.value1 << '\n';
    std::cout << b.value2 << '\n';

    SubClass s(2);
    std::cout << s.value1 << '\n';
    std::cout << s.value2 << '\n';

    return 0;
}

