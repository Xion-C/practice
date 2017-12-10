#ifndef SCOPECONTOL_H
#define SCOPECONTOL_H

#include <iostream>
#include <string>
#include <map>
// #include "node.h"
// #include "literal.h"
#include "ast.h"

class FuncNode;

class SyntaxScope {
public:
    static SyntaxScope& getInstance() {
        static SyntaxScope instance;
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
private:
    FuncNode* currentFunc;
    int currentScope;
    SyntaxScope() : currentFunc(), currentScope(0) {}
};

#endif
