#include <iostream>
#include <string>
#include <map>
// #include "node.h"
// #include "literal.h"

#include "literal.h"
// #include "ast.h"
#include "symbolTable.h"
#include "funcTable.h"

#include "global.h"

#include "scopeControl.h"

void Scope::scopeIn(const Node* func) {
// void scopeIn() {
    currentFunc = func;
    currentScope++;
}

void Scope::scopeOut() {
    if(currentFunc) {
        const FuncNode* cf = dynamic_cast<const FuncNode*>(currentFunc);
        const FuncNode* cfouter = cf->getOuterFunc();
        currentFunc = cfouter;
        currentScope--;
    }
    else {
        throw std::string("scope error");
    }
}


SymbolTable& Scope::getVariableTable() {
    return Global::getInstance().getVariables();
}

FuncTable& Scope::getFuncTable() {
    return Global::getInstance().getFuncs();
}
