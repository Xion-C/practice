#ifndef __MESH_H__
#define __MESH_H__

#include "Common.h"

#include <vector>

struct Mesh
{
    std::vector<Vector3d> vertices;
    std::vector<Vector2d> uvs;
    std::vector<int> indices;
};

struct ObjectMesh : public Mesh
{

};


#endif