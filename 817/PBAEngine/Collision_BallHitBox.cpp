#include "Collision_BallHitBox.h"
#include "BallObject.h"
#include "BoxObject.h"
#include "ParameterLoader.h"

#include <bitset>


#define PRECISION 0.005
#define ITERATION_NUM 6


BallHitStaticBoxSolver::BallHitStaticBoxSolver(BallCollider* ball, BoxCollider* box) : 
    PBACollisionSolver(),
    ballcol(ball),
    boxcol(box)
    // radius(ballcol->radius),
    // boxsize(boxcol->size)
{

}

uint8_t BallHitStaticBoxSolver::CheckPointStateToBox(const Vector3d& point, const Vector3d& boxcenter, const Vector3d& boxsize, float extend)
{
    uint8_t state = 0b000000;
    if(point.x < boxcenter.x - boxsize.x/2 - extend) {
        state |= 0b000001;
    }
    else if(point.x > boxcenter.x + boxsize.x/2 + extend) {
        state |= 0b000010;
    }

    if(point.y < boxcenter.y - boxsize.y/2 - extend) {
        state |= 0b000100;
    }
    else if(point.y > boxcenter.y + boxsize.y/2 + extend) {
        state |= 0b001000;
    }

    if(point.z < boxcenter.z - boxsize.z/2 - extend) {
        state |= 0b010000;
    }
    else if(point.z > boxcenter.z + boxsize.z/2 + extend) {
        state |= 0b100000;
    }

    return state;
}

bool BallHitStaticBoxSolver::CheckBallBoxCollision(const Vector3d& ballcenter, const Vector3d& boxcenter, const Vector3d& boxsize, float radius)
{

    // broad phase
    uint8_t state = CheckPointStateToBox(ballcenter, boxcenter, boxsize, radius + PRECISION);
    if(state != 0) {
        return false;
    }
    else {
        // uint8_t centerState = CheckPointStateToBox(ballcenter, boxcenter, boxsize, 0 + PRECISION);
        // return CheckBallBoxCollisionByState(centerState, ballcenter, boxcenter, boxsize, radius);
        return true;
    }
}

/* unfinished function */
bool CheckBallBoxCollisionByState(uint8_t centerState, const Vector3d& ballcenter, const Vector3d& boxcenter, const Vector3d& boxsize, float radius)
{
    bool haveCollision = false;
    // narrow phase
    switch(centerState) 
    {
    case 0b000000:
        haveCollision = true;
        break;
    case 0b000001:
    case 0b000010:
    case 0b000100:
    case 0b001000:
    case 0b010000:
    case 0b100000:
        haveCollision = true;
        break;
    default:
        break;
    }
    return haveCollision;
}

Vector3d BallHitStaticBoxSolver::IterateBallPosition(float hOld, float hNew, unsigned int itnum, const Vector3d& startPos, const Vector3d& vel)
{
    float h = ParameterLoader::GetInstance().timeStep;
    std::cout << "---------- iteration: " << itnum << std::endl;
    std::cout << "hOld: " << hOld << std::endl;
    std::cout << "hNew: " << hNew << std::endl;
    std::cout << "startPos: " << startPos << std::endl;
    std::cout << "vel: " << vel << std::endl;
    std::cout << "--------------------------" << std::endl;
    if(itnum <= 0) return startPos + vel * hOld * h;
    else itnum--;
    Vector3d middlePos = startPos + vel * 0.5 * (hOld + hNew) * h;
    bool haveCollision = CheckBallBoxCollision(middlePos, boxcol->GetPosition(), boxcol->size, ballcol->radius);

    if(haveCollision) {
        return IterateBallPosition(hOld, 0.5 * (hOld + hNew), itnum, startPos, vel);
    }
    else {
        return IterateBallPosition(0.5 * (hOld + hNew), hNew, itnum, startPos, vel);
    }
}

Collision BallHitStaticBoxSolver::Solve() 
{
    float h = ParameterLoader::GetInstance().timeStep;

    BallObject* ballobj = static_cast<BallObject*>(ballcol->object);
    BoxObject* boxobj = static_cast<BoxObject*>(boxcol->object);

    Vector3d ballpos = ballcol->GetPosition();
    Vector3d boxpos = boxcol->GetPosition();

    //last position should be a member of RigidBody
    Vector3d lastballpos = ballpos - ballobj->GetVelocity() * h;

    bool haveCollision = CheckBallBoxCollision(ballpos, boxpos, boxcol->size, ballcol->radius);

    bool haveLastCollision = CheckBallBoxCollision(lastballpos, boxpos, boxcol->size, ballcol->radius);

    IFDEBUG(
        if(haveLastCollision) {
            // std::cout << "have last collision to : " << boxcol->object->name << std::endl;
            // if(haveCollision) {
            //     std::cout << "stuck in : " << boxcol->object->name << std::endl;
            // }
        }

    );

    if(haveCollision) {
        Vector3d ballColPos = IterateBallPosition(0, 1, ITERATION_NUM, lastballpos, ballobj->GetVelocity());

        uint8_t centerState = CheckPointStateToBox(ballColPos, boxcol->GetPosition(), boxcol->size, PRECISION);

        Vector3d normal;
        Vector3d collisionPoint; // point on ball
        Vector3d boxColPoint; // collision point on box
        int signx = (int(centerState & 0b000011) << 1) - 3;
        int signy = (int(centerState & 0b001100) >> 1) - 3;
        int signz = (int(centerState & 0b110000) >> 3) - 3;
        switch(centerState) {
        //center
        case 0b000000:
            IFDEBUG(
                std::cout << "weird centerState" << std::endl;
            )
            break;
        //face
        case 0b000001:
        case 0b000010:
            normal = Vector3d(signx, 0, 0);
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit face: " << (int)centerState << std::endl;

            break;
        case 0b000100:
        case 0b001000:
            normal = Vector3d(0, signy, 0);
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit face: " << (int)centerState << std::endl;

            break;
        case 0b010000:
        case 0b100000:
            normal = Vector3d(0, 0, signz);
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit face: " << (int)centerState << std::endl;


            break;
        //edge
        case 0b010100:
        case 0b011000:
        case 0b100100:
        case 0b101000:
            boxColPoint.x = ballColPos.x;
            boxColPoint.y = boxpos.y + signy * (boxcol->size.y)/2;
            boxColPoint.z = boxpos.z + signz * (boxcol->size.z)/2;
            normal = (ballpos - boxColPoint).normalize();
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit edge: " << (int)centerState << std::endl;

            break;
        case 0b010001:
        case 0b010010:
        case 0b100001:
        case 0b100010:
            boxColPoint.x = boxpos.x + signx * (boxcol->size.x)/2;
            boxColPoint.y = ballColPos.y;
            boxColPoint.z = boxpos.z + signz * (boxcol->size.z)/2;
            normal = (ballpos - boxColPoint).normalize();
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit edge: " << (int)centerState << std::endl;

            break;
        case 0b000101:
        case 0b000110:
        case 0b001001:
        case 0b001010:
            boxColPoint.x = boxpos.x + signx * (boxcol->size.x)/2;
            boxColPoint.y = boxpos.y + signy * (boxcol->size.y)/2;
            boxColPoint.z = ballColPos.z;
            normal = (ballpos - boxColPoint).normalize();
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit edge: " << (int)centerState << std::endl;

            break;
        case 0b010101:
        case 0b010110:
        case 0b011001:
        case 0b011010:
        case 0b100101:
        case 0b100110:
        case 0b101001:
        case 0b101010:
            boxColPoint.x = boxpos.x + signx * (boxcol->size.x)/2;
            boxColPoint.y = boxpos.y + signy * (boxcol->size.y)/2;
            boxColPoint.z = boxpos.z + signz * (boxcol->size.z)/2;
            normal = (ballpos - boxColPoint).normalize();
            collisionPoint = ballColPos - normal * ballcol->radius;

            // std::cout << "hit vertex: " << std::bitset<8>(centerState) << std::endl;
            break;

        default: 
            IFDEBUG(
                std::cout << "impossible centerState" << std::endl;
            );
            break;
        }

        IFDEBUG(
            std::cout << "collide with: " << boxcol->object->name << std::endl;
            std::cout << "collisionPoint: " << collisionPoint << std::endl;
            std::cout << "normal: " << normal << std::endl;
        );

        ballcol->object->SetPosition(ballColPos + PRECISION * normal);

        return Collision(true, collisionPoint, normal);
    }

    else {
        return Collision(false);
    }


}