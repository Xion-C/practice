#include "PBACollider.h"
#include "PBARigidBody.h"
#include "PBAMath.h"

PBACollider::PBACollider(PBARigidBody* obj) : 
    object(obj),
    localPosition(Vector3d(0, 0, 0)),
    localRotation(Quaternion())
{
    localRotation.identity();
}

const Vector3d& PBACollider::GetLoacalPosition() const 
{
    return localPosition;
}