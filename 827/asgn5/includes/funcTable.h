#ifndef FUNCTABLE_H
#define FUNCTABLE_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class FuncNode;

class FuncTable {
public:
    FuncTable() : table() {}
    // void setFunc(const std::string& name, const FuncNode* f);
    void setFunc(const std::string& name, const FuncNode* f) {
        table[name] = f;
    } //if put this definition into .cpp, it will not work. I do not know why
    const FuncNode* getFunc(const std::string& name) const;
private:
    std::map<std::string, const FuncNode*> table;
};

#endif /* end of include guard: FUNCTABLE_H */
