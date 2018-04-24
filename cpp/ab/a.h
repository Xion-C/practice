// #include "b.h"
#include <iostream>
class B;
class A {
public:
    A();
    void g() {std::cout << "afafafa" << '\n';}
private:
    B* b;
};
