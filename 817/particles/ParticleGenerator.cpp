/*
    CPSC 8170 Physically Based Animation - Assignment 2

    By Xin Cheng
 */

#include "ParticleGenerator.h"
#include "gauss.h"

#include <cmath>
#include <iostream>

#define PRECISION 0.01

bool ParticleGenerator::LoadParameters(const ParameterLoader& params)
{
    h = params.timeStep;
    speed = params.generateSpeed;
    pos = params.position;
    vel = params.velocity;
    mass = params.mass;
    lifespan = params.lifespan;
    height = params.height;
    width = params.width;
    velStd = params.velocityStd;

    PrintParameters();
    return true;
}

void ParticleGenerator::PrintParameters() const
{
    std::cout << "/----- Particle Generator Parameters: -----/" << '\n';
    std::cout << "time step:        " << h << '\n';
    std::cout << "generate speed:   " << speed << '\n';
    std::cout << "initial position: " << pos << '\n';
    std::cout << "initial velocity: " << vel << '\n';
    std::cout << "velocity std:     " << velStd << '\n';
    std::cout << "initial mass:     " << mass << '\n';
    std::cout << "initial lifespan: " << lifespan << '\n';
    std::cout << "generator height: " << height << '\n';
    std::cout << "generator width:  " << width << '\n';
    std::cout << "/------------------------------------------/" << '\n';
}


void ParticleGenerator::GenerateRectPaticles()
{
    //std::cout << "init pos" << pos << '\n';
    for(int i = 0; i < int(speed * h); i++)
    {
        int velseed[3];
        Vector3d rvel;

        for(int s = 0; s < 3; s++)
        {
            velseed[s] = rand();
            rvel[s] = gauss(vel[s], velStd, velseed[s]);
        }

        double dtime = (double)rand() / RAND_MAX * h;
        double rheight = (double)rand() / RAND_MAX * height;
        double rwidth = (double)rand() / RAND_MAX * width;
        Vector3d rpos(pos[0] - 0.5 * rwidth, pos[1] - 0.5 * rheight, pos[2]);
        rpos = rpos + rvel * h;
        Vector3d rcolor = rvel.normalize() * 0.5 + Vector3d(0.5, 0.5, 0.5);
        //Vector3d rcolor(0, 0, 0);
        float rmass = mass;
        float rlifespan = lifespan;
        Particle particle(rpos, rvel, rmass, rlifespan, rcolor);
        particles.push_back(particle);

    }
}


void ParticleGenerator::SimulateParticles()
{
    Vector3d gravity = model->gravity;
    Vector3d windVel = model->windVel;

    float d = model->d;
    float cr = model->cr;
    float cf = model->cf;
    float boxsize = model->boxsize;

    std::list<Particle>::iterator itparticle = particles.begin();
    while(itparticle != particles.end())
    {
        Vector3d velCur = itparticle->vel;
        Vector3d posCur = itparticle->pos;
        float mass = itparticle->mass;

        Vector3d a;
        Vector3d velNew;
        Vector3d posNew;

        float timeStepRemain = h;
        float timeStep;

        bool collideDetected = false;

        int timeCount = 0;

        while(timeStepRemain > 0)
        {
            timeCount++;
            if(timeCount > 4) break;

            timeStep = timeStepRemain;

            // force
            a = gravity + d / mass * (windVel - velCur);

            // new State
            velNew = velCur + a * timeStep;
            posNew = posCur + velNew * timeStep;

            //int collideIndex = -1;
            Vector3d collideNormal;
            Vector3d collidePos;
            Vector3d collideVel;

            collideDetected = false;
            float f;         // fraction

            //determine collision
            //float dn0 = 0, dn1 = 0, ddn = 0;

            // for(int i = 0; i < 6; i++)
            // {
            //     dn0 = (float)((posCur - model->points[i]) * model->normals[i]);
            //     dn1 = (float)((posNew - model->points[i]) * model->normals[i]);
            //
            //     //detect collision
            //     ddn = dn0 - dn1;
            //     float checkf = dn0/(ddn);
            //     if(checkf > 0 && checkf < 1)
            //     {
            //         Vector3d checkCollidePos = posCur + velNew * timeStep * checkf;
            //         //std::cout << "checkCollidePos: " << checkCollidePos << '\n';
            //
            //         //check if the object is inside the box
            //         bool inside = true;
            //         if(model->normals[i][0] == 0.0)
            //             inside &= (checkCollidePos[0] >= -boxsize/2 && checkCollidePos[0] <= boxsize/2);
            //         if(model->normals[i][1] == 0.0)
            //             inside &= (checkCollidePos[1] >= -boxsize/2 && checkCollidePos[1] <= boxsize/2);
            //         if(model->normals[i][2] == 0.0)
            //             inside &= (checkCollidePos[2] >= -boxsize/2 && checkCollidePos[2] <= boxsize/2);
            //
            //         if(inside)
            //         {
            //             //if(checkf < PRECISION) continue;
            //             collideDetected = true;
            //             collidePos = checkCollidePos;
            //             f = checkf;
            //             //collideIndex = i;
            //             collideNormal = model->normals[i];
            //             //break;
            //         }
            //     }
            // }

            collideDetected = DetectBoxCollision(timeStep,
                                                 boxsize,
                                                 posCur,
                                                 posNew,
                                                 collidePos, collideNormal,
                                                 f);

            if(collideDetected)
            {
                timeStep = f * timeStep;
                collideVel = velCur + a * timeStep;
                //collideVel = velCur + f * (velNew - velCur);

                //not accurate
                //collidePos = posCur + collideVel * timeStep;
                collidePos = collidePos + 0.5 * PRECISION * collideNormal;

                //perpendicular and parallel component of collide velocity
                Vector3d collideVelPerp = (collideVel * collideNormal) * collideNormal;
                Vector3d collideVelPara = collideVel - collideVelPerp;
                collideVelPerp = -cr * collideVelPerp;
                collideVelPara = (1 - cf * (timeStep / h)) * collideVelPara;

                velNew = collideVelPerp + collideVelPara;

                //posNew = collidePos + velNew * timeStep;
                posNew = collidePos;

            }

            timeStepRemain = timeStepRemain - timeStep;
            velCur = velNew;
            posCur = posNew;

        }

        itparticle->pos = posCur;
        itparticle->vel = velCur;
        itparticle->Colorize(h);

        itparticle->lifespan -= h;
        if(itparticle->lifespan < 0) {
            itparticle = particles.erase(itparticle);
        }
        else {
            itparticle++;
        }

    }

}

bool ParticleGenerator::DetectBoxCollision(float timeStep,
                                           float boxsize,
                                           const Vector3d& posCur,
                                           const Vector3d& posNew,
                                           Vector3d& collidePos,
                                           Vector3d& collideNormal,
                                           float& f)
{
    bool collideDetected = false;
    float dn0 = 0, dn1 = 0, ddn = 0;
    for(int i = 0; i < 6; i++)
    {
        dn0 = (float)((posCur - model->points[i]) * model->normals[i]);
        dn1 = (float)((posNew - model->points[i]) * model->normals[i]);

        //detect collision
        ddn = dn0 - dn1;
        float checkf = dn0/(ddn);
        if(checkf > 0 && checkf < 1)
        {
            //Vector3d checkCollidePos = posCur + velNew * timeStep * checkf;
            Vector3d checkCollidePos = posCur + (posNew - posCur) * checkf;
            //std::cout << "checkCollidePos: " << checkCollidePos << '\n';

            //check if the object is inside the box
            bool inside = true;
            if(model->normals[i][0] == 0.0)
                inside &= (checkCollidePos[0] >= -boxsize/2 && checkCollidePos[0] <= boxsize/2);
            if(model->normals[i][1] == 0.0)
                inside &= (checkCollidePos[1] >= -boxsize/2 && checkCollidePos[1] <= boxsize/2);
            if(model->normals[i][2] == 0.0)
                inside &= (checkCollidePos[2] >= -boxsize/2 && checkCollidePos[2] <= boxsize/2);

            if(inside)
            {
                //if(checkf < PRECISION) continue;
                collideDetected = true;
                collidePos = checkCollidePos;
                f = checkf;
                //collideIndex = i;
                collideNormal = model->normals[i];
                //break;
            }
        }
    }
    return collideDetected;

}

void ParticleGenerator::TimeStep()
{
    SimulateParticles();
    GenerateRectPaticles();

}
