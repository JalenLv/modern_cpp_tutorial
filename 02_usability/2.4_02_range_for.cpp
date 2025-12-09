#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec { 1, 2, 3, 4 };

    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) {
        *itr = 4;
    }
    
    for (auto element : vec) {  // read only
        std::cout << element << '\n';
    }
    for (auto &element : vec) { // writable
        element += 1;
    }
    for (auto element : vec) {  // read only
        std::cout << element << '\n';
    }

    return 0;
}
