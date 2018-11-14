#ifndef __PBASCENE_H__
#define __PBASCENE_H__

#include <unordered_map>
#include <string>

#include "PBAObject.h"

class PBAScene 
{
public: 
    PBAScene();
    ~PBAScene();
    virtual void Init();
    virtual void Update();
    //virtual void Display() const;
    virtual void Display();
protected: 
    std::unordered_map<std::string, PBAObject*> objectlist;

};

#endif
