#include <vector>
#include <iostream>

template class std::vector<bool>;           // Force instantiation
extern template class std::vector<double>;  // Should not be instantiated in this compilation unit

int main() {
    // std::vector<double> vec { 1.0, 2.0, 3.0 };   // Won't compile
    return 0;
}