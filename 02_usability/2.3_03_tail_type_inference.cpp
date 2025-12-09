#include <iostream>
#include <type_traits>

template<typename R, typename T, typename U>
R add(T x, U y) {
    return x + y;
}

// Since C++11
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x + y) {
    return x + y;
}

// Since C++14
template<typename T, typename U>
auto add3(T x, U y) {
    return x + y;
}

int main() {
    auto v = add<double, int, double>(1, 2.0);
    if (std::is_same<decltype(v), double>::value) {
        std::cout << "v is double: ";
    }
    std::cout << v << '\n';

    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << '\n';

    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << '\n';

    return 0;
}
