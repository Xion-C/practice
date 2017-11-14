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

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

#define OP_PLUS 1
#define OP_MINUS 2
#define OP_STAR 3
#define OP_SLASH 4
#define OP_PERCENT 5
#define OP_DOUBLESLASH 6
#define OP_DOUBLESTAR 7

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

class UnaryNode : public Node {
public:
    UnaryNode(Node* r) : Node(), right(r) {}
    // virtual ~UnaryNode() {}
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

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  // virtual ~BinaryNode() {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

#endif