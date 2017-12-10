#ifndef SCOPECONTOL_H
#define SCOPECONTOL_H

#include <iostream>
#include <string>
#include <map>
// #include "node.h"
// #include "literal.h"
#include "ast.h"
#include "symbolTable.h"
#include "global.h"

class FuncNode;
// class Global;
// class SymbolTable;

// class GlobalVaribleTable : public SymbolTable {
// public:
//     static GlobalVaribleTable& getInstance() {
//         static GlobalVaribleTable instance;
//         return instance;
//     }
// private:
//     GlobalVaribleTable() {}
// };

class Scope {
public:
    static Scope& getInstance() {
        static Scope instance;
        return instance;
    }
    //void scopeIn(FuncNode* func) {
    void scopeIn() {
        // currentFunc = func;
        currentScope++;
    }
    void scopeOut() {
        // currentFunc = currentFunc->getOuterFunc();
        currentScope--;
    }
    int getScope() {
        return currentScope;
    }
    SymbolTable& getVariableTable() {
        return Global::getInstance().getVariables();
    }
    FuncTable& getFuncTable() {
        return Global::getInstance().getFuncs();
    }
private:
    FuncNode* currentFunc;
    int currentScope;
    Scope() : currentFunc(), currentScope(0) {}
};

#endif
