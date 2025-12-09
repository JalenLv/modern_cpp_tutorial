#include <iostream>
#include <type_traits>

template<int i>
struct Int {};

template<int i>
constexpr auto iter(Int<i>) {
    return iter(Int<i-1> {});
}

constexpr auto iter(Int<0>) -> Int<0>;

int main() {
    decltype(iter(Int<10> {})) a;
    if (std::is_same<decltype(a), Int<0>>::value) {
        std::cout << "type a == Int<0>\n";
    }

    return 0;
}
