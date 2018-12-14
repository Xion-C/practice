#ifndef __BALLOBJECT_H__
#define __BALLOBJECT_H__

#include "Common.h"
#include "PBARigidBody.h"

class BallObject : public PBARigidBody 
{
public: 
    BallObject();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;

    void SetRidus(float);

public: 
    float radius;
};

#endif