#ifndef AST__H
#define AST__H

#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"
#include "scopeControl.h"
#include "global.h"
#include "symbolTable.h"
#include "funcTable.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

#define OP_PLUS                 1
#define OP_MINUS                2
#define OP_STAR                 3
#define OP_SLASH                4
#define OP_PERCENT              5
#define OP_DOUBLESLASH          6
#define OP_DOUBLESTAR           7
#define OP_PLUSEQUAL            8
#define OP_MINEQUAL             9
#define OP_STAREQUAL            10
#define OP_SLASHEQUAL           11
#define OP_PERCENTEQUAL         12
#define OP_DOUBLESTAREQUAL      13
#define OP_DOUBELSLASHEQUAL     14
#define OP_EQEQUAL              15
#define OP_GREATER              16
#define OP_GREATEREQUAL         17
#define OP_LESS                 18
#define OP_LESSEQUAL            19
#define OP_NOTEQUAL             20

/* identifier */
class IdentNode : public Node {
public:
    IdentNode(const std::string id) : Node(), ident(id) { }
    virtual ~IdentNode() {}
    const std::string getIdent() const { return ident; }
    virtual const Literal* eval() const;
    virtual void print() const {
      std::cout << "IDENTIFIER: " << ident << std::endl;
    }
private:
    std::string ident;
};

/******************* UnaryNode *******************/
class UnaryNode : public Node {
public:
    UnaryNode(Node* r) : Node(), right(r) {}
    virtual ~UnaryNode() {}
    virtual const Literal* eval() const = 0;
    Node* getRight() const { return right; }
    UnaryNode(const UnaryNode&) = delete;
    UnaryNode& operator=(const UnaryNode&) = delete;
protected:
    Node* right;
};

class PositiveUnaryNode : public UnaryNode {
public:
    PositiveUnaryNode(Node* right) : UnaryNode(right) {}
    virtual const Literal* eval() const;
};

class NegativeUnaryNode : public UnaryNode {
public:
    NegativeUnaryNode(Node* right) : UnaryNode(right) {}
    virtual const Literal* eval() const;
};

/******************* BinaryNode *******************/
class BinaryNode : public Node {
public:
    BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
    virtual ~BinaryNode() {}
    virtual const Literal* eval() const = 0;
    Node* getLeft()  const { return left; }
    Node* getRight() const { return right; }
    BinaryNode(const BinaryNode&) = delete;
    BinaryNode& operator=(const BinaryNode&) = delete;
protected:
    Node *left;
    Node *right;
};

/*------------------ Assignment ------------------*/
class AsgBinaryNode : public BinaryNode {
public:
    AsgBinaryNode(Node* left, Node* right);
    virtual const Literal* eval() const;
};

class PlusAsgBinaryNode : public BinaryNode {
public:
    PlusAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class MinAsgBinaryNode : public BinaryNode {
public:
    MinAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class MulAsgBinaryNode : public BinaryNode {
public:
    MulAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class DivAsgBinaryNode : public BinaryNode {
public:
    DivAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class ModAsgBinaryNode : public BinaryNode {
public:
    ModAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class ExpAsgBinaryNode : public BinaryNode {
public:
    ExpAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class FlrDivAsgBinaryNode : public BinaryNode {
public:
    FlrDivAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

/*------------------ Arithmetic ------------------*/
class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class FlrDivBinaryNode : public BinaryNode {
public:
  FlrDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class ExpBinaryNode : public BinaryNode {
public:
  ExpBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

/* compare */
class LessBinaryNode : public BinaryNode {
public:
    LessBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class GreaterBinaryNode : public BinaryNode {
public:
    GreaterBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class EqequalBinaryNode : public BinaryNode {
public:
    EqequalBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class LessEqualBinaryNode : public BinaryNode {
public:
    LessEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class GreaterEqualBinaryNode : public BinaryNode {
public:
    GreaterEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};

class NotEqualBinaryNode : public BinaryNode {
public:
    NotEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
    virtual const Literal* eval() const;
};


/*******************************************************/
class PrintNode : public Node {
public:
    PrintNode(Node* p) : Node(), prints(p) {}
    virtual ~PrintNode() {}
    virtual const Literal* eval() const;
    PrintNode(const PrintNode&) = delete;
    PrintNode& operator=(const PrintNode&) = delete;
private:
    Node* prints;
};


class ReturnNode : public Node {
public:
    ReturnNode(Node* r) : Node(), rvalue(r) {}
    virtual ~ReturnNode() {}
    virtual const Literal* eval() const;
    ReturnNode(const ReturnNode&) = delete;
    ReturnNode& operator=(const ReturnNode&) = delete;
private:
    Node* rvalue;
};

class SuiteNode : public Node {
public:
    SuiteNode() : Node(), stmts() {}
    virtual ~SuiteNode() {}
    void add(Node* s) { stmts.push_back(s); }
    virtual const Literal* eval() const;
    SuiteNode(const SuiteNode&) = delete;
    SuiteNode& operator=(const SuiteNode&) = delete;
private:
    std::vector<Node *> stmts;
};


class FuncNode : public Node {
public:
    FuncNode(std::string id, Node* s) :
    Node(), name(id), paras(), virableTable(), outerFunc(), nestedFuncTable(), suite(s), returnValue(), p(this) {}
    virtual ~FuncNode() {}
    virtual const Literal* eval() const;
    FuncNode(const FuncNode&) = delete;
    FuncNode& operator=(const FuncNode&) = delete;
private:
    std::string name;
    std::vector<Node*> paras;
    std::map<std::string, const Literal*> virableTable;
    FuncNode* outerFunc;
    std::map<std::string, const FuncNode*> nestedFuncTable;
    Node* suite;
    Literal* returnValue;
    const FuncNode* p;
};

class CallNode : public Node {
public:
    CallNode(std::string name ) : Node(), name(name) {}
    virtual ~CallNode() {}
    virtual const Literal* eval() const;
    CallNode(const CallNode&) = delete;
    CallNode& operator=(const CallNode&) = delete;
private:
    std::string name;
};

class IfNode : public Node {
public:
    IfNode(Node* t, Node* s1, Node* s2) : Node(), test(t), ifsuite(s1), elsesuite(s2) {}
    virtual ~IfNode() {}
    virtual const Literal* eval() const;
    IfNode(const IfNode&) = delete;
    IfNode& operator=(const IfNode&) = delete;
private:
    Node* test;
    Node* ifsuite;
    Node* elsesuite;
};


#endif
