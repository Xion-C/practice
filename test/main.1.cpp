#include <iostream>
#include <string>

class Test
{
public:
    Test(int mem) : mem(mem)
    {}
    void print() const
    {
        std::cout << "mem: " << mem << std::endl;
    }
private:
    int mem;
};

int main () {
    Test t(10);
    std::cout << __LINE__ << std::endl;
    t.print();
    std::cout << __LINE__ << std::endl;

}
