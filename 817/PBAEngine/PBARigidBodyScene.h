#ifndef __PBARIGIDBODYSCENE_H__
#define __PBARIGIDBODYSCENE_H__

#include "PBAScene.h"

class RigidBodyScene : public PBAScene
{
public: 
    RigidBodyScene();
    virtual void Init() override;
};

#endif