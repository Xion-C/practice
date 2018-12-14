#ifndef __PBAOBJECT_H__
#define __PBAOBJECT_H__

#include "Common.h"
#include "PBAMath.h"

#include <string>

class PBAObject 
{
public: 
    PBAObject();
    virtual ~PBAObject() {}

    virtual void Update() = 0;
    virtual void Render() = 0;

    virtual void SetPosition(float, float, float);
    virtual void SetPosition(const Vector3d&);
    const Vector3d& GetPosition() const;

    virtual void SetAngle(float yaw, float pitch, float roll);

    void SetStatic(bool);

public: 
    Vector3d position;
    Quaternion orientation;
    std::string name;

    bool staticFlag;
    bool activatedFlag;
};

#endif