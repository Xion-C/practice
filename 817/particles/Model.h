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

public:
    Model();

    void toggleHaveAir() {
        haveAir = !haveAir;
    }

    void toggleHaveWind() {
        haveWind = !haveWind;
        if(!haveAir) haveAir = true;
    }

    void toggleHaveLowGravity() {
        haveLowGravity = !haveLowGravity;
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

    void print() const;
};

#endif
