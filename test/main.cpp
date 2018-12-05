#include <iostream>
#include <string>
#include "Logger.h"

#define DEBUG

#ifdef DEBUG
#   define IFDEBUG(...) __VA_ARGS__
#else 
#   define IFDEBUG(...)
#endif

void TestDefault(int a = 31, int b = 10);

class Test
{
public: 
    Test() {
        std::cout << "cosntrunctor" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Test&) {
        return os << "| operator << |";
    }
};

void TestDefault(int b, int a)
{
    std::cout << "first: " << b << std::endl;
    std::cout << "second: " << a << std::endl;
}


int main () {
    
    std::cout << __LINE__ << std::endl;

    //Logger& logger = Logger::GetInstance();

    LogList ls;

    int num = 3;

    //ls << "hello: " << num << std::endl;

    Test test;

    // std::ostringstream ss;
    // ss << "str--" << "int " << num;
    // ss << Test();
    // std::cout << ss.str() << std::endl;
    // std::cout << Test() << std::endl;

    // std::stringstream sss;
    // sss << "test sss" << num << 0.001;
    // sss << test;
    // std::cout << sss.str() << std::endl;

    // ls.SetPrint(true);
    // ls << "test log" << " " << num << test;
    // ls << "another" << std::endl;
    // ls << "testitem" << LogItemEnd();

    IFDEBUG(
        std::cout << "debug test" << std::endl;
        ls.SetPrint(true);
        ls << "test log" << " " << num << test;
        ls << "another" << std::endl;
        ls << "testitem" << LogItemEnd();
    );
    std::cout << "debug end" << std::endl;
    //ls.end();
    TestDefault();

}
