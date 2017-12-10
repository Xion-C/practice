#ifndef LITERAL__H
#define LITERAL__H

#include "node.h"
#include "poolOfNodes.h"
#include <cmath>
#include <iostream>
#include <string>

#define LIMIT 0.00001

class Literal : public Node {
public:
    virtual ~Literal() {}

    virtual const Literal* operator+(const Literal& rhs) const =0;
    virtual const Literal* opPlus(float) const =0;
    virtual const Literal* opPlus(int) const =0;

    virtual const Literal* operator*(const Literal& rhs) const =0;
    virtual const Literal* opMult(float) const =0;
    virtual const Literal* opMult(int) const =0;

    virtual const Literal* operator-(const Literal& rhs) const =0;
    virtual const Literal* opSubt(float) const =0;
    virtual const Literal* opSubt(int) const =0;

    virtual const Literal* operator/(const Literal& rhs) const =0;
    virtual const Literal* opDiv(float) const =0;
    virtual const Literal* opDiv(int) const =0;

    virtual const Literal* doubleSlash(const Literal& rhs) const =0;
    virtual const Literal* opDoubleSlash(float) const =0;
    virtual const Literal* opDoubleSlash(int) const =0;

    virtual const Literal* operator%(const Literal& rhs) const =0;
    virtual const Literal* opMod(float) const =0;
    virtual const Literal* opMod(int) const =0;

    virtual const Literal* doubleStar(const Literal& rhs) const =0;
    virtual const Literal* opDoubleStar(float) const =0;
    virtual const Literal* opDoubleStar(int) const =0;

    virtual const Literal* less(const Literal& rhs) const =0;
    virtual const Literal* opLess(float) const =0;
    virtual const Literal* opLess(int) const =0;

    virtual const Literal* greater(const Literal& rhs) const =0;
    virtual const Literal* opGreater(float) const =0;
    virtual const Literal* opGreater(int) const =0;

    virtual const Literal* eqequal(const Literal& rhs) const =0;
    virtual const Literal* opEqequal(float) const =0;
    virtual const Literal* opEqequal(int) const =0;

    virtual const Literal* lessEqual(const Literal& rhs) const =0;
    virtual const Literal* opLessEqual(float) const =0;
    virtual const Literal* opLessEqual(int) const =0;

    virtual const Literal* greaterEqual(const Literal& rhs) const =0;
    virtual const Literal* opGreaterEqual(float) const =0;
    virtual const Literal* opGreaterEqual(int) const =0;

    virtual const Literal* notEqual(const Literal& rhs) const =0;
    virtual const Literal* opNotEqual(float) const =0;
    virtual const Literal* opNotEqual(int) const =0;

    virtual const Literal* opposite() const =0;
    virtual bool isTrue() const =0;

    virtual const Literal* eval() const = 0;
    virtual void print() const {
    std::cout << "No Way" << std::endl;
    }
};


class FloatLiteral: public Literal {
public:
    FloatLiteral(float _val): val(_val) {}

    virtual const Literal* operator+(const Literal& rhs) const  {
        return rhs.opPlus(val);
    }
    virtual const Literal* opPlus(float lhs) const  {
        const Literal* node = new FloatLiteral(lhs + val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opPlus(int lhs) const  {
        const Literal* node = new FloatLiteral(lhs + val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator-(const Literal& rhs) const  {
        return rhs.opSubt(val);
    }
    virtual const Literal* opSubt(float lhs) const  {
        const Literal* node = new FloatLiteral(lhs - val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opSubt(int lhs) const  {
        const Literal* node = new FloatLiteral(lhs - val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
    }
    virtual const Literal* opMult(float lhs) const  {
        const Literal* node = new FloatLiteral(lhs * val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opMult(int lhs) const  {
        const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator/(const Literal& rhs) const  {
        return rhs.opDiv(val);
    }
    virtual const Literal* opDiv(float lhs) const  {
        if ( val == 0 ) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs / val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDiv(int lhs) const  {
        if ( val == 0 ) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs / val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* doubleSlash(const Literal& rhs) const {
        return rhs.opDoubleSlash(val);
    }
    virtual const Literal* opDoubleSlash(float lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDoubleSlash(int lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator%(const Literal& rhs) const {
        return rhs.opMod(val);
    }
    virtual const Literal* opMod(float lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs - val * floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opMod(int lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs - val * floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* doubleStar(const Literal& rhs) const {
        return rhs.opDoubleStar(val);
    }
    virtual const Literal* opDoubleStar(float lhs) const {
        const Literal* node = new FloatLiteral(powf(lhs, val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDoubleStar(int lhs) const {
        const Literal* node = new FloatLiteral(powf(lhs, val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    /*** compare ****/
    virtual const Literal* less(const Literal& rhs) const {
        return rhs.opLess(val);
    }
    virtual const Literal* opLess(float lhs) const {
        const Literal* res;
        if(lhs < val)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opLess(int lhs) const {
        const Literal* res;
        if(lhs < val)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* greater(const Literal& rhs) const {
        return rhs.opGreater(val);
    }
    virtual const Literal* opGreater(float lhs) const {
        const Literal* res;
        if(lhs > val)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opGreater(int lhs) const {
        const Literal* res;
        if(lhs > val)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* eqequal(const Literal& rhs) const {
        return rhs.opEqequal(val);
    }
    virtual const Literal* opEqequal(float lhs) const {
        const Literal* res;
        if(fabs(lhs - val) < LIMIT)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opEqequal(int lhs) const {
        const Literal* res;
        if(fabs(lhs - val) < LIMIT)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* lessEqual(const Literal& rhs) const {
        return rhs.opLessEqual(val);
    }
    virtual const Literal* opLessEqual(float lhs) const {
        const Literal* res;
        if(float(lhs) <= float(val))
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opLessEqual(int lhs) const {
        const Literal* res;
        if(float(lhs) <= float(val))
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* greaterEqual(const Literal& rhs) const {
        return rhs.opGreaterEqual(val);
    }
    virtual const Literal* opGreaterEqual(float lhs) const {
        const Literal* res;
        if(float(lhs) >= float(val))
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opGreaterEqual(int lhs) const {
        const Literal* res;
        if(float(lhs) >= float(val))
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;

    }

    virtual const Literal* notEqual(const Literal& rhs) const {
        return rhs.opNotEqual(val);
    }
    virtual const Literal* opNotEqual(float lhs) const {
        const Literal* res;
        if(fabs(lhs - val) > LIMIT)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opNotEqual(int lhs) const {
        const Literal* res;
        if(fabs(lhs - val) > LIMIT)
            res = new FloatLiteral(1);
        else
            res = new FloatLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }


    virtual const Literal* opposite() const {
        const Literal* node = new FloatLiteral(-val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual bool isTrue() const {
        if(val) return true;
        else return false;
    }

    virtual const Literal* eval() const { return this; }
    virtual void print() const {
        std::cout << "FLOAT: " << val << std::endl;
    }
private:
    float val;
};

class IntLiteral: public Literal {
public:
    IntLiteral(int _val): val(_val) {}

    virtual const Literal* operator+(const Literal& rhs) const  {
        return rhs.opPlus(val);
    }
    virtual const Literal* opPlus(float lhs) const  {
        const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opPlus(int lhs) const  {
        const Literal* node = new IntLiteral(lhs + val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator-(const Literal& rhs) const  {
        return rhs.opSubt(val);
    }
    virtual const Literal* opSubt(float lhs) const  {
        const Literal* node = new FloatLiteral(lhs - val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opSubt(int lhs) const  {
        const Literal* node = new IntLiteral(lhs - val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator*(const Literal& rhs) const  {
        return rhs.opMult(val);
    }
    virtual const Literal* opMult(float lhs) const  {
        const Literal* node = new FloatLiteral(lhs * val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opMult(int lhs) const  {
        const Literal* node = new IntLiteral(lhs * val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator/(const Literal& rhs) const  {
        return rhs.opDiv(val);
    }
    virtual const Literal* opDiv(float lhs) const  {
        if ( val == 0 ) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs / val);
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDiv(int lhs) const  {
        if ( val == 0 ) throw std::string("Zero Division Error");
        int r = (int)(floor(static_cast<float>(lhs) / static_cast<float>(val)));
        const Literal* node = new IntLiteral(r);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* doubleSlash(const Literal& rhs) const {
        return rhs.opDoubleSlash(val);
    }
    virtual const Literal* opDoubleSlash(float lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDoubleSlash(int lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        int r = (int)(floor(static_cast<float>(lhs) / static_cast<float>(val)));
        const Literal* node = new IntLiteral(r);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* operator%(const Literal& rhs) const {
        return rhs.opMod(val);
    }
    virtual const Literal* opMod(float lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        const Literal* node = new FloatLiteral(lhs - val * floor(lhs / val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opMod(int lhs) const {
        if ( val == 0) throw std::string("Zero Division Error");
        int r = lhs - val * (int)(floor((float)lhs / (float)val));
        const Literal* node = new IntLiteral(r);
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    virtual const Literal* doubleStar(const Literal& rhs) const {
        return rhs.opDoubleStar(val);
    }
    virtual const Literal* opDoubleStar(float lhs) const {
        const Literal* node = new FloatLiteral(powf(lhs, val));
        PoolOfNodes::getInstance().add(node);
        return node;
    }
    virtual const Literal* opDoubleStar(int lhs) const {
        const Literal* node = new IntLiteral((int)(powf(lhs, val)));
        PoolOfNodes::getInstance().add(node);
        return node;
    }

    /*** compare ****/
    virtual const Literal* less(const Literal& rhs) const {
        return rhs.opLess(val);
    }
    virtual const Literal* opLess(float lhs) const {
        const Literal* res;
        if(lhs < val)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opLess(int lhs) const {
        const Literal* res;
        if(lhs < val)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* greater(const Literal& rhs) const {
        return rhs.opGreater(val);
    }
    virtual const Literal* opGreater(float lhs) const {
        const Literal* res;
        if(lhs > val)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opGreater(int lhs) const {
        const Literal* res;
        if(lhs > val)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* eqequal(const Literal& rhs) const {
        return rhs.opEqequal(val);
    }
    virtual const Literal* opEqequal(float lhs) const {
        const Literal* res;
        if(fabs(lhs - val) < LIMIT)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opEqequal(int lhs) const {
        const Literal* res;
        if(fabs(lhs - val) < LIMIT)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* lessEqual(const Literal& rhs) const {
        return rhs.opLessEqual(val);
    }
    virtual const Literal* opLessEqual(float lhs) const {
        const Literal* res;
        if(float(lhs) <= float(val))
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opLessEqual(int lhs) const {
        const Literal* res;
        if(float(lhs) <= float(val))
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }

    virtual const Literal* greaterEqual(const Literal& rhs) const {
        return rhs.opGreaterEqual(val);
    }
    virtual const Literal* opGreaterEqual(float lhs) const {
        const Literal* res;
        if(float(lhs) >= float(val))
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opGreaterEqual(int lhs) const {
        const Literal* res;
        if(float(lhs) >= float(val))
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;

    }

    virtual const Literal* notEqual(const Literal& rhs) const {
        return rhs.opNotEqual(val);
    }
    virtual const Literal* opNotEqual(float lhs) const {
        const Literal* res;
        if(fabs(lhs - val) > LIMIT)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }
    virtual const Literal* opNotEqual(int lhs) const {
        const Literal* res;
        if(fabs(lhs - val) > LIMIT)
            res = new IntLiteral(1);
        else
            res = new IntLiteral(0);
        PoolOfNodes::getInstance().add(res);
        return res;
    }


    virtual const Literal* opposite() const {
      const Literal* node = new IntLiteral(-val);
      PoolOfNodes::getInstance().add(node);
      return node;
    // return this;
    }

    virtual bool isTrue() const {
        if(val) return true;
        else return false;
    }

    virtual const Literal* eval() const { return this; }
    virtual void print() const {
    std::cout << "INT: " << val << std::endl;
    }
private:
    int val;
};

#endif
