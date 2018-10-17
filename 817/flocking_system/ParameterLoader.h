/*
    By Xin Cheng
 */
#ifndef __PARAMTERLOADER_H__
#define __PARAMTERLOADER_H__

#include <vector>
#include "Vector.h"

class ParameterLoader
{
public:
    float timeStep;
    int displayInterval;

    Vector3d gravity;
    Vector3d windVelocity;
    float airReisistance;

    float boxSize;
    float restitution;
    float friction;

    int generateSpeed;
    Vector3d position;
    Vector3d velocity;
    float mass;
    float lifespan;
    int height;
    int width;
    float velocityStd;

    float particleSize;

    float ballSize;
    Vector3d ballPosition;

    Vector3d vertex0;
    Vector3d vertex1;
    Vector3d vertex2;

    int particleNum;
    float generatorSize;

    //FlockingSystem
    float ka;
    float kv;
    float kc;
    float amax;

    float r1;
    float r2;
    float t1;
    float t2;

    float leadBoidSpeed;
    //route
    int routePointsNum;
    std::vector<Vector3d> routePoints;

    ParameterLoader() {
    }
    ParameterLoader(const char* path);

    bool LoadParameters(const char* path);
    const bool IsSuccess() const {
        return success;
    }

private:
    bool success;

};

#endif
