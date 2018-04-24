#include "a.h"
#include "b.h"

int main() {
    A a;
    B b;
    b.f(&a);
    return 0;
}
