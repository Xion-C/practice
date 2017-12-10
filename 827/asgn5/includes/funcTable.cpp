#include <map>
#include <algorithm>
#include <string>
#include "funcTable.h"
#include "literal.h"

const Node* FuncTable::getFunc(const std::string& name) const {
    std::map<std::string, const Node*>::const_iterator it =
      table.find(name);
    if ( it == table.end() ) {
        std::cout << "can not find: " << name << std::endl;
        //throw (name+std::string(" not found"));
        return nullptr;
    }
    return it->second;
}

void FuncTable::setFunc(const std::string& name, const Node* f) {
    table[name] = f;
}
