#include <iostream>
#include <string>
class Student {
public:
    //Student(const string * s) : name(new std::string(s)) {}
    Student(const char * s) : name(new std::string(s)) {
    }
    Student(const Student& s) : name(new std::string(*(s.name))) {
    }
    ~Student ( ) {
        delete name;
    }
    const std::string& getName ( ) const
    {
        return *name;
    }
    void setName ( const std::string n ) {
        (*name) = n;
    }
private:
    std::string * name;
};


int main () {
    Student student("Goku"), teacher = student;
    teacher.setName("Kakarot");
    std::cout << teacher.getName ( ) << std::endl;
    std::cout << student.getName ( ) << std::endl;
}
