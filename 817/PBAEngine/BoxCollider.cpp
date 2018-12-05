#include "BoxCollider.h"
#include "PBARigidBody.h"

BoxCollider::BoxCollider(PBARigidBody* obj) : 
    PBACollider(obj)
{

}

bool BoxCollider::CheckPointInside(const Vector3d& point) 
{
    Vector3d center = object->GetPosition() + localPosition;
    //Quaternion allrotation = 
    Vector3d localPoint = point;
    if(
        center.x - size.x / 2 <= localPoint.x &&
        center.x + size.x / 2 >= localPoint.x &&
        center.y - size.y / 2 <= localPoint.y &&
        center.y + size.y / 2 >= localPoint.y &&
        center.z - size.z / 2 <= localPoint.z &&
        center.z + size.z / 2 >= localPoint.z
    )
    {
        return true;
    }
    else {
        return false;
    }
}

bool BoxCollider::CheckPointInX(const Vector3d& point) 
{
    Vector3d center = object->GetPosition() + localPosition;
    //Quaternion allrotation = 
    Vector3d localPoint = point;
    if(
        center.x - size.x / 2 <= localPoint.x &&
        center.x + size.x / 2 >= localPoint.x
    )
    {
        return true;
    }
    else {
        return false;
    }
}

bool BoxCollider::CheckPointInY(const Vector3d& point) 
{
    Vector3d center = object->GetPosition() + localPosition;
    //Quaternion allrotation = 
    Vector3d localPoint = point;
    if(
        center.y - size.y / 2 <= localPoint.y &&
        center.y + size.y / 2 >= localPoint.y
    )
    {
        return true;
    }
    else {
        return false;
    }
}

