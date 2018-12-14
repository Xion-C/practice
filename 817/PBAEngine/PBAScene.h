#ifndef __PBASCENE_H__
#define __PBASCENE_H__

#include <unordered_map>
#include <string>

#include "PBARigidBody.h"
#include "PBAUI.h"

class PBAScene 
{
public: 
    PBAScene();
    ~PBAScene();
    virtual void Init();
    virtual void Clear();
    virtual void Update();
    //virtual void Display() const;
    virtual void Display();

    virtual PBARigidBody* AddObject(const std::string&, PBARigidBody*);
    virtual void DeleteObject(const std::string& name);
    virtual PBARigidBody* GetObject(const std::string&);

    virtual PBAUI* AddUI(const std::string&, PBAUI*);
    virtual PBAUI* GetUI(const std::string&);

public: 
    bool pause;
protected: 
    std::unordered_map<std::string, PBARigidBody*> objectlist;
    std::unordered_map<std::string, PBAUI*> uilist;

    float timeStep;
};

#endif
