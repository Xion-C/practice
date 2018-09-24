/*
   Model.h

   CPSC 8170 Physically Based Animation
   Donald H. House     8/26/2018

   Interface for Teapot-Bubble Simulation Model
 */

#ifndef __MODEL_H__
#define __MODEL_H__

#include "Vector.h"
#include "ParameterLoader.h"

class Model {
private:
    // Ball and box simulation parameters
    Vector3d initVel;
    float mass;
    float drag;
    float buoyancy;

    Vector3d gravity;   // gravity
    Vector3d windVel;   // velocity of wind

    float d;            // coefficient of air resistance
    float cr;           // coefficient of restitution
    float cf;           // coefficient of friction

    float h;
    int dispinterval;

    float ballsize;
    float boxsize;

    bool Rising;
    bool moving;
    bool resting;
    int restingSurface;

    // State of ball
    Vector3d ballPos;
    Vector3d ballVel;
    Vector3d a; // acceleration

    // box Parameters
    Vector3d normals[6];
    Vector3d points[6];

    // Control
    bool haveVel;
    bool haveAir;
    bool haveWind;
    bool haveLight;

public:
    Model();

    void toggleHaveVel() {
        haveVel = !haveVel;
    }

    void toggleHaveAir() {
        haveAir = !haveAir;
    }

    void toggleHaveWind() {
        haveWind = !haveWind;
        if(!haveAir) haveAir = true;
    }

    void toggleHaveLight() {
        haveLight = !haveLight;
    }

    bool loadParameters(const char *parmfilename); // get simulation parameters
    bool loadParameters(const ParameterLoader& params);

    void printParameters() const;

    void initSimulation();    // initialize bubble to initial position and velocity
    void timeStep();          // take one timestep
    void startBall();       // make the bubble active

    // accessors to retrieve bubble state
    Vector3d ballPosition() const {
        return ballPos;
    }
    Vector3d ballVelocity() const {
        return ballVel;
    }
    float ballSize() const {
        return ballsize;
    }
    float boxSize() const {
        return boxsize;
    }
    bool isRising(){
        return Rising;
    }
    bool isMoving() {
        return moving;
    }

    // accessor to retrieve model information for viewer
    int displayInterval(){
        return dispinterval;
    }

    void print() const;
};

#endif
