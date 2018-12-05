#include "ColliderMesh.h"
#include "PBAObject.h"
#include "PBAMath.h"

ColliderMesh::ColliderMesh(PBAObject* obj) : 
    Mesh(),
    object(obj),
    initvertices(),
    vertices(),
    indicies(),
    relativePosition(Vector3d(0, 0, 0)),
    relativeRotation(Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1))
{

}

void ColliderMesh::SetCube()
{
    initvertices = std::vector<Vector3d>(8);
    initvertices[0] = Vector3d(0.5, 0.5, 0.5);
    initvertices[1] = Vector3d(0.5, 0.5, -0.5);
    initvertices[2] = Vector3d(-0.5, 0.5, -0.5);
    initvertices[3] = Vector3d(-0.5, 0.5, 0.5);
    initvertices[4] = Vector3d(0.5, -0.5, 0.5);
    initvertices[5] = Vector3d(0.5, -0.5, -0.5);
    initvertices[6] = Vector3d(-0.5, -0.5, -0.5);
    initvertices[7] = Vector3d(-0.5, -0.5, 0.5);
    vertices = initvertices;

}

void ColliderMesh::Scale(float x, float y, float z)
{
    //should also translate // save this step
    if(relativePosition.norm() > 0.01) {
        IFDEBUG(
            std::cout << "should translate in scale" << std::endl;
        );
    }
    Matrix3x3 scale = Matrix3x3(
        x, 0, 0,
        0, y, 0,
        0, 0, z
    );
    for(unsigned int i = 0; i < initvertices.size(); i++) {
        initvertices[i] = initvertices[i] * scale;
    }
}

void ColliderMesh::Update() {
    // for(auto& vert : vertices) {
    //     vert = initvertices * (object->rotation) + (object->position);
    // }
    for(unsigned int i = 0; i < initvertices.size(); i++) {
        vertices[i] = initvertices[i] * (object->rotation) + (object->position);
    }

    IFDEBUG(
    int i = 0;
        for(const auto& vert : vertices) {
            std::cout << i++ << " - vert: " << vert << std::endl;
        }
    );
}
