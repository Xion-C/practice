#ifndef FUNCTABLE_H
#define FUNCTABLE_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
// #include "ast.h"


class Node;

class FuncTable {
public:
    FuncTable() : table() {}
    void setFunc(const std::string& name, const Node* f);
    const Node* getFunc(const std::string& name) const;
    bool exist(const std::string& name) const;
private:
    std::map<std::string, const Node*> table;
};

#endif /* end of include guard: FUNCTABLE_H */
