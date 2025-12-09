#include <iostream>

template<typename... Ts>
auto mean(Ts... xs) {
    return (xs + ...) / sizeof...(xs);
}

int main() {
    std::cout << "Mean of 1, 2, 3: " << mean(1, 2, 3) << std::endl;
    std::cout << "Mean of 10, 20, 30, 40: " << mean(10, 20, 30, 40) << std::endl;
    std::cout << "Mean of 5.5, 6.5, 7.5: " << mean(5.5, 6.5, 7.5) << std::endl;

    return 0;
}

