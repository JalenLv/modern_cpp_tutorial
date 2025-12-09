#include <vector>
#include <initializer_list>
#include <iostream>

class MagicFoo {
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); it++) {
            vec.push_back(*it);
        }
    }
};

auto add14 = [] (auto x, auto y) -> int {
    return x + y;
};

int add20 (auto x, auto y) {
    return x + y;
}

int main() {
    MagicFoo magicFoo = { 1, 2, 3, 4, 5 };
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << '\n';

    auto i = 5;                 // i as int
    auto p = new auto(10);      // p as int *
    std::cout << "i: " << i << '\n';
    std::cout << "*p: " << *p << '\n';

    auto j = 6; // j as int
    std::cout << add14(i, j) << '\n';
    std::cout << add20(i, j) << '\n';

    // auto auto_arr[20] = arr;    // illegal, can't infer array type

    return 0;
}
