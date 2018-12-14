#ifndef __PBARIGIDBODY_H__
#define __PBARIGIDBODY_H__

#include "Common.h"
#include "PBAMath.h"
//#include "ColliderMesh.h"
#include "PBACollider.h"
#include "Mesh.h"
#include "PBARenderer.h"
#include "PBAObject.h"

#include <string>

class PBARigidBody : public PBAObject
{
public: 
    PBARigidBody();
    virtual ~PBARigidBody();
    virtual void Init();
    virtual void Update() override;
    //virtual void Draw() const;
    virtual void Render() override;

    virtual void SetVelocity(float vx, float vy, float vz);
    virtual void SetVelocity(const Vector3d&);
    virtual void SetAngle(float yaw, float pitch, float roll);
    virtual void SetAngularVelocity(float ux, float uy, float uz);
    void SetGravity(bool);

    const Vector3d& GetVelocity() const {
        return velocity;
    }
    const Vector3d& GetAngularVelocity() const {
        return angularVelocity;
    }

    const Matrix3x3& GetRotMoiInv() const {
        return rotMoiInv;
    }

    void SetMass(float m) {
        mass = m;
    }
    float GetMass() const {
        return mass;
    } 

    void BindCollider(PBACollider*);

    /* this part need to be moved to renderer */
    void SetDiffuseColor(float, float, float, float a = 1.0);
    void SetSpecularColor(float, float, float, float a = 1.0);
    void SetShininess(float);

    //in world coordinates
    void AddImpulseAtPosition(const Vector3d& imp, const Vector3d& impos);

    //Matrix3x3 ComputeWorldToLocalMatrix();
protected: 
    void RefreshState();
    void ComputeEulerIntegration();

/* member */
public: 
    //ColliderMesh* colliderMesh;
    ObjectMesh* mesh;
    PBARenderer* renderer;
    PBACollider* collider;

protected: 
    float mass, massInv;
    Matrix3x3 moi, moiInv; //moment of inertia
    Matrix3x3 rotMoi, rotMoiInv; //moment of inertia after rotation

    //Vector3d position; //position
    //Quaternion orientation; //orientation to express oritation
    Matrix3x3 rotation; //rotation matrix

    Vector3d velocity; //velocity
    Vector3d angularVelocity; //angular velocity

    Vector3d momentum; //momentum P
    Vector3d angularMomentum; //angular momentum L

    Vector3d force; //force
    Vector3d torque; //torque

    bool gravityFlag;

    /* this part need to be moved to renderer */
    std::vector<float> diffuseColor;
    std::vector<float> specularColor;
    float shininess;

};

#endif
