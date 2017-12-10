#include <map>
#include <algorithm>
#include <string>
#include "funcTable.h"
#include "ast.h"

const FuncNode* FuncTable::getFunc(const std::string& name) const {
    std::map<std::string, const FuncNode*>::const_iterator it =
      table.find(name);
    if ( it == table.end() ) {
        std::cout << "can not find: " << name << std::endl;
        //throw (name+std::string(" not found"));
        return nullptr;
    }
    return it->second;
}

// void FuncTable::setFunc(const std::string& name, const FuncNode* f) {
//     table[name] = f;
// }
