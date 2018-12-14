#ifndef __BALLHITBOXSOLVER_H__
#define __BALLHITBOXSOLVER_H__

#include "PBACollisionSolver.h"
#include "BoxCollider.h"
#include "BallCollider.h"

typedef unsigned char uint8_t;

class BallHitStaticBoxSolver : public PBACollisionSolver 
{
public: 
    BallHitStaticBoxSolver(BallCollider*, BoxCollider*);
    virtual Collision Solve() override;

    uint8_t CheckPointStateToBox(const Vector3d& point, const Vector3d& boxcenter, const Vector3d& boxsize, float extend);

    bool CheckBallBoxCollision(const Vector3d& ballcenter, const Vector3d& boxcenter, const Vector3d& boxsize, float radius);
    bool CheckBallBoxCollisionByState(uint8_t centerState, const Vector3d& ballcenter, const Vector3d& boxcenter, const Vector3d& boxsize, float radius);


private: 
    Vector3d IterateBallPosition(float hOld, float hNew, unsigned int itnum, const Vector3d& startPos, const Vector3d& vel);

private: 
    BallCollider* ballcol;
    BoxCollider* boxcol;

    // float radius;
    // Vector3d boxsize;
};

#endif