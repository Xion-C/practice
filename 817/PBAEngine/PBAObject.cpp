#include "PBAObject.h"

PBAObject::PBAObject() : 
    position(Vector3d(0, 0, 0)),
    orientation(Quaternion()),
    name(""),
    staticFlag(true),
    activatedFlag(true)
{

}

void PBAObject::SetPosition(float x, float y, float z) 
{
    position = Vector3d(x, y, z);
}
void PBAObject::SetPosition(const Vector3d& p) 
{
    position = p;
}
const Vector3d& PBAObject::GetPosition() const 
{
    return position;
}

void PBAObject::SetAngle(float yaw, float pitch, float roll) 
{
    orientation.set(yaw, pitch, roll);
}

void PBAObject::SetStatic(bool s)
{
    staticFlag = s;
}