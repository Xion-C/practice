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
    std::list<Particle> particles;

    ParticleGenerator(Model *m) : model(m) {
    }

    bool LoadParameters(const ParameterLoader& params);

    void GenerateRectPaticles();
    void PrintParameters() const;
    void SimulateParticles();

    bool DetectBoxCollision(float timeStep,
                            float boxsize,
                            const Vector3d& posCur,
                            const Vector3d& posNew,
                            Vector3d& collidePos,
                            Vector3d& collideNormal,
                            float& f);


    void TimeStep();
    bool Clear();

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
};

#endif
