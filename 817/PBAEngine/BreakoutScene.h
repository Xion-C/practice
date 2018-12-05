#ifndef __BREAKOUTSCENE_H__
#define __BREAKOUTSCENE_H__

#include "Common.h"
#include "PBAScene.h"
#include "BoxCollider.h"
#include "BallCollider.h"

#include <list>

class BreakoutScene : public PBAScene
{
public: 
    BreakoutScene();
    virtual void Init() override;
    virtual void Clear() override;
    virtual void Update() override;
    //virtual void Display() override;
private: 
    bool HandleBallHitStaticBox(BallCollider*, BoxCollider*);

private: 
    std::list<BoxCollider*> boxColliderList;
    std::list<BoxCollider*> brickColliderList;
    BallCollider* bounceBallCollider;
    BoxCollider* paddleCollider;
};

#endif