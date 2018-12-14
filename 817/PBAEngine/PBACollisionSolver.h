#ifndef __PBACOLLISIONSOLVER_H__
#define __PBACOLLISIONSOLVER_H__

#include "Common.h"
#include "PBAMath.h"
#include "BallCollider.h"
#include "BoxCollider.h"

struct Collision {
    bool contact;
    Vector3d point;
    Vector3d normal;

    Collision(
        bool ct = false, 
        const Vector3d& colpos = Vector3d(), 
        const Vector3d& colnorm = Vector3d()
    ) : 
        contact(ct), 
        point(colpos), 
        normal(colnorm) 
    {}
};

class PBACollisionSolver {
public: 
    virtual Collision Solve() = 0;
};

#endif