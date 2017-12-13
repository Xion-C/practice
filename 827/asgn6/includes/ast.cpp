#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

/************************ DATA STRUCTURE ************************/
const Literal* IdentNode::eval() const {
    const Literal* val = ScopeControl::getInstance().getValue(ident);
    if(val == NULL) {
      throw std::string("ident error");
    }
    return val;
}

const Literal* ElementsNode::eval() const {
    return nullptr;
}
void ElementsNode::print() const {
    for(const Node* element : elements) {
        if(!element) {
            std::cout << "None" << std::endl;
        }
        else {
            const Node* node = element->eval();
            if(!node) {
                if(dynamic_cast<const IdentNode*>(node)) {
                    element->print();
                }
                else {
                    std::cout << "None" << std::endl;
                }
            }
            else {
                node->print();
            }
        }
    }
}

/************************ OPERATOR ************************/
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
  // ScopeControl::getInstance().setValue(n, res);
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
        ScopeControl::getInstance().setValue(n, res);
        // std::cout << "set " << n << std::endl;
        leftAsg->eval();
    }
    else {
        n = static_cast<IdentNode*>(left)->getIdent();
        ScopeControl::getInstance().setValue(n, res);
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
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* MinAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))-(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* MulAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))*(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* DivAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).operator/(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* ModAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval()))%(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* ExpAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).doubleStar(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
    return res;
}

const Literal* FlrDivAsgBinaryNode::eval() const {
    if (!left || !right) {
        throw std::string("error");
    }
    const Literal* res = (*(left->eval())).doubleSlash(*(right->eval()));
    const std::string n = static_cast<IdentNode*>(left)->getIdent();
    ScopeControl::getInstance().setValue(n, res);
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

/* compare */
const Literal* LessBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).less(*y);
}

const Literal* GreaterBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).greater(*y);
}

const Literal* EqequalBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).eqequal(*y);
}

const Literal* LessEqualBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).lessEqual(*y);
}

const Literal* GreaterEqualBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).greaterEqual(*y);
}

const Literal* NotEqualBinaryNode::eval() const {
    if (!left || !right) {
      throw std::string("error");
    }
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    return (*x).notEqual(*y);
}

/***********************************************************/
const Literal* PrintNode::eval() const {
    if(!elements) {
        std::cout << "" << std::endl;
    }
    else if (dynamic_cast<const ElementsNode*>(elements)) {
        elements->print();
    }
    else {
        const Literal* node = elements->eval();
        if(!node) {
            std::cout << "None" << std::endl;
        }
        else {
            node->print();
        }
        //elements->eval()->print();
    }
    return nullptr;
}

const Literal* ReturnNode::eval() const {
    const Literal* res;
    if(!rvalue) {
        res = nullptr;
    }
    else {
        res = rvalue->eval();
    }
    ScopeControl::getInstance().setValue("__RETURN__", res);
    return res;
}

const Literal* CallNode::eval() const {
    ScopeControl& scope = ScopeControl::getInstance();
    const FuncNode* func = dynamic_cast<const FuncNode*>(scope.getFunc(name));
    if(!args) {
        if(func->getParas()) {
            throw std::string("invalid functions paras");
        }
        else {
            scope.pushScope();
            const Literal* res = scope.getSuite(name)->eval();
            scope.popScope();
            return res;
        }
    }
    else {
        if(!func->getParas()) {
            throw std::string("invalid functions paras");
        }
        else {
            const FuncParasNode* fps = dynamic_cast<const FuncParasNode*>(func->getParas());
            const ArgsNode* ags = dynamic_cast<const ArgsNode*>(args);
            if((!fps && ags) || (fps && !ags) || (fps->getParaSize() != ags->getArgSize())) {
                throw std::string("invalid functions paras");
            }
            else {
                scope.pushScope();
                const IdentNode* id;
                const Literal* val;
                for(int i = 0; i < fps->getParaSize(); i++) {
                    id = dynamic_cast<const IdentNode*>(fps->getPara(i));
                    //id = fps->getPara(i);
                    //val = ags->getArg(i);
                    std::string n = id->getIdent();
                    val = ags->getArg(i)->eval();
                    ScopeControl::getInstance().setValue(n, val);
                }
                const Literal* res = scope.getSuite(name)->eval();
                scope.popScope();
                return res;
            }
        }
    }
    return nullptr;
}

const Literal* IfNode::eval() const {
    if(!test) return nullptr;
    const Literal* t_res = test->eval();
    // t_res->print(); //print 0 or 1
    if(!t_res) throw std::string("if test error");
    if(t_res->isTrue()) {
        if(ifsuite) {
            ifsuite->eval();
        }
    }
    else if(elsesuite) {
        elsesuite->eval();
    }
    return nullptr;
}

const Literal* FuncNode::eval() const {
    //ScopeControl::getInstance().setFunc(name, suite);
    ScopeControl::getInstance().setFunc(name, this);
    return nullptr;
}
const Node* FuncNode::getPara(int n) const {
    const FuncParasNode* fp = dynamic_cast<const FuncParasNode*>(paras);
    if(fp) {
        return fp->getPara(n);
    }
    else {
        throw std::string("FuncParasNode type error");
    }
}
int FuncNode::getParaSize() const {
    const FuncParasNode* fp = dynamic_cast<const FuncParasNode*>(paras);
    if(fp) {
        return fp->getParaSize();
    }
    else {
        throw std::string("FuncParasNode type error");
    }
}

/************************ FUNCTION ************************/
const Literal* SuiteNode::eval() const {
    if(stmts.empty()) {
        return nullptr;
    }
    // int i = 1;
    for(const Node* n : stmts) {
        if(n) {
            n->eval();
            // std::cout << "#" << i++ << std::endl;
            if(ScopeControl::getInstance().currentExist("__RETURN__")) {
                return ScopeControl::getInstance().getValue("__RETURN__");
            }
        }
        else {
            std::cout << "null statement" << std::endl;
        }
    }
    return nullptr;
}

const Literal* ArgsNode::eval() const {
    return nullptr;
}

const Literal* FuncParasNode::eval() const {
    return nullptr;
}

/************************ Tracer ************************/
//just use to track the parser
const Literal* TracerNode::eval() const {
    std::cout << "impossible to evaluate Tracer" << std::endl;
    return nullptr;
}

// const
