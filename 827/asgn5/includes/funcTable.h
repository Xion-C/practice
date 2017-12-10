#ifndef FUNCTABLE_H
#define FUNCTABLE_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "ast.h"

class FuncNode;

class FuncTable {
public:
    FuncTable() : table() {}
    // void setFunc(const std::string& name, const FuncNode* f);
    void setFunc(const std::string& name, const FuncNode* f) {
        table[name] = f;
    } //if put this definition into .cpp, it will not work. I do not know why
    // const FuncNode* getFunc(const std::string& name) const;
    // const FuncNode* getFunc(std::string const& name) const;
    const FuncNode* getFunc(const std::string& name) const {
        std::map<std::string, const FuncNode*>::const_iterator it =
          table.find(name);
        if ( it == table.end() ) {
            std::cout << "can not find: " << name << std::endl;
            //throw (name+std::string(" not found"));
            return nullptr;
        }
        return it->second;
    }

private:
    std::map<std::string, const FuncNode*> table;
};

#endif /* end of include guard: FUNCTABLE_H */
