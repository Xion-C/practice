#ifndef __COLLIDERMESH_H__
#define __COLLIDERMESH_H__

#include "Common.h"
#include "PBAMath.h"
#include "Mesh.h"

#include <vector>

class PBAObject;

struct ColliderMesh : public Mesh 
{
public: 
    ColliderMesh(PBAObject* obj = nullptr);

    virtual void Update();

    void SetCube();
    void Scale(float x, float y, float z);
public: 
    PBAObject* object;

    std::vector<Vector3d> initvertices;
    std::vector<Vector3d> vertices;
    std::vector<int> indicies;

    Vector3d relativePosition;
    Matrix3x3 relativeRotation;
};

#endif