#include "Breakout_BounceBall.h"
#include "PBAEngine.h"
#include "PBAMouseManager.h"

BounceBall::BounceBall(PBAObject* pad) : 
    BallObject(),
    paddle(pad),
    start(false)
{

}

void BounceBall::Update() 
{
    if(start) {
        BallObject::Update();
    }
    else {
        if(PBAEngine::GetInstance()->GetMouse().GetClick()) {
            start = true;
            std::cout << "***** start *****" << std::endl;
        }
        position.x = paddle->position.x;
    }
}