#include <iostream>
extern void pointer();
extern int* p;
extern int i;
int main() {
    std::cout << "main here" << std::endl;
    pointer();
    if (p) {
        std::cout << "point to " << *p << std::endl;
    }
    else {
        std::cout << "pointer is NULL" << std::endl;
    }
    std::cout << "extern int " << i << std::endl;
    return 0;
}
