#ifndef __BREAKOUTPADDLE_H__
#define __BREAKOUTPADDLE_H__

#include "Common.h"
#include "BoxObject.h"

class BreakoutPaddle : public BoxObject 
{
public: 
    virtual void Update() override;

    void SetLimit(float, float);

private: 
    float limitRight, limitLeft;
};

#endif