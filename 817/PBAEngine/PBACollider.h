#ifndef __PBACOLLIDER_H__
#define __PBACOLLIDER_H__

#include "Common.h"
#include "PBAMath.h"

class PBARigidBody;

class PBACollider 
{
public: 
    PBACollider(PBARigidBody* obj = nullptr);

    const Vector3d& GetLoacalPosition() const;

public: 
    PBARigidBody* object;

protected: 
    Vector3d localPosition;
    Quaternion localRotation;

};

#endif