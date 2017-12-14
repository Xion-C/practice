#include <map>
#include <algorithm>
#include <string>
#include "funcTable.h"
#include "literal.h"
#include "ast.h"

const Node* FuncTable::getSuite(const std::string& name) const {
    std::map<std::string, const Node*>::const_iterator it = table.find(name);
    if ( it == table.end() ) {
        //std::cout << "can not find: " << name << std::endl;
        throw (name+std::string(" not found"));
        return nullptr;
    }
    const FuncNode* func = dynamic_cast<const FuncNode*>(it->second);
    if(!func) throw std::string("can not get function");
    return func->getSuite();
}

const Node* FuncTable::getFunc(const std::string& name) const {
    std::map<std::string, const Node*>::const_iterator it = table.find(name);
    if ( it == table.end() ) {
        //std::cout << "can not find: " << name << std::endl;
        throw (name+std::string(" not found"));
        return nullptr;
    }
    const FuncNode* func = dynamic_cast<const FuncNode*>(it->second);
    if(!func) throw std::string("can not get function");
    return func;
}

void FuncTable::setFunc(const std::string& name, const Node* f) {
    table[name] = f;
}

bool FuncTable::exist(const std::string& name) const {
    std::map<std::string, const Node*>::const_iterator it = table.find(name);
    if ( it == table.end() ) return false;
    else return true;
}
