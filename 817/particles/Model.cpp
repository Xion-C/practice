/*
   Model.h

   CPSC 8170 Physically Based Animation Homework1
   Adapted form Dr. Donald H. House

   Implementation for Bouncing-Ball Viewer
 */

#include "Model.h"

#include <cstdlib>
#include <cstdio>
#include <cmath>

#define PRECISION 0.01
#define MAXCOLLIDES 5

using namespace std;

//===========================================================================
// Model
//===========================================================================

Model::Model(){
    initSimulation();
    haveAir = true;
    haveWind = true;
    haveLowGravity = true;
}

bool Model::loadParameters(const ParameterLoader& params)
{
    if(!params.IsSuccess()) return false;
    h = params.timeStep;
    dispinterval = params.displayInterval;
    gravity = params.gravity;
    windVel = params.windVelocity;
    d = params.airReisistance;
    cr = params.restitution;
    cf = params.friction;
    boxsize = params.boxSize;

    ballsize = params.ballSize;
    ballPos = params.ballPosition;

    // set box
    normals[0] = Vector3d(1.0, 0.0, 0.0);
    normals[1] = Vector3d(0.0, 1.0, 0.0);
    normals[2] = Vector3d(0.0, 0.0, 1.0);
    normals[3] = Vector3d(-1.0, 0.0, 0.0);
    normals[4] = Vector3d(0.0, -1.0, 0.0);
    normals[5] = Vector3d(0.0, 0.0, -1.0);
    points[0] = Vector3d(-boxsize/2, 0.0, 0.0);
    points[1] = Vector3d(0.0, -boxsize/2, 0.0);
    points[2] = Vector3d(0.0, 0.0, -boxsize/2);
    points[3] = Vector3d(boxsize/2, 0.0, 0.0);
    points[4] = Vector3d(0.0, boxsize/2, 0.0);
    points[5] = Vector3d(0.0, 0.0, boxsize/2);

    printParameters();

    return true;
}

void Model::printParameters() const
{
    std::cout << "/----- Model Parameters: -----/" << '\n';
    std::cout << "time step:        " << h << '\n';
    std::cout << "display interval: " << dispinterval << '\n';
    std::cout << "gravity:          " << gravity << '\n';
    std::cout << "wind vel:         " << windVel << '\n';
    std::cout << "d:                " << d << '\n';
    std::cout << "cr:               " << cr << '\n';
    std::cout << "cf:               " << cf << '\n';
    std::cout << "box size:         " << boxsize << '\n';
    std::cout << "ball size:        " << ballsize << '\n';
    std::cout << "/----------------------------/" << '\n';
}

void Model::initSimulation() {
    if(!haveAir) d = 0;
    if(!haveWind) windVel = 0;
    if(!haveLowGravity) gravity = gravity * 0.2;
}
