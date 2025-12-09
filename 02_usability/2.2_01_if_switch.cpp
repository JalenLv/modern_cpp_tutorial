#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4 };

    // Since C++17, can be simplified with `auto`
    const std::vector<int>::iterator itr =
        std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    if (const auto &itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) {
        *itr = 4;
    }

    for (auto element = vec.begin(); element != vec.end(); element++) {
        std::cout << *element << '\n';
    }

    return 0;
}
