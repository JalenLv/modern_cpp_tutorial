#include <iostream>
#include <type_traits>

void foo(char *) {
    std::cout << "foo(char *) is called\n";
}
void foo(int) {
    std::cout << "foo(int) is called\n";
}

int main() {
    if (std::is_same<decltype(NULL), decltype(0)>::value) {
        std::cout << "NULL == 0\n";
    }
    if (std::is_same<decltype(NULL), decltype((void *)0)>::value) {
        std::cout << "NULL == (void *)0\n";
    }
    if (std::is_same<decltype(NULL), decltype(nullptr)>::value) {
        std::cout << "NULL == nullptr\n";
    }

    foo(0);         // will call foo(int)
    // foo(NULL);   // doesn't compile
    foo(nullptr);   // will call foo(char *)

    return 0;
}