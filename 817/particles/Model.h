/*
   Model.h

   CPSC 8170 Physically Based Animation

 */

#ifndef __MODEL_H__
#define __MODEL_H__

#include "Vector.h"
#include "ParameterLoader.h"
#include <vector>


class Model {
//private:
public:
    Vector3d gravity;   // gravity
    Vector3d windVel;   // velocity of wind

    float d;            // coefficient of air resistance
    float cr;           // coefficient of restitution
    float cf;           // coefficient of friction

    float h;
    int dispinterval;

    float boxsize;

    // box Parameters
    Vector3d normals[6];
    Vector3d points[6];

    // Control
    bool haveAir;
    bool haveWind;
    bool haveLowGravity;

    float ballsize;
    Vector3d ballPos;

    Vector3d v0;
    Vector3d v1;
    Vector3d v2;
    Vector3d triNormal;
    int triNormMax;

public:
    Model();

    void toggleHaveAir() {
        haveAir = !haveAir;
        if(!haveAir) d = 0;
    }

    void toggleHaveWind() {
        haveWind = !haveWind;
        if(!haveAir) haveAir = true;
        if(!haveWind)
        {
            windVel = Vector3d(0, 0, 0);
        }
    }

    void toggleHaveLowGravity() {
        haveLowGravity = !haveLowGravity;
        if(haveLowGravity) gravity = 0.2 * gravity;
    }

    bool loadParameters(const ParameterLoader& params); // get simulation parameters
    void printParameters() const;

    void initSimulation();

    float ballSize() const {
        return ballsize;
    }
    float boxSize() const {
        return boxsize;
    }

    // accessor to retrieve model information for viewer
    int displayInterval(){
        return dispinterval;
    }
};

#endif
