#include <cmath>
#include <iostream>

#include "ParameterLoader.h"
#include "SpringyMeshFlag.h"
#include "Vector.h"

#define PRECISION 0.000001

void SpringyParticle::PrintInfo()
{
    std::cout << "- SpringyParticle:\n";
    std::cout << "  - pos: " << pos << "\n";
    std::cout << "  - vel: " << vel << "\n";
    std::cout << "  - mass: " << mass << "\n";
    std::cout << "  - force: " << force << "\n";
}

void SpringyFlagStrut::AddFaceIndex(int i)
{
    if(fi[0] < 0 || fi[0] == i) fi[0] = i;
    else fi[1] = 0;
}

void SpringyFlagFace::AddStrutIndex(int i)
{
    if(si[0] < 0 || si[0] == i) si[0] = i;
    else if(si[1] < 0 || si[1] == i) si[1] = i;
    else si[2] = i;
}

void SpringyMeshFlag::Init() {
    LoadParameters();

    GenerateSpringyMesh();
}

void SpringyMeshFlag::LoadParameters() {
    ParameterLoader& params = ParameterLoader::GetInstance();
    h = params.timeStep;
    mass = params.mass;
    numx = params.meshNumX;
    numy = params.meshNumY;
    lx = params.flagWidth / numx;
    ly = params.flagHeight / numy;
    startPos = params.startPostion;

    k = params.springy_k;
    d = params.damper_d;
}

void SpringyMeshFlag::PrintInfo() {
    std::cout << "vertexArraySize: " << vertexArraySize << "\n";
    std::cout << "indexArraySize: " << indexArraySize << "\n";
    std::cout << "vertex array:\n";
    for (int i = 0; i < vertexArraySize / 3; i++) {
        std::cout << i << " - " << vertexArrayPtr[i * 3] << " "
                  << vertexArrayPtr[i * 3 + 1] << " "
                  << vertexArrayPtr[i * 3 + 2] << "\n";
    }
    std::cout << "index array:\n";
    for (int i = 0; i < indexArraySize / 3; i++) {
        std::cout << i << "- " << indexArrayPtr[i * 3] << " "
                  << indexArrayPtr[i * 3 + 1] << " " << indexArrayPtr[i * 3 + 2]
                  << "\n";
    }
}

void SpringyMeshFlag::GenerateSpringyMesh() {
    const float lxy = sqrtf(lx * lx + ly * ly);

    vertexArraySize = numx * numy * 3;
    verticesPos = Vertices_t(vertexArraySize);  // x y z
    normals = Normals_t(vertexArraySize);
    vertnormals = VertexNormals_t(numx * numy);
    indexArraySize = 2 * (numx - 1) * (numy - 1) * 3;
    faceIndices = FaceIndices_t(indexArraySize);  // v0 v1 v2 triangle
    normalPtr = normals.data();
    vertexArrayPtr = verticesPos.data();
    indexArrayPtr = faceIndices.data();

    particles = SpringyFlagParticles(numx * numy);
    struts = SpringyFlagStruts(3 * numx * numy + numx + numy);
    faces = SpringyFlagFaces(2 * (numx - 1) * (numy - 1));


    const Vector3d zerovec = Vector3d(0, 0, 0);

    for (int i = 0; i < numy; i++) {
        for (int j = 0; j < numx; j++) {
            Vector3d pos = Vector3d(startPos.x + j * lx, startPos.y + i * ly, startPos.z);
            //SpringyParticle particle(pos, zerovec, mass, zerovec);
            particles[i * numx + j] = SpringyParticle(pos, zerovec, mass, zerovec);
            int vpIndex = (i * numx + j) * 3;
            verticesPos[vpIndex] = pos.x;
            verticesPos[vpIndex + 1] = pos.y;
            verticesPos[vpIndex + 2] = pos.z;
        }
    }

    // 0 ------- 3
    // | \   f2  |
    // |   \     |
    // |     \   |
    // | f1    \ |
    // 1 ------- 2
    int strutsCount = 0;
    int facesCount = 0;
    for (int i = 0; i < numy - 1; i++) {
        for (int j = 0; j < numx - 1; j++) {
            int fiIndex = 2 * (i * (numx - 1) + j) * 3;
            // triangle 1 - v0 v1 v2
            faceIndices[fiIndex] = i * numx + j;
            faceIndices[fiIndex + 1] = (i + 1) * numx + j;
            faceIndices[fiIndex + 2] = (i + 1) * numx + j + 1;
            // triangle 2 - v0 v2 v3
            faceIndices[fiIndex + 3] = i * numx + j;
            faceIndices[fiIndex + 4] = (i + 1) * numx + j + 1;
            faceIndices[fiIndex + 5] = i * numx + j + 1;

            // struts and faces
            // SpringyFlagFace face1;
            // SpringyFlagFace face2;
            faces[facesCount].vi[0] =  faceIndices[fiIndex];
            faces[facesCount].vi[1] =  faceIndices[fiIndex + 1];
            faces[facesCount].vi[2] =  faceIndices[fiIndex + 2];

            faces[facesCount + 1].vi[0] =  faceIndices[fiIndex + 3];
            faces[facesCount + 1].vi[1] =  faceIndices[fiIndex + 4];
            faces[facesCount + 1].vi[2] =  faceIndices[fiIndex + 5];


            if (0 == j) {
                SpringyFlagStrut strut01(k, d, lx);
                strut01.vi[0] = i * numx + j;
                strut01.vi[1] = (i + 1) * numx + j;
                strut01.AddFaceIndex(facesCount);
                struts[strutsCount] = strut01;
                strutsCount++;
            }
            if (0 == i) {
                SpringyFlagStrut strut03(k, d, lx);
                strut03.vi[0] = i * numx + j;
                strut03.vi[1] = i * numx + j + 1;
                strut03.AddFaceIndex(facesCount + 1);
                struts[strutsCount] = strut03;
                strutsCount++;
            }

            SpringyFlagStrut strut02(0.01 * k, d, lx);
            strut02.vi[0] = i * numx + j;
            strut02.vi[1] = (i + 1) * numx + j + 1;
            strut02.AddFaceIndex(facesCount);
            strut02.AddFaceIndex(facesCount + 1);
            struts[strutsCount] = strut02;
            strutsCount++;

            SpringyFlagStrut strut12(k, d, lx);
            strut12.vi[0] = (i + 1) * numx + j;
            strut12.vi[1] = (i + 1) * numx + j + 1;
            strut12.AddFaceIndex(facesCount);
            struts[strutsCount] = strut12;
            strutsCount++;

            SpringyFlagStrut strut23(k, d, lx);
            strut23.vi[0] = (i + 1) * numx + j + 1;
            strut23.vi[1] = i * numx + j + 1;
            strut23.AddFaceIndex(facesCount + 1);
            struts[strutsCount] = strut23;
            strutsCount++;            

            facesCount += 2;

            //
            // fi need to be assigned
            //
        }
    }
    ComputeNormals();
}

void SpringyMeshFlag::ComputeNormals()
{
    // clear to 0
    auto it = normals.begin();
    while(it < normals.end())
    {
        *(it) = 0.0f;
        it++;
    }

    auto itvn = vertnormals.begin();
    while(itvn < vertnormals.end())
    {
        *(itvn) = 0;
        itvn++;
    }

    const int facesNum = indexArraySize / 3;
    for(int fi = 0; fi < facesNum; fi++)
    {
        int vi[3];
        float x[3], y[3], z[3];
        Vector3d vert[3];
        for(int ni = 0; ni < 3; ni++)
        {
            vi[ni] = faceIndices[3 * fi + ni];
            x[ni] = verticesPos[3 * vi[ni]];
            y[ni] = verticesPos[3 * vi[ni] + 1];
            z[ni] = verticesPos[3 * vi[ni] + 2];
            vert[ni] = Vector3d(x[ni], y[ni], z[ni]);
        }
        Vector3d v01 = vert[1] - vert[0];
        Vector3d v12 = vert[2] - vert[1];
        Vector3d normal = (v01.cross(v12)).normalize();

        faces[fi].normal = normal;

        for(int ni = 0; ni < 3; ni++)
        {
            normals[3 * vi[ni]] += normal.x; //nx
            normals[3 * vi[ni] + 1] += normal.y;
            normals[3 * vi[ni] + 2] += normal.z;
            vertnormals[vi[ni]]++;
        }
    }

    const int vertNum = vertexArraySize / 3;
    for(int iv = 0; iv < vertNum; iv++)
    {
        for(int ni = 0; ni < 3; ni++)
        {
            normals[3 * iv + ni] = normals[3 * iv + ni] / (float)vertnormals[iv];
        }
    }
}

void SpringyMeshFlag::ProcessWindForce()
{
    ParameterLoader& params = ParameterLoader::GetInstance();
    const float cdrag = params.dragCoefficient;
    const float clift = params.liftCoefficient;
    const Vector3d windVel = params.windVelocity;

    const int facesNum = faces.size();
    int vi[3];
    Vector3d vp[3];
    Vector3d fd; //drag
    Vector3d fl; //lift
    Vector3d normal;
    for(int fi = 0; fi < facesNum; fi++)
    {
        Vector3d vaver;
        for(int ni = 0; ni < 3; ni++)
        {
            vi[ni] = faces[fi].vi[ni];
            vp[ni] = particles[vi[ni]].pos;
            vaver = vaver + particles[vi[ni]].vel;
        }
        vaver = vaver / 3.0;
        Vector3d vr = vaver - windVel;
        normal = faces[fi].normal;

        float a = (vp[1] - vp[0]).norm();
        float b = (vp[2] - vp[0]).norm();
        float c = (vp[2] - vp[1]).norm();
        if(PRECISION > a || PRECISION > b || PRECISION > c)
        {
            continue;
        }
        float p = (a + b + c) * 0.5;
        float area = sqrtf(p * (p - a) * (p - b) * (p - c));
        if(PRECISION > area) continue;

        float nn_dot_vr = normal * vr;
        if(nn_dot_vr < 0) {
            nn_dot_vr = -nn_dot_vr;
        }
        Vector3d nn_cross_vr = normal.cross(vr);

        float nn_cross_vr_mag = nn_cross_vr.norm();
        if(PRECISION > nn_cross_vr_mag) {
            fl = Vector3d(0, 0, 0);
        }
        else {
            fl = -clift * area * nn_dot_vr * (vr.cross(nn_cross_vr / nn_cross_vr_mag));
        }
        fd = -cdrag * area * nn_dot_vr * vr;

        for(int ni = 0; ni < 3; ni++)
        {
            particles[vi[ni]].force = particles[vi[ni]].force + (fd + fl) * (1.0 / 3.0);
        }

    }

}

void SpringyMeshFlag::ProcessEnvironmentalForce()
{
    Vector3d gravity = ParameterLoader::GetInstance().gravity;

    for(SpringyParticle& particle : particles)
    {
        particle.force = particle.mass * gravity;
    }

    ProcessWindForce();
}

void SpringyMeshFlag::ProcessInteractionForce()
{
    //int strutsNum = struts.size();
    for(SpringyFlagStrut& strut : struts)
    {
        const int vi0 = strut.vi[0];
        const int vi1 = strut.vi[1];
        const float l0 = strut.l0;
        const float d = strut.d;
        const float k = strut.k;

        Vector3d x0 = particles[vi0].pos;
        Vector3d x1 = particles[vi1].pos;
        Vector3d x01 = x1 - x0;
        Vector3d x01n = x01.normalize();
        float l01 = x01.norm();

        Vector3d v0 = particles[vi0].vel;
        Vector3d v1 = particles[vi1].vel;
        Vector3d v01 = v1 - v0;

        Vector3d fd = d * (v01 * x01n) * x01n;
        Vector3d fs = k * (l01 - l0) * x01n;
        Vector3d f01 = fd + fs;

        particles[vi0].force = particles[vi0].force + f01;
        particles[vi1].force = particles[vi1].force - f01;
    }
}

void SpringyMeshFlag::ProcessEulerIntergration()
{
    for(SpringyParticle& particle : particles)
    {
        particle.pos = particle.pos + particle.vel * h;
        particle.vel = particle.vel + particle.force * (1.0 / particle.mass) * h;
        //particle.PrintInfo();
    }
}

void SpringyMeshFlag::ProcessRK4Intergration()
{
    SpringyFlagParticles k1 = particles;
    for(SpringyParticle& particle : particles)
    {
        particle.pos = particle.pos + particle.vel * 0.5 * h;
        particle.vel = particle.vel + particle.force * (1.0 / particle.mass) * 0.5 * h;
    }
    ProcessEnvironmentalForce();
    ProcessInteractionForce();
    FixFlagEdge();

    SpringyFlagParticles k2 = particles;
    for(SpringyParticle& particle : particles)
    {
        particle.pos = particle.pos + particle.vel * 0.5 * h;
        particle.vel = particle.vel + particle.force * (1.0 / particle.mass) * 0.5 * h;
    }
    ProcessEnvironmentalForce();
    ProcessInteractionForce();
    FixFlagEdge();

    SpringyFlagParticles k3 = particles;
    for(SpringyParticle& particle : particles)
    {
        particle.pos = particle.pos + particle.vel * h;
        particle.vel = particle.vel + particle.force * (1.0 / particle.mass) * h;
    }
    ProcessEnvironmentalForce();
    ProcessInteractionForce();
    FixFlagEdge();

    SpringyFlagParticles k4 = particles;

    for(int i = 0; i < particles.size(); i++)
    {
        particles[i].pos = k1[i].pos + (h / 6.0) * (k1[i].vel + 2 * k2[i].vel + 2 * k3[i].vel + k4[i].vel);
        particles[i].vel = k1[i].vel + (h / 6.0) * (1.0 / particles[i].mass) * (k1[i].force + 2 * k2[i].force + 2 * k3[i].force + k4[i].force);
    }

}


void SpringyMeshFlag::FixFlagEdge()
{
    std::vector<SpringyParticle>::iterator it = particles.begin();
    while(it < particles.end())
    {
        it->force = Vector3d(0, 0 ,0);
        it += numx;
    }
}

void SpringyMeshFlag::Simulate()
{
    ProcessEnvironmentalForce();
    ProcessInteractionForce();

    FixFlagEdge();
    //ProcessEulerIntergration();
    ProcessRK4Intergration();

    //particles[0].PrintInfo();
    //std::cout << "h: " << h << "\n";
}

void SpringyMeshFlag::UpdateVertexArray()
{
    int i = 0;
    for(SpringyParticle& particle : particles)
    {
        verticesPos[i] = particle.pos.x;
        verticesPos[i + 1] = particle.pos.y;
        verticesPos[i + 2] = particle.pos.z;
        i += 3;
    }
}

void SpringyMeshFlag::TimeStep()
{
    Simulate();
    UpdateVertexArray();
    ComputeNormals();
}