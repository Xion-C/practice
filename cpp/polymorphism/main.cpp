#include <iostream>

void func() {
    std::cout << "func" << '\n';
}

class Test {
public:
    void Try() {
        std::cout << "Try: Test" << '\n';
    }
};

class Base {
public:
    Base() : test() {
        std::cout << "Default: Base" << '\n';
    }
    virtual ~Base() {
        std::cout << "Destruct: Base" << '\n';
    }
    virtual void TestVirtual() {
        std::cout << "TestVirtual: Base" << '\n';
    }
    void TestNotVirtual() {
        std::cout << "TestNotVirtual: Base" << '\n';
    }
    void Const() const {
        std::cout << "Const: Base" << '\n';
        func();
        test.Try();
    }
private:
    Test test;
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Default: Derived" << '\n';
    }
    virtual ~Derived() {
        std::cout << "Destruct: Derived" << '\n';
    }
    virtual void TestVirtual() {
        std::cout << "TestVirtual: Derived" << '\n';
    }
    void TestNotVirtual() {
        std::cout << "TestNotVirtual: Derived" << '\n';
    }
};

int main() {
    Base* ins = new Derived();
    ins->TestVirtual();
    ins->TestNotVirtual();
    ins->Const();
    delete ins;
    return 0;
}
