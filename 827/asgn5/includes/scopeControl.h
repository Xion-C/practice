#ifndef SCOPECONTOL_H
#define SCOPECONTOL_H

#include <iostream>
#include <string>
#include <map>
// #include "node.h"
#include "literal.h"
// #include "ast.h"
#include "symbolTable.h"
#include "funcTable.h"

#include "global.h"

class Literal;

class ScopeControl {
public:
    static ScopeControl& getInstance();

    //set value in variableTables
    void  setValue(const std::string& name, const Literal* node);
    //set function in funcTables
    void  setFunc(const std::string& name, const Node* node);

    const Literal* getValue(const std::string & name);
    const Node* getFunc(const std::string & name);

    void  pushScope();
    void  popScope();

    bool currentExist(const std::string & name) const;

private:
    int currentScope;
    std::vector<SymbolTable> variableTables;
    std::vector<FuncTable> funcTables;
    ScopeControl();
};


#endif
