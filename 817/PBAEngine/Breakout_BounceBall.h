#ifndef __BOUNCEBALL_H__
#define __BOUNCEBALL_H__

#include "BallObject.h"

class BounceBall : public BallObject 
{
public: 
    BounceBall(PBAObject*);
    virtual void Update() override;


private: 
    PBAObject* paddle;
    bool start;

};

#endif