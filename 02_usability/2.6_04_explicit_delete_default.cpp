class Magic {
public:
    Magic() = default;                          // Explicitly require default constructor
    Magic(int magic_number);
    Magic & operator=(const Magic &) = delete;  // Explicitly refuse default copy constructor
};

int main() { return 0; }

