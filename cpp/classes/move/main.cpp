#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>


class string {
public:
    string() : buf(new char[1]) {
        buf[0] = '\0';
        std::cout << this << " - " << "default" << std::endl;
    }
    string(const char* s) : buf(new char[strlen(s) + 1]) {
        std::cout << this << " - " << "convert" << std::endl;
        strcpy(buf, s);
    }
    string(const string & s) : buf(new char[strlen(s.buf) + 1]) {
        std::cout << this << " - " << "copy" << std::endl;
        strcpy(buf, s.buf);
    }

    ~string() {
        std::cout << this << " - " << "destruct : " << buf << std::endl;
        delete[] buf;
    }

    string& operator=(const string& s) {
        if (this == &s) return *this;
        delete[] buf;
        buf = new char[strlen(s.buf) + 1];
        strcpy(buf, s.buf);
        std::cout << this << " - " << "assign" << std::endl;
        return *this;
    }

private:
    char *buf;
};

class Pokemon {
public:
    Pokemon(string n) : name(n) {}
private:
    string name;
};

int main() {

    Pokemon a("aa");
    Pokemon b("bb");
    Pokemon c("cc");
    std::cout << "end" << '\n';

    //string b("vb");

    //ctrl + F5
    return 0;
}
