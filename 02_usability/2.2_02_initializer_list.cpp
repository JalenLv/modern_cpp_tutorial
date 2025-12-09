#include <iostream>
#include <vector>

class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo {
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list) {
        for (
            std::initializer_list<int>::iterator it = list.begin();
            it != list.end(); it++
        ) {
            vec.push_back(*it);
        }
    }

    void foo(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); it++) {
            vec.push_back(*it);
        }
    }
};

int main() {
    // Before C++11
    int arr[3] = { 1, 2, 3 };
    Foo foo(1, 2);
    // Foo foo2();  // doesn't compile, is ambiguous and parsed as function declaration
    int tmp[] = { 1, 2, 3, 4, 5 };
    std::vector<int> vec(tmp, tmp + 5);

    std::cout << "arr[0]: " << arr[0] << '\n';
    std::cout << "foo: " << foo.value_a << ", " << foo.value_b << '\n';
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << "\n";
    }


    // After C++11
    MagicFoo magicFoo = { 1, 2, 3, 4, 5 };
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); it++) {
        std::cout << *it << '\n';
    }
    
    magicFoo.foo({ 6, 7, 8, 9 });
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); it++) {
        std::cout << *it << '\n';
    }

    Foo foo3 { 3, 4 };
    std::cout << "foo3: " << foo3.value_a << ", " << foo3.value_b << '\n';

    std::vector<int>vec2 = { 1, 2, 3, 4, 5 };
    for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++) {
        std::cout << *it << "\n";
    }

    return 0;
}
