#ifndef __PBARIGIDBODYSCENE_H__
#define __PBARIGIDBODYSCENE_H__

#include "PBAScene.h"

class RigidBodyScene : public PBAScene
{
public: 
    RigidBodyScene();
    virtual void Init() override;
    virtual void Update() override;
    //virtual void Display() override;

    virtual void HandleStaticCollision(PBAObject* objsta, PBAObject* objdyn);

/* inherited member */
    //objectlist
    //timeStep
};

#endif