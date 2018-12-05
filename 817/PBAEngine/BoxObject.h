#ifndef __BOXOBJECT_H__
#define __BOXOBJECT_H__

#include "Common.h"
#include "PBARigidBody.h"

#include <vector>

class BoxObject : public PBARigidBody 
{
public: 
    BoxObject();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Draw() override;

    void SetSize(float, float, float);
    //const Vector3d& GetSize() const;

protected: 
    void ComputerMomentOfInertia();

public: 
    Vector3d size; //length, height, width - x y z 

};

#endif