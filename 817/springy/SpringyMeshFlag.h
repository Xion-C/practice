#ifndef __SPRINGYMESHFLAG_H__
#define __SPRINGYMESHFLAG_H__

#include <vector>

#include "Vector.h"
#include "Particle.h"

//typedef Particle SpringyParticle;
struct SpringyParticle 
{
    Vector3d pos;  // position
    Vector3d vel;  // velocity
    // Vector3d oldpos;
    // Vector3d oldvel;

    float mass;
    Vector3d force;

    SpringyParticle() {}
    SpringyParticle(const Vector3d& p, const Vector3d& v, float m,
                    const Vector3d& f)
        : pos(p), vel(v), mass(m), force(f) {}
    void PrintInfo();
};

struct SpringyFlagStrut {
    float k;
    float d;
    float l0;
    int vi[2];  // vertex indices
    int fi[2];  // face indices
    SpringyFlagStrut(){}
    SpringyFlagStrut(float kp, float dp, float l0p)
    : k(kp), d(dp), l0(l0p) 
    {
        vi[0] = vi[1] = -1;
        fi[0] = fi[1] = -1;
    }
    inline void AddFaceIndex(int i);
};


struct SpringyFlagFace 
{
    int si[3];       // strut indices
    float angle[3];  // vectex angle

    int vi[3];       // vertex indices
    Vector3d normal;


    SpringyFlagFace()
    {
        si[0] = si[1] = si[2] = -1;
    }
    inline void AddStrutIndex(int i);
};

typedef std::vector<SpringyParticle> SpringyFlagParticles;
typedef std::vector<SpringyFlagStrut> SpringyFlagStruts;
typedef std::vector<SpringyFlagFace> SpringyFlagFaces;

typedef std::vector<float> Normals_t;
typedef std::vector<unsigned int> VertexNormals_t;
typedef std::vector<float> Vertices_t;
typedef std::vector<unsigned int> FaceIndices_t;


class SpringyMeshFlag {
// members
public:
    const float* normalPtr;
    const float* vertexArrayPtr;
    const unsigned int* indexArrayPtr;
    int vertexArraySize;
    int indexArraySize;

private:
    SpringyFlagParticles particles;
    SpringyFlagStruts struts;
    SpringyFlagFaces faces;

    Vertices_t verticesPos;
    FaceIndices_t faceIndices;
    Normals_t normals;
    VertexNormals_t vertnormals;


    float h; //time step
    float k; //spring
    float d; //damper
    float lx; //grid length in x direction
    float ly; 
    int numx; //grid num in x
    int numy;
    float mass; //mass of each particle
    Vector3d startPos;


// methods
public: 
    void Init();
    void LoadParameters();
    void PrintInfo();
    void TimeStep();
private: 
    void GenerateSpringyMesh();
    void ComputeNormals();
    void ProcessWindForce();
    void ProcessEnvironmentalForce();
    void ProcessInteractionForce();
    void ProcessEulerIntergration();
    void ProcessRK4Intergration();
    void FixFlagEdge();
    void UpdateVertexArray();
    void Simulate();

};

#endif