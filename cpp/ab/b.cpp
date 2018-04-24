#include <iostream>
#include "b.h"
#include "a.h"

B::B() {
    std::cout << "bbbbb" << '\n';
}

int B::f(const A* a) const {
    a->g();
    std::cout << "f" << '\n';
    return 0;
}
