#include <iostream>
#include <type_traits>

enum Left {
    left_value1 = 1,
    left_value2
};

enum Right {
    right_value1 = 1,
    right_value2
};

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

template<typename T>
std::ostream &operator<<(
    typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream,
    const T &e
) {
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main() {
    // Compiler warns you about comparing enums
    // if (Left::left_value1 == Right::right_value1) {
    //     std::cout << "Left::value1 ?= Right::value1\n";
    // }

    // Compiler throws an error on comparing `new_enum` to `int`
    // if (new_enum::value1 == 0) {
    //     std::cout << "new_enum::value1 ?= 0\n";
    // }

    if (new_enum::value3 == new_enum::value4) {
        std::cout << "new_enum::value3 == new_enum::value4\n";
    }

    std::cout << new_enum::value1 << '\n';
    std::cout << new_enum::value2 << '\n';
    std::cout << new_enum::value3 << '\n';

    return 0;
}

