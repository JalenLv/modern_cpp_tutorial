struct Base {
    virtual void foo(int);
};

struct SubClass : public Base {
    void foo();
    virtual void foo(int) override;         // Legal
    // virtual void foo(double) override;   // Illegal, no such virtual function in super class
};

struct Base_ {
    virtual void foo() final;
};

struct SubClass1 final : public Base {};    // Legal
// struct SubClass2 : public SubClass1 {};  // Illegal, SubClass1 has final
struct SubClass3 : public Base {
    // void foo();                          // Illegal, foo has final
};

int main() { return 0; }

