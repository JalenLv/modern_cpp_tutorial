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

int main() {
    Base b(2);
    std::cout << b.value1 << '\n';
    std::cout << b.value2 << '\n';
    return 0;
}

