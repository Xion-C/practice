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


void ParticleGenerator::GenerateRectPaticles(int number)
{
    //std::cout << "init pos" << pos << '\n';
    for(int i = 0; i < number; i++)
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
            collideDetected = DetectBoxCollision(timeStep,
                                                 posCur,
                                                 posNew,
                                                 collidePos, collideNormal,
                                                 f);
            collideDetected |= DetectSphereCollision(timeStep,
                                                     posCur,
                                                     posNew,
                                                     collidePos,
                                                     collideNormal,
                                                     f);
            collideDetected |= DetectTriangleCollision(timeStep,
                                                       posCur,
                                                       posNew,
                                                       collidePos,
                                                       collideNormal,
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
                                           const Vector3d& posCur,
                                           const Vector3d& posNew,
                                           Vector3d& collidePos,
                                           Vector3d& collideNormal,
                                           float& f)
{
    float boxsize = model->boxsize;

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

bool ParticleGenerator::DetectSphereCollision(const float timeStep,
                                              const Vector3d& posCur,
                                              const Vector3d& posNew,
                                              Vector3d& collidePos,
                                              Vector3d& collideNormal,
                                              float& f)
{
    float ballsize = model->ballsize;
    Vector3d ballPos = model->ballPos;
    float radius = ballsize / 2;

    bool collideDetected = false;
    Vector3d vn1 = posNew - ballPos;
    float dn1 = (float)(vn1).norm();
    if(dn1 <= radius + PRECISION)
    {
        collideDetected = true;
        Vector3d dpos = posNew - posCur;
        //float dposnorm = dpos.norm();
        float a = (float)(dpos * dpos);
        float b = (float)(-2 * vn1 * dpos);
        float c = (float)(vn1 * vn1 - radius * radius);
        float delta = b * b - 4 * a * c;
        float f = (-b + sqrt(delta))/(2 * a);
        f = 1 - f;
        collidePos = posCur + (posNew - posCur) * f;
        collideNormal = (collidePos - ballPos).normalize();

        // std::cout << "[ballcollide]" << '\n';
        // std::cout << "  collidePos: " << collidePos << '\n';
        // std::cout << "  collideNormal: " << collideNormal << '\n';
        // std::cout << "  f: " << f << '\n';
        // std::cout << "a: " << a << "b: " << b << "c: " << c << '\n';
        // std::cout << "====================" << '\n';
    }
    return collideDetected;

}

bool ParticleGenerator::DetectTriangleCollision(float timeStep,
                                                const Vector3d& posCur,
                                                const Vector3d& posNew,
                                                Vector3d& collidePos,
                                                Vector3d& collideNormal,
                                                float& f)
{
    Vector3d v0 = model->v0;
    Vector3d v1 = model->v1;
    Vector3d v2 = model->v2;
    Vector3d triNormal = model->triNormal;

    bool collideDetected = false;

    float dn0 = 0, dn1 = 0, ddn = 0;
    dn0 = (float)((posCur - v0) * triNormal);
    dn1 = (float)((posNew - v0) * triNormal);

    //detect collision
    ddn = dn0 - dn1;
    float checkf = dn0/(ddn);
    if(checkf > 0 && checkf < 1)
    {
        //Vector3d checkCollidePos = posCur + velNew * timeStep * checkf;
        Vector3d checkCollidePos = posCur + (posNew - posCur) * checkf;
        //std::cout << "checkCollidePos: " << checkCollidePos << '\n';

        //check if the object is inside the box
        bool inside = false;

        int maxIndex = 0;
        if(triNormal[1] > triNormal[maxIndex]) maxIndex = 1;
        if(triNormal[2] > triNormal[maxIndex]) maxIndex = 2;
        Vector2d vec01;
        Vector2d vec02;
        Vector2d vec0p;
        switch (maxIndex) {
        case 0:
            vec01.x = v1.y - v0.y;
            vec01.y = v1.z - v0.z;
            vec02.x = v2.y - v0.y;
            vec02.y = v2.z - v0.z;
            vec0p.x = checkCollidePos.y - v0.y;
            vec0p.y = checkCollidePos.z - v0.z;
            break;
        case 1:
            vec01.x = v1.x - v0.x;
            vec01.y = v1.z - v0.z;
            vec02.x = v2.x - v0.x;
            vec02.y = v2.z - v0.z;
            vec0p.x = checkCollidePos.x - v0.x;
            vec0p.y = checkCollidePos.z - v0.z;
            break;
        case 2:
            vec01.x = v1.x - v0.x;
            vec01.y = v1.y - v0.y;
            vec02.x = v2.x - v0.x;
            vec02.y = v2.y - v0.y;
            vec0p.x = checkCollidePos.x - v0.x;
            vec0p.y = checkCollidePos.y - v0.y;
            break;
        }
        float dxy01 = vec01.x * vec02.y - vec02.x * vec01.y;
        float dxy1p = checkCollidePos.y * vec01.x - checkCollidePos.x * vec01.y;
        float dxy2p = checkCollidePos.x * vec02.y - checkCollidePos.y * vec02.x;
        float u = dxy2p / dxy01;
        float v = dxy1p / dxy01;
        if(u + v <= 1 && u >= 0 && v >= 0) inside = true;

        if(inside)
        {
            //if(checkf < PRECISION) continue;
            collideDetected = true;
            collidePos = checkCollidePos;
            f = checkf;
            collideNormal = triNormal;

            // std::cout << "[triangle]" << '\n';
            // std::cout << "  u: " << u << "  v: "<< v << '\n';
            // std::cout << "==================" << '\n';
        }
    }
    return collideDetected;

}


void ParticleGenerator::TimeStep()
{
    if(continuous)
        GenerateRectPaticles(int(speed * h));
    SimulateParticles();
}
