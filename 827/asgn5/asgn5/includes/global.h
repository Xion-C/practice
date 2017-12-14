#ifndef GLOBAL_H
#define GLOBAL_H

#include "literal.h"
#include "ast.h"
#include "funcTable.h"
#include "symbolTable.h"

class Global {
public:
    static Global& getInstance() {
        static Global instance;
        return instance;
    }
    SymbolTable& getVariables() {
        return virables;
    }
    FuncTable& getFuncs() {
        return funcs;
    }
private:
    SymbolTable virables;
    FuncTable funcs;
    Global() : virables() ,funcs() {}
};

#endif /* end of include guard: GLOBAL_H */
