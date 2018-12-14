#include "Breakout_Paddle.h"
#include "PBAEngine.h"
#include "PBAKeyboardManager.h"

#define MOVESPEED 5

void BreakoutPaddle::Update() 
{
    const float h = ParameterLoader::GetInstance().timeStep;
    const PBAKeyboardManager& keyboard = PBAEngine::GetInstance()->GetKeyboard();
    const PBAMouseManager& mouse = PBAEngine::GetInstance()->GetMouse();
    const View& viewer = PBAEngine::GetInstance()->GetView();


    if(keyboard.GetKey('a')) {
        velocity = Vector3d(-MOVESPEED, 0, 0);
    }
    else if(keyboard.GetKey('d')) {
        velocity = Vector3d(MOVESPEED, 0, 0);
    }
    else {
        velocity = Vector3d(0, 0, 0);
        //velocity = 0.5 * velocity;
    }

    float mx = (float)mouse.GetX();
    mx = mx - viewer.getWidth() / 2.0;
    mx = mx / 480 * 15;
    position.x = mx;

    BoxObject::Update();
    if(position.x <= limitLeft) 
    {
        position.x = limitLeft;
        velocity = Vector3d(0, 0, 0);
    }
    else if(position.x >= limitRight)
    {
        position.x = limitRight;
        velocity = Vector3d(0, 0, 0);
    }

}

void BreakoutPaddle::SetLimit(float l, float r)
{
    limitRight = r;
    limitLeft = l;
}