#ifndef NODETYPE_H
#define NODETYPE_H

#include "node.h"
#include "literal.h"
#include "ast.h"

#define T_NODE              1
#define T_LITERAL           2

#define T_FLOATLITERAL      3
#define T_INTLITERAL        4
#define T_IDENT             5

#define T_UNARY             6
#define T_POSITIVEUNARY     7
#define T_NEGATIVEUNARY     8

#define T_BINARY            9

#define T_ASGBINARY         10
#define T_PLUSASGBINARY     11
#define T_MINASGBINARY      12
#define T_MULASGBINARY      13
#define T_DIVASGBINARY      14
#define T_MODASGBINARY      15
#define T_EXPASGBINARY      16
#define T_FLRDIVASGBINARY   17

#define T_ADDBINARY         18
#define T_SUBBINARY         19
#define T_MULBINARY         20
#define T_DIVBINARY         21
#define T_FLRDIVBINARY      22
#define T_MODBINARY         23
#define T_EXPBINARY         24

#define T_FUNC              25
#define T_RETURN            26
#define T_CALL              27
#define T_SUITE             28
#define T_PRINT             29

#define T_ASG               101
#define T_EXPR              102
#define T_VAL               103

int nodeType(const Node* node) {
    int res = 0;
    if(dynamic_cast<const Node*>(node)) {
        res = T_NODE;
    }
    if(dynamic_cast<const Literal*>(node)) {
        res = T_LITERAL;
    }
    if(dynamic_cast<const FloatLiteral*>(node)) {
        res = T_FLOATLITERAL;
    }
    if(dynamic_cast<const IntLiteral*>(node)) {
        res = T_INTLITERAL;
    }
    if(dynamic_cast<const IdentNode*>(node)) {
        res = T_IDENT;
    }
    if(dynamic_cast<const UnaryNode*>(node)) {
        res = T_UNARY;
    }
    if(dynamic_cast<const PositiveUnaryNode*>(node)) {
        res = T_POSITIVEUNARY;
    }
    if(dynamic_cast<const NegativeUnaryNode*>(node)) {
        res = T_NEGATIVEUNARY;
    }
    if(dynamic_cast<const BinaryNode*>(node)) {
        res = T_BINARY;
    }
    if(dynamic_cast<const AsgBinaryNode*>(node)) {
        res = T_ASGBINARY;
    }
    if(dynamic_cast<const PlusAsgBinaryNode*>(node)) {
        res = T_PLUSASGBINARY;
    }
    if(dynamic_cast<const MinAsgBinaryNode*>(node)) {
        res = T_MINASGBINARY;
    }
    if(dynamic_cast<const MulAsgBinaryNode*>(node)) {
        res = T_MULASGBINARY;
    }
    if(dynamic_cast<const DivAsgBinaryNode*>(node)) {
        res = T_DIVASGBINARY;
    }
    if(dynamic_cast<const ModAsgBinaryNode*>(node)) {
        res = T_MODASGBINARY;
    }
    if(dynamic_cast<const ExpAsgBinaryNode*>(node)) {
        res = T_EXPASGBINARY;
    }
    if(dynamic_cast<const FlrDivAsgBinaryNode*>(node)) {
        res = T_FLRDIVASGBINARY;
    }
    if(dynamic_cast<const AddBinaryNode*>(node)) {
        res = T_ADDBINARY;
    }
    if(dynamic_cast<const SubBinaryNode*>(node)) {
        res = T_SUBBINARY;
    }
    if(dynamic_cast<const MulBinaryNode*>(node)) {
        res = T_MULBINARY;
    }
    if(dynamic_cast<const DivBinaryNode*>(node)) {
        res = T_DIVBINARY;
    }
    if(dynamic_cast<const FlrDivBinaryNode*>(node)) {
        res = T_FLRDIVBINARY;
    }
    if(dynamic_cast<const ModBinaryNode*>(node)) {
        res = T_MODBINARY;
    }
    if(dynamic_cast<const ExpBinaryNode*>(node)) {
        res = T_EXPBINARY;
    }
    if(dynamic_cast<const FuncNode*>(node)) {
        res = T_FUNC;
    }
    if(dynamic_cast<const ReturnNode*>(node)) {
        res = T_RETURN;
    }
    if(dynamic_cast<const CallNode*>(node)) {
        res = T_CALL;
    }
    if(dynamic_cast<const SuiteNode*>(node)) {
        res = T_SUITE;
    }
    if(dynamic_cast<const PrintNode*>(node)) {
        res = T_PRINT;
    }

    return res;
}

int nodeGroup(const Node* node) {
    int res = nodeType(node);
    switch(res) {
        case T_FLOATLITERAL:
        case T_INTLITERAL:
        case T_IDENT:
            res = T_VAL;
            break;
        case T_ASG:
        case T_PLUSASGBINARY:
        case T_MINASGBINARY:
        
    }
}



#endif /* end of include guard: NODETYPE_H */
