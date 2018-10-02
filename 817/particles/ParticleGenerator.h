/*
    CPSC 8170 Physically Based Animation - Assignment 2

    By Xin Cheng
 */

#ifndef __PARTICLEGENERATOR_H__
#define __PARTICLEGENERATOR_H__

//#include <vector>
#include <list>
#include "Vector.h"
#include "Model.h"
#include "ParameterLoader.h"
#include "Particle.h"

class ParticleGenerator
{
public:
    //std::list<Particle> particles;

    ParticleGenerator(Model *m) : model(m), continuous(false) {
    }

    bool LoadParameters(const ParameterLoader& params);

    const float GetParticleSize() const {return particleSize;}
    const std::list<Particle>& GetParticles() const { return particles; }

    void GenerateRectPaticles(int number);
    void PrintParameters() const;
    void SimulateParticles();

    void Init() {
        continuous = true;
    }
    void Stop() {
        continuous = false;
    }

    bool DetectBoxCollision(const float timeStep,
                            const Vector3d& posCur,
                            const Vector3d& posNew,
                            Vector3d& collidePos,
                            Vector3d& collideNormal,
                            float& f);

    bool DetectSphereCollision(const float timeStep,
                               const Vector3d& posCur,
                               const Vector3d& posNew,
                               Vector3d& collidePos,
                               Vector3d& collideNormal,
                               float& f);
    bool DetectTriangleCollision(const float timeStep,
                                 const Vector3d& posCur,
                                 const Vector3d& posNew,
                                 Vector3d& collidePos,
                                 Vector3d& collideNormal,
                                 float& f);

    void Translate(const Vector3d& transVel);
    void TimeStep();

private:
    Model* model;
    float h; // time step
    int speed; // genetrate speed
    Vector3d pos;
    Vector3d vel;
    float mass;
    float lifespan;
    int height;
    int width;
    float velStd;

    float particleSize;

    bool continuous;

    std::list<Particle> particles;
};

#endif
