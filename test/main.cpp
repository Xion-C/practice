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
    Test(int i) : num(i) {
        std::cout << "int cosntrunctor" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Test&) {
        return os << "| operator << |";
    }

    int num;
};

void TestDefault(int b, int a)
{
    std::cout << "first: " << b << std::endl;
    std::cout << "second: " << a << std::endl;
}


int main () {
    
    std::cout << __LINE__ << std::endl;

    //Logger& logger = Logger::GetInstance();

    LogList ls("hello");
    std::cout << "size: " << sizeof(ls) << std::endl;
    LogList *pls;
    std::cout << "psize: " << sizeof(*pls) << std::endl;

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
        ls << "testitem" << LEND();
    );
    std::cout << "debug end" << std::endl;
    //ls.end();
    TestDefault();


    Logger logger = Logger::GetInstance();
    logger.SetAllPrint(true);
    logger.SetPrint("test01", false);
    logger["test01"] << "try test" << LEND();
    logger["test02"] << "try test02" << std::endl << "another line" << LEND();

    for(int i=0;i<5;i++) {
        Test t(i);
        std::cout << "t: " << t.num << std::endl;
    }

    int tnum = 3;
    std::cout << (tnum << 2) << std::endl;

    typedef unsigned char uint8_t;
    uint8_t ttnum = 0b000000;
    std::cout << (int(ttnum) << 2) << std::endl;
    std::cout << (int(ttnum) >> 2) << std::endl;
}
