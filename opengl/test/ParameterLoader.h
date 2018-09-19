/*
    By Xin Cheng
*/
#ifndef __PARAMTERLOADER_H__
#define __PARAMTERLOADER_H__

#include "Vector.h"

struct ParameterLoader
{
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

    ParameterLoader() {}
    ParameterLoader(const char* path);

    bool LoadParameters(const char* path);

};

#endif
