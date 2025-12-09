#include <iostream>

template<auto value>
void foo() {
    std::cout << value << '\n';
    return;
}

int main() {
    foo<10>();  // value as int
    return 0;
}

