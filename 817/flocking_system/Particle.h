/*
    CPSC 8170 Physically Based Animation - Assignment 2

    By Xin Cheng
 */

#ifndef __PARTICLE_H__
#define __PARTICLE_H__


#include "Vector.h"

class Particle
{
public:
    Vector3d pos; //position
    Vector3d vel; //velocity
    Vector3d oldpos;
    Vector3d oldvel;

    float mass;
    float lifespan;
    Vector3d color;

    Particle() {
    }
    Particle(const Vector3d& p, const Vector3d& v, float m, float l, const Vector3d& c) :
        pos(p), vel(v),
        oldpos(p), oldvel(v),
        mass(m), lifespan(l), color(c) {
    }

    void SetState(const Vector3d& p, const Vector3d& v)
    {
        oldpos = pos;
        oldvel = vel;
        pos = p;
        vel = v;
    }

    inline void Colorize()
    {
        Vector3d dcolor = vel.normalize() * 0.5 + Vector3d(0.5, 0.5, 0.5);
        color = color + 0.2 * (dcolor - color);
    }
};



#endif
