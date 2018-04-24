#include <iostream>
#include "a.h"
#include "b.h"

A::A() : b(new B) {
    std::cout << "aaaaa" << '\n';
}
