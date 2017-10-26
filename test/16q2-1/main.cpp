#include <iostream>

class Pokemon {
public:
    Pokemon() { std::cout << "default" << std::endl; }
    Pokemon(const char*) { std::cout << "convert" << std::endl; }
    Pokemon(const Pokemon&) { std::cout << "copy" << std::endl; }
    ~Pokemon() { std::cout << "destructor" << std::endl; }

    Pokemon& operator=(const Pokemon&)
    {
        std::cout << "assign" << std::endl;
        return *this;
    }
};


int main()
{
    Pokemon x("Dragonite"), y=x;
    Pokemon* z= new Pokemon(x);
    //*z=x;
    delete z;
    return 0;
}
