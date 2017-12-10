#include <map>
#include <algorithm>
#include <string>
#include "symbolTable.h"
#include "literal.h"

const Literal* SymbolTable::getValue(const std::string& name) const {
    std::map<std::string, const Literal*>::const_iterator it =
      table.find(name);
    if ( it == table.end() ) {
        std::cout << "can not find: " << name << std::endl;
        //throw (name+std::string(" not found"));
        return nullptr;
    }
    return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) {
    table[name] = val;
}

bool SymbolTable::exist(const std::string& name) const {
    std::map<std::string, const Literal*>::const_iterator it = table.find(name);
    if ( it == table.end() ) return false;
    else return true;
}
