#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

const Literal* ReturnNode::eval() const {
    if(!rvalue) {
        throw std::string("return error");
    }
    return rvalue->eval();
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
    const Literal* val = Scope::getInstance().getVariableTable().getValue(ident);
    if(val == NULL) {
      throw std::string("ident error");
    }
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
  // const Literal* res = right->eval();
  // const std::string n = static_cast<IdentNode*>(left)->getIdent();
  // Scope::getInstance().getVariableTable().setValue(n, res);
}
const Literal* AsgBinaryNode::eval() const {
    if (!left) {
        throw std::string("asg error, left is nullptr");
    }
    else if (!right) {
        throw std::string("asg error, right is nullptr");
    }
    const Literal* res = right->eval();
    std::string n;
    AsgBinaryNode* leftAsg = dynamic_cast<AsgBinaryNode*>(left);
    if(leftAsg) {
        n = static_cast<IdentNode*>(leftAsg->getRight())->getIdent();
        Scope::getInstance().getVariableTable().setValue(n, res);
        // std::cout << "set " << n << std::endl;
        leftAsg->eval();
    }
    else {
        n = static_cast<IdentNode*>(left)->getIdent();
        Scope::getInstance().getVariableTable().setValue(n, res);
        // std::cout << "set " << n << std::endl;
    }
    if (!res) {
        throw std::string("asg error, no right value");
    }
    // const std::string n = static_cast<IdentNode*>(left)->getIdent();
    return res;
}


const Literal* PlusAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("PlusAsg error");
    }
    const Literal* res = (*(left->eval()))+(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* MinAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))-(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* MulAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))*(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* DivAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).operator/(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* ModAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))%(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* ExpAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).doubleStar(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

const Literal* FlrDivAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).doubleSlash(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    Scope::getInstance().getVariableTable().setValue(n, res);
    return res;
}

/********************************************/
const Literal* AddBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* FlrDivBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).doubleSlash(*y);
}

const Literal* ModBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* ExpBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).doubleStar(*y);
}


const Literal* SuiteNode::eval() const {
    if(stmts.empty()) {
        return nullptr;
    }
    int i = 1;
    for(const Node* n : stmts) {
        if(n) {
            n->eval();
            std::cout << "#" << i++ << std::endl;
        }
    }
    return nullptr;
}


const Literal* FuncNode::eval() const {
    //FuncNode* f = this;
    // Scope::getInstance().getFuncTable().setFunc(name, const_cast<FuncNode*>(this));
    Scope::getInstance().getFuncTable().setFunc(name, this);
    return nullptr;
}

const Literal* CallNode::eval() const {
    const FuncNode* func = Scope::getInstance().getFuncTable().getFunc(funcname);
    std::cout << "fname:" <<func->getName()<< std::endl;
    func->getSuite()->eval();

    return func->eval();
}

// const
