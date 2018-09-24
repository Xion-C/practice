/*
    By Xin Cheng
 */
#ifndef __PARAMTERLOADER_H__
#define __PARAMTERLOADER_H__

#include "Vector.h"

class ParameterLoader
{
public:
    float timeStep;
    int displayInterval;

    float mass;
    Vector3d initialVelocity;

    Vector3d gravity;
    Vector3d windVelocity;
    float airReisistance;
    float ballSize;
    float boxSize;
    float restitution;
    float friction;

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
