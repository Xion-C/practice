#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

const Literal* FuncNode::eval() const {
    return nullptr;
}

const Literal* ReturnNode::eval() const {
    if(!rvalue) {
        throw "error";
    }
    return rvalue->eval();
}

const Literal* CallNode::eval() const {
    return func->eval();
}

const Literal* SuiteNode::eval() const {
    if(stmts.empty()) {
        return nullptr;
    }
    for(const Node* n : stmts) {
        n->eval();
    }
    return nullptr;
}

const Literal* PrintNode::eval() const {
    if(!prints) {
        std::cout << "" << std::endl;
    }
    else {
        prints->eval()->print();
    }
    return nullptr;
}

const Literal* IdentNode::eval() const {
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  if(val == NULL) { throw "ident error"; }
  return val;
}

const Literal* PositiveUnaryNode::eval() const {
    const Literal* res = right->eval();
    return res;
}

const Literal* NegativeUnaryNode::eval() const {
    const Literal* res = right->eval()->opposite();
    return res;
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


PlusAsgBinaryNode::PlusAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval()))+(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* PlusAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


MinAsgBinaryNode::MinAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval()))-(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* MinAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

MulAsgBinaryNode::MulAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval()))*(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* MulAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


DivAsgBinaryNode::DivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval())).operator/(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* DivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


ModAsgBinaryNode::ModAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval()))%(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* ModAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


ExpAsgBinaryNode::ExpAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval())).doubleStar(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* ExpAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


FlrDivAsgBinaryNode::FlrDivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = (*(left->eval())).doubleSlash(*(right->eval()));
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}
const Literal* FlrDivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}


/********************************************/
const Literal* AddBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
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

const Literal* FlrDivBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).doubleSlash(*y);
}

const Literal* ModBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* ExpBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).doubleStar(*y);
}
