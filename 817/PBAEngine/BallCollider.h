#ifndef __BALLCOLLIDER_H__
#define __BALLCOLLIDER_H__

#include "Common.h"
#include "PBACollider.h"

class BallCollider : public PBACollider 
{
public: 
    BallCollider(PBARigidBody* obj = nullptr);

public: 
    float radius;

};

#endif