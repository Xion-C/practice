#ifndef SCOPECONTOL_H
#define SCOPECONTOL_H

#include <iostream>
#include <string>
#include <map>
// #include "node.h"
// #include "literal.h"
#include "ast.h"

class SyntaxScope {
public:
    //
    static SyntaxScope& getInstance();
private:
    FuncNode* currentFunc;
    int currentScope;
    SyntaxScope() : currentScope(0) {}
}

#endif