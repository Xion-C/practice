#include <iostream>

class Number
{
public:
    Number() { std::cout << "default" << std::endl; }
    Number(float) { std::cout << "convert" << std::endl; }
    Number(const Number&) { std::cout << "copy" << std::endl; }
    ~Number() { std::cout << "destructor" << std::endl; }

    Number& operator=(const Number&)
    {
        std::cout << "assign" << std::endl;
        return *this;
    }
};

class Pokemon
{
public:
    Pokemon(int cp, int hp)
    {
			  std::cout << "here" << std::endl;
        combatPower = cp;
				std::cout << "there" << std::endl;
        hitpoints = hp;
    }
private:
    Number combatPower;
    int hitpoints;
};

int main()
{
    Pokemon* chansey = new Pokemon(400, 376);
    int i = 100000;
    while(i)
    {
        int j = 1;
        j++;
        i--;
        std::cout << "j: " << j << '\n';
    }
    return 0;
}
