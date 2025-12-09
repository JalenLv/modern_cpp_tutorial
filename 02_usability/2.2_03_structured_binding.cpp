#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    // Before C++17
    auto t = f();
    int x1 = std::get<0>(t);
    double y1 = std::get<1>(t);
    std::string z1 = std::get<2>(t);
    std::cout << x1 << ", " << y1 << ", " << z1 << '\n';

    int x2; double y2; std::string z2;
    std::tie(x2, y2, z2) = f();
    std::cout << x2 << ", " << y2 << ", " << z2 << '\n';

    // Since C++17
    auto [x3, y3, z3] = f();
    std::cout << x3 << ", " << y3 << ", " << z3 << '\n';

    return 0;
}
