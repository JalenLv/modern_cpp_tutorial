#include <iostream>

template<typename... Ts> class Magic {};
template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << '\n';
}

// Ways to unpack variadics 

// 1. Recursive template function
template<typename T0>
void printf1(T0 value) {
    std::cout << value << '\n';
}
template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << '\n';
    printf1(args...);
}

// 2. Variadic template expansion
// Since C++17
template<typename T0, typename... Ts>
void printf2(T0 t0, Ts... ts) {
    std::cout << t0 << '\n';
    if constexpr (sizeof...(ts) > 0) printf2(ts...);
}

// 3. Initializer list expansion
// C++11 hack, pre-C++17 style
// template<typename T, typename... Ts>
// auto printf3(T value, Ts... args) {
//     std::cout << value << '\n';
//     (void) std::initializer_list<T>{
//         ([&args] { std::cout << args << '\n'; }(), value)...
//     };
// }
template<typename... Ts>
auto printf3(Ts... args) {
    (void) std::initializer_list<int>{
        ((std::cout << args << '\n'), 0)...
    };
}

// 4. Fold expressions
// Since C++17
template<typename... Ts>
void printf4(Ts... xs) {
    ((std::cout << xs << '\n'), ...);
}

int main() {
    magic();        // 0
    magic(1);       // 1
    magic(1, "");   // 2

    printf1(1, 2, "123", 1.1);
    printf2(1, 2, "123", 1.1);
    printf3(1, 2, "123", 1.1);
    printf4(1, 2, "123", 1.1);

    return 0;
}
