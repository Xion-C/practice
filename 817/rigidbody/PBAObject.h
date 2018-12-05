#ifndef __PBAOBJECT_H__
#define __PBAOBJECT_H__

#include "Common.h"
#include "PBAMath.h"
#include "ColliderMesh.h"

class PBAObject 
{
public: 
    PBAObject();
    ~PBAObject();
    virtual void Update();
    //virtual void Draw() const;
    virtual void Draw();

    void SetPosition(float x, float y, float z);
    void SetVelocity(float vx, float vy, float vz);
    void SetAngle(float yaw, float pitch, float roll);
    void SetAngularVelocity(float ux, float uy, float uz);
    void SetStatic(bool);

    const Vector3d& GetPosition() const {
        return position;
    }
    const Vector3d& GetVelocity() const {
        return velocity;
    }
    const Vector3d& GetAngularVelocity() const {
        return angularVelocity;
    }

    const Matrix3x3& GetRotMoiInv() const {
        return rotMoiInv;
    }

    float GetMass() const {
        return mass;
    } 


    //in world coordinates
    void AddImpulseAtPosition(const Vector3d&, const Vector3d&);

    //Matrix3x3 ComputeWorldToLocalMatrix();
private: 
    void RefreshState();
    void ComputerMomentOfInertia();
    void ComputeEulerIntegration();
/* member */
public: 
    ColliderMesh* colliderMesh;
protected: 
    float mass, massInv;
    Matrix3x3 moi, moiInv; //moment of inertia
    Matrix3x3 rotMoi, rotMoiInv; //moment of inertia after rotation

    Vector3d position; //position
    Quaternion quaternion; //quaternion to express oritation
    Matrix3x3 rotation; //rotation matrix

    Vector3d velocity; //velocity
    Vector3d angularVelocity; //angular velocity

    Vector3d momentum; //momentum P
    Vector3d angularMomentum; //angular momentum L

    Vector3d force; //force
    Vector3d torque; //torque

    bool staticFlag;

    friend class ColliderMesh;

};

#endif
