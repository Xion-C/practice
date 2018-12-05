#ifndef __BOXCOLLIDER_H__
#define __BOXCOLLIDER_H__

#include "Common.h"
#include "PBACollider.h"

class BoxCollider : public PBACollider 
{
public: 
    BoxCollider(PBARigidBody* obj = nullptr);

    //point position in world space
    bool CheckPointInside(const Vector3d&);
    bool CheckPointInX(const Vector3d&);
    bool CheckPointInY(const Vector3d&);

public: 
    Vector3d size;

};

#endif