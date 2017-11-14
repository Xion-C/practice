#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

const Literal* IdentNode::eval() const { 
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  return val;
}


AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* PosUnaryNode::eval() const {
  if (!unary){
    throw "error";
  }
  const Literal* res = unary->eval()->operator+();

  const std::string n = static_cast<IdentNode*>(unary)->getIdent();
  SymbolTable::getInstance().setValue(n,res);
  return res;
}

const Literal* NegUnaryNode::eval() const {
  if (!unary){
    throw "error";
  }
  //const Literal* res = (unary->eval())->operator-();

  const Literal* x = unary->eval();
  const Literal* res = (*x).operator-();
  const std::string n = static_cast<IdentNode*>(unary)->getIdent();
  SymbolTable::getInstance().setValue(n,res);
  return res;
}

const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

const Literal* AddEqualBinaryNode::eval() const {
  if (!left || !right)
  {
    throw "eror";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = (*x).operator+(*y);
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n,res);
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubEqualBinaryNode::eval() const {
  if (!left || !right)
  {
    throw "eror";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = ((*x) - (*y));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n,res);
  return res;
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* PercentBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* DbStarBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)^(*y));
}


const Literal* DbSlashBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).DbSlash(*y);
}
