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

class Node;

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
    // void scopeIn(const Node* func) {
    // // void scopeIn() {
    //     currentFunc = func;
    //     currentScope++;
    // }
    void scopeIn(const Node* func);

    // void scopeOut() {
    //     if(currentFunc) {
    //         const Node* cf = currentFunc->getOuterFunc();
    //         currentFunc = cf;
    //         currentScope--;
    //     }
    //     else {
    //         throw std::string("scope error");
    //     }
    // }
    void scopeOut();

    int getScope() {
        return currentScope;
    }

    // SymbolTable& getVariableTable() {
    //     return Global::getInstance().getVariables();
    // }
    SymbolTable& getVariableTable();

    // FuncTable& getFuncTable() {
    //     return Global::getInstance().getFuncs();
    // }
    FuncTable& getFuncTable();

    const Node* getCurrentFunc() const {
        return currentFunc;
    }
private:
    const Node* currentFunc;
    int currentScope;
    Scope() : currentFunc(), currentScope(0) {}
};

#endif
