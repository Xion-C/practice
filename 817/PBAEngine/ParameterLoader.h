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

    float mass;

    float flagWidth;
    float flagHeight;

    int meshNumX;
    int meshNumY;

    Vector3d startPostion;

    float springy_k;
    float damper_d;

    float dragCoefficient;
    float liftCoefficient;

private:
    bool success;

public:
    static ParameterLoader& GetInstance();
    bool LoadParameters(const char* path);
    const bool IsSuccess() const {
        return success;
    }
private:
    ParameterLoader() {}
    ParameterLoader(const ParameterLoader &) = delete;
    ParameterLoader& operator=(const ParameterLoader&) = delete;
};

#endif
