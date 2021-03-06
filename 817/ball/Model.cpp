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

#define PRECISION 0.05
#define MAXCOLLIDES 5

using namespace std;

//===========================================================================
// Model
//===========================================================================

Model::Model(){
    initSimulation();
    haveVel = true;
    haveAir = true;
    haveWind = true;
    haveLight = true;
}

// get simulation parameters from parameter file
bool Model::loadParameters(const char *paramfilename){
    FILE *paramfile;

    paramfile = fopen(paramfilename, "r");
    if(paramfile == NULL) {
        fprintf(stderr, "Unable to open parameter file: %s\n", paramfilename);
        return false;
    }

    // int nparams = fscanf(paramfile, "%f, %f, %f, %f, %f, %d", &speed, &mass, &drag, &buoyancy, &h, &dispinterval);
    char temp[64];
    float vel[3];

    int nparams = fscanf(paramfile, "%f,", &h);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%d,", &dispinterval);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &mass);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "( %lf, %lf, %lf ),",
                      &(originalVel[0]), &(originalVel[1]), &(originalVel[2]));
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "( %lf, %lf, %lf ),",
                      &(gravity[0]), &(gravity[1]), &(gravity[2]));
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "( %lf, %lf, %lf ),",
                      &(windVel[0]), &(windVel[1]), &(windVel[2]));
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &d);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &cr);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &cf);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &ballsize);
    fscanf(paramfile, "%s\n", temp);

    nparams += fscanf(paramfile, "%f,", &boxsize);
    fscanf(paramfile, "%s\n", temp);

    if(!nparams || nparams != 17) {
        fprintf(stderr,
                "Parameter file %s invalid format.\n",
                paramfilename);
        fclose(paramfile);
        return false;
    }

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

    fclose(paramfile);
    return true;
}

void Model::printParameters() const
{
    std::cout << "/----- Parameters: -----/" << '\n';
    std::cout << "time step:        " << h << '\n';
    std::cout << "display interval: " << dispinterval << '\n';
    std::cout << "mass:             " << mass << '\n';
    std::cout << "ori vel:          " << originalVel << '\n';
    std::cout << "gravity:          " << gravity << '\n';
    std::cout << "wind vel:         " << windVel << '\n';
    std::cout << "d:                " << d << '\n';
    std::cout << "cr:               " << cr << '\n';
    std::cout << "cf:               " << cf << '\n';
    std::cout << "ball size:        " << ballsize << '\n';
    std::cout << "box size:         " << boxsize << '\n';
}

// restore the bubble simulation to its initial state
void Model::initSimulation(){
    // return the bubble to its starting position and velocity
    ballPos.set(0.0, 0.0, 0.0);
    ballVel = originalVel;
    Rising = false;
    moving = false;
    resting = false;
    restingSurface = -1;
    if(!haveVel) ballVel = Vector3d(0.0, 0.0, 0.0);
    if(!haveAir) d = 0;
    if(!haveWind) windVel = 0;
    if(!haveLight) gravity = gravity * 0.2;
}

// this does one time step in the simulation
void Model::timeStep(){
    if(!moving) return;
    Vector3d newBallVel;
    Vector3d newBallPos;

    float timeStepRemain = h;
    float timeStep;

    bool collideDetected = false;

    while(timeStepRemain > 0)
    {
        timeStep = timeStepRemain;

        // force
        a = gravity + d / mass * (windVel - ballVel);

        // new State
        newBallVel = ballVel + a * timeStep;
        newBallPos = ballPos + newBallVel * timeStep;

        int collideIndex = -1;
        Vector3d collidePos;
        Vector3d collideVel;

        collideDetected = false;
        float f;         // fraction

        //determine collision
        float dn0 = 0, dn1 = 0, ddn = 0;
        for(int i = 0; i < 6; i++)
        {
            dn0 = (float)((ballPos - points[i] - ballsize / 2 * normals[i]) * normals[i]);
            dn1 = (float)((newBallPos - points[i] - ballsize / 2 * normals[i]) * normals[i]);

            //check if resting
            if(fabs(dn0) < PRECISION)
            {
                float ballVelPerpNorm = (ballVel * normals[i]);
                float aPerpNorm = (a * normals[i]);
                if(fabs(ballVelPerpNorm) < PRECISION && aPerpNorm < PRECISION)
                {
                    ballVel = ballVel - (ballVelPerpNorm * normals[i]);
                    a = (a - aPerpNorm * normals[i]);
                    //check if stop moving
                    if(ballVel.norm() < PRECISION && a.norm() < PRECISION)
                    {
                        moving = false;
                        std::cout << "stop moving" << '\n';
                        break;
                    }
                    newBallVel = (1 - cf) * (ballVel + a * timeStep);
                    //newBallPos could have a better exprssion
                    newBallPos = ballPos + newBallVel * timeStep;

                    resting = true;
                    std::cout << "*******resting*******" << '\n';

                    continue;
                }
            }

            //detect collision
            ddn = dn0 - dn1;
            f = dn0/(ddn);
            if(f > 0 && f < 1)
            {
                collidePos = ballPos + newBallVel * timeStep * f;
                //std::cout << "collide: " << collidePos << '\n';

                //check if the ball is inside the box
                bool inside = true;
                if(normals[i][0] == 0.0)
                    inside &= (collidePos[0] >= -boxsize/2 && collidePos[0] <= boxsize/2);
                if(normals[i][1] == 0.0)
                    inside &= (collidePos[1] >= -boxsize/2 && collidePos[1] <= boxsize/2);
                if(normals[i][2] == 0.0)
                    inside &= (collidePos[2] >= -boxsize/2 && collidePos[2] <= boxsize/2);
                if(inside)
                {
                    collideDetected = true;
                    collideIndex = i;
                    std::cout << "*******collision-----------" << '\n';
                    break;
                }
            }
        }

        if(collideDetected)
        {
            timeStep = f * timeStep;
            collideVel = ballVel + a * timeStep;
            //collideVel = ballVel + f * (newBallVel - ballVel);

            //not accurate
            collidePos = ballPos + collideVel * timeStep;

            //perpendicular and parallel component of collide velocity
            Vector3d collideVelPerp = (collideVel * normals[collideIndex]) * normals[collideIndex];
            Vector3d collideVelPara = collideVel - collideVelPerp;
            collideVelPerp = -cr * collideVelPerp;
            collideVelPara = (1 - cf) * collideVelPara;

            newBallVel = collideVelPerp + collideVelPara;

            //newBallPos = collidePos + newBallVel * timeStep;
            newBallPos = collidePos;

            std::cout << "old vel: " << ballVel << ", old pos: " << ballPos << '\n';
            std::cout << "new vel: " << newBallVel << ", new pos: " << newBallPos << '\n';
        }

        timeStepRemain = timeStepRemain - timeStep;
        ballVel = newBallVel;
        ballPos = newBallPos;
    }
}

// start the ball
void Model::startBall(){
    Rising = true;
    moving = true;
}

void Model::print() const {
    cout << "Pos: " << ballPos << " | " << "Vel: " << ballVel << endl;
}
