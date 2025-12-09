#include <vector>

template<bool T>
class MagicType {
    bool magic = T;
};

int main() {
    std::vector<MagicType<(1>2)>> magics;   // Legal, but not recommended
    return 0;
}
