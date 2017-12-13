#include <iostream>
#include <string>
#include <map>
// #include "node.h"
// #include "literal.h"

#include "literal.h"
// #include "ast.h"
#include "symbolTable.h"
#include "funcTable.h"

#include "scopeControl.h"

ScopeControl::ScopeControl() :
currentScope(0), variableTables(), funcTables() {
    variableTables.push_back(SymbolTable());
    funcTables.push_back(FuncTable());
}

ScopeControl& ScopeControl::getInstance() {
    static ScopeControl instance;
    return instance;
}

void ScopeControl::setValue(const std::string& name, const Literal* node) {
    variableTables[currentScope].setValue(name,node);
}

void ScopeControl::setFunc(const std::string& name, const Node* node) {
    funcTables[currentScope].setFunc(name,node);
}

const Literal* ScopeControl::getValue(const std::string & name) {
    std::vector<SymbolTable>::reverse_iterator rit = variableTables.rbegin();

    for (; rit != variableTables.rend() ; ++rit) {
        if(rit->exist(name))
            return rit->getValue(name);
    }

    if ( rit == variableTables.rend() ) throw name + std::string(" not found");

    return 0;
}

const Node* ScopeControl::getSuite(const std::string & name) {
    std::vector<FuncTable>::reverse_iterator rit = funcTables.rbegin();
    for (; rit != funcTables.rend(); ++rit) {
        if (rit->exist(name))
            return rit->getSuite(name);
    }
    if (rit == funcTables.rend()) throw name + std::string(" not found");
    return 0;
}

const Node* ScopeControl::getFunc(const std::string & name) {
    std::vector<FuncTable>::reverse_iterator rit = funcTables.rbegin();
    for (; rit != funcTables.rend(); ++rit) {
        if (rit->exist(name))
            return rit->getFunc(name);
    }
    if (rit == funcTables.rend()) throw name + std::string(" not found");
    return 0;
}

void ScopeControl::pushScope() {
    FuncTable funcTable;
    funcTables.push_back(funcTable);
    SymbolTable variableTable;
    variableTables.push_back(variableTable);
    currentScope++;
}

void ScopeControl::popScope() {
    variableTables.pop_back();
    funcTables.pop_back();
    currentScope--;
}

bool ScopeControl::currentExist(const std::string & name) const {
    return variableTables[currentScope].exist(name);
}
