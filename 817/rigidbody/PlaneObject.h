#ifndef __PLANEOBJECT_H__
#define __PLANEOBJECT_H__

#include "Common.h"
#include "PBAObject.h"

class PlaneObject : public PBAObject 
{
public: 
    virtual void Draw() override {
        glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        glScalef(5, 0.001, 5);
        //quaternion.GLrotate();
        glutSolidCube(10);
        glPopMatrix();
    }
};

#endif