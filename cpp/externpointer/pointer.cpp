#include <iostream>

// static int* p=NULL; // if static, other file could not use this p even using extern
int* p=NULL;
int i=0;
void pointer() {
    std::cout << "pointer func" << std::endl;
    p = (int*)calloc(1, sizeof(int));
    *p = 10;
    i=99;
    std::cout << "pointer func end" << std::endl;
}
