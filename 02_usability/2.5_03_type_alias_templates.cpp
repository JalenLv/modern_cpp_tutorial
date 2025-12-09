#include <vector>
#include <string>

template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;
};

// Illegal
// template<typename T>
// typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

typedef int (*Process)(void *);
using NewProcess = int (*)(void *);

int main() {
    TrueDarkMagic<bool> you;
    return 0;
}
