#ifndef __PLANEOBJECT_H__
#define __PLANEOBJECT_H__

#include "Common.h"
#include "PBARigidBody.h"

class PlaneObject : public PBARigidBody 
{
public: 
    virtual void Render() override {
        glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        glScalef(5, 0.001, 5);
        //quaternion.GLrotate();
        glutSolidCube(10);
        glPopMatrix();
    }
};

#endif