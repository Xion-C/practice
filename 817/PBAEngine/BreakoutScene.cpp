#include "BreakoutScene.h"
#include "PBARigidBody.h"
#include "BoxObject.h"
#include "BreakoutPaddle.h"
#include "BallObject.h"
#include "BoxCollider.h"
#include "BallCollider.h"
#include "ParameterLoader.h"
#include "PBAKeyboardManager.h"
#include "PBAEngine.h"

#include <string>

#define PRECISION 0.01

BreakoutScene::BreakoutScene() : PBAScene()
{

}

void BreakoutScene::Init()
{
    const float thickness = 4;
    const float paddleLength = 5;

    const float red[] = { 0.95, 0.3, 0.35 };
    const float green[] = { 0.35, 0.95, 0.35 };
    const float color1[] = { 0.6, 0.8, 0.65 };
    const float color2[] = { 0.5, 0.05, 0.95 };
    const float color3[] = { 0.5, 0.65, 0.95 };
    const float brick1[] = { 0.2, 0.65, 0.15 };

    BoxObject* wall_left = static_cast<BoxObject*>(AddObject("wall_left", new BoxObject()));
    wall_left->SetSize(1.0, 30.0, thickness);
    //wall_l->SetAngularVelocity(0.0, 0.2, 0.0);
    wall_left->SetPosition(-10.5, 0, 0);
    wall_left->SetDiffuseColor(red[0], red[1], red[2]);
    wall_left->BindCollider(new BoxCollider(wall_left));
    BoxCollider* wallleftcol = static_cast<BoxCollider*>(wall_left->collider);
    wallleftcol->size = wall_left->size;
    boxColliderList.push_back(wallleftcol);


    BoxObject* wall_right = static_cast<BoxObject*>(AddObject("wall_right", new BoxObject()));
    wall_right->SetSize(1.0, 30.0, thickness);
    wall_right->SetPosition(10.5, 0, 0);
    wall_right->SetDiffuseColor(red[0], red[1], red[2]);
    wall_right->BindCollider(new BoxCollider(wall_right));
    BoxCollider* wallrightcol = static_cast<BoxCollider*>(wall_right->collider);
    wallrightcol->size = wall_right->size;
    boxColliderList.push_back(wallrightcol);


    BoxObject* wall_top = static_cast<BoxObject*>(AddObject("wall_top", new BoxObject()));
    wall_top->SetSize(20.0, 1.0, thickness);
    wall_top->SetPosition(0, 14.5, 0);
    wall_top->SetDiffuseColor(red[0], red[1], red[2]);
    wall_top->BindCollider(new BoxCollider(wall_top));
    BoxCollider* walltopcol = static_cast<BoxCollider*>(wall_top->collider);
    walltopcol->size = wall_top->size;
    boxColliderList.push_back(walltopcol);


    BoxObject* table = static_cast<BoxObject*>(AddObject("table", new BoxObject()));
    table->SetSize(20.0, 30.0, 0.01);
    table->SetPosition(0, 0, -thickness/2);
    table->SetDiffuseColor(color1[0], color1[1], color1[2]);



    BreakoutPaddle* paddle = static_cast<BreakoutPaddle*>(AddObject("paddle", new BreakoutPaddle()));
    paddle->SetSize(paddleLength, 1.0, 2.0);
    paddle->SetPosition(0, -14.5, 0);
    paddle->SetLimit(-10 + paddleLength/2, 10 - paddleLength/2);
    paddle->SetDiffuseColor(color2[0], color2[1], color2[2]);
    paddle->BindCollider(new BoxCollider(paddle));
    BoxCollider* paddlecol = static_cast<BoxCollider*>(paddle->collider);
    paddlecol->size = paddle->size;
    paddleCollider = paddlecol;


    BallObject* ball = static_cast<BallObject*>(AddObject("ball", new BallObject()));
    ball->SetStatic(false);
    ball->SetGravity(true);
    ball->radius = 1.0;
    ball->SetPosition(0, -12.9, 0);
    ball->SetVelocity(6, 8, 0);
    ball->SetDiffuseColor(color3[0], color3[1], color3[2], 0.8);
    ball->BindCollider(new BallCollider(ball));
    BallCollider* ballcol = static_cast<BallCollider*>(ball->collider);
    ballcol->radius = ball->radius;
    bounceBallCollider = ballcol;


    /* bricks */
    // BoxObject* brick01 = static_cast<BoxObject*>(AddObject("brick01", new BoxObject()));
    // brick01->SetSize(2.0, 1.0, thickness);
    // brick01->SetPosition(8, 10, 0);
    // brick01->SetDiffuseColor(brick1[0], brick1[1], brick1[2]);
    // brick01->BindCollider(new BoxCollider(brick01));
    // BoxCollider* brick01col = static_cast<BoxCollider*>(brick01->collider);
    // brick01col->size = brick01->size;
    // brickColliderList.push_back(brick01col);

    // BoxObject* brick02 = static_cast<BoxObject*>(AddObject("brick02", new BoxObject()));
    // brick02->SetSize(2.0, 1.0, thickness);
    // brick02->SetPosition(-7, 9.2, 0);
    // brick02->SetDiffuseColor(brick1[0], brick1[1], brick1[2]);
    // brick02->BindCollider(new BoxCollider(brick02));
    // BoxCollider* brick02col = static_cast<BoxCollider*>(brick02->collider);
    // brick02col->size = brick02->size;
    // brickColliderList.push_back(brick02col);

    // BoxObject* brick03 = static_cast<BoxObject*>(AddObject("brick03", new BoxObject()));
    // brick03->SetSize(1.5, 1.2, thickness);
    // brick03->SetPosition(-8.2, 0, 0);
    // brick03->SetDiffuseColor(brick1[0], brick1[1], brick1[2]);
    // brick03->BindCollider(new BoxCollider(brick03));
    // BoxCollider* brick03col = static_cast<BoxCollider*>(brick03->collider);
    // brick03col->size = brick03->size;
    // brickColliderList.push_back(brick03col);


    BoxObject* bricktmp;
    BoxCollider* bricktmpcol;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::string name;
            name = std::string("bricktmp") + std::to_string(i) + std::to_string(j);
            bricktmp = static_cast<BoxObject*>(AddObject(name, new BoxObject()));
            bricktmp->SetSize(1.5, 1.2, thickness/2);
            bricktmp->SetPosition(i*5-7.5, j*3, 0);
            bricktmp->SetDiffuseColor(brick1[0], brick1[1], brick1[2]);
            bricktmp->BindCollider(new BoxCollider(bricktmp));
            bricktmpcol = static_cast<BoxCollider*>(bricktmp->collider);
            bricktmpcol->size = bricktmp->size;
            brickColliderList.push_back(bricktmpcol);
        }
    }


}

void BreakoutScene::Clear()
{
    boxColliderList.clear();
    brickColliderList.clear();
    bounceBallCollider = nullptr;
    paddleCollider = nullptr;
    PBAScene::Clear();
}

void BreakoutScene::Update()
{
    PBAKeyboardManager keyboard = PBAEngine::GetInstance()->GetKeyboard();
    if(keyboard.GetKey('p')) pause = !pause;
    if(pause) return;
    PBAScene::Update();
    for(BoxCollider* boxcol : boxColliderList) 
    {
        HandleBallHitStaticBox(bounceBallCollider, boxcol);
    }


    auto itbrickcol = brickColliderList.begin();
    while(itbrickcol != brickColliderList.end()) 
    {
        if(HandleBallHitStaticBox(bounceBallCollider, *itbrickcol))
        {
            DeleteObject((*itbrickcol)->object->name);
            itbrickcol = brickColliderList.erase(itbrickcol);
        }
        else {
            itbrickcol++;
        }
    }
    // for(BoxCollider* brickcol : brickColliderList) 
    // {
    //     HandleBallHitStaticBox(bounceBallCollider, brickcol);
    // }


    const float startSpeed = 10.0;
    if(HandleBallHitStaticBox(bounceBallCollider, paddleCollider))
    {
        Vector3d ballVel = bounceBallCollider->object->GetVelocity();
        ballVel = ballVel.normalize() * startSpeed;
        if(ballVel.y < 0) ballVel.y = -ballVel.y;
        bounceBallCollider->object->SetVelocity(ballVel.x, ballVel.y, ballVel.z);
    }

    if(brickColliderList.empty()) {
        pause = true;
        std::cout << "***************************" << std::endl;
        std::cout << "*****                 *****" << std::endl;
        std::cout << "*****    YOU WIN !    *****" << std::endl;
        std::cout << "*****                 *****" << std::endl;
        std::cout << "***************************" << std::endl;
    }
    if((bounceBallCollider->object->GetPosition()).y < -20) {
        Clear();
        Init();
        pause = true;
    }

}

// void BreakoutScene::Display()
// {
    
// }

bool BreakoutScene::HandleBallHitStaticBox(BallCollider* ballcol, BoxCollider* boxcol)
{
    const float h = ParameterLoader::GetInstance().timeStep;

    bool haveCollision = false;
    Vector3d ballcolPos = ballcol->object->GetPosition() + ballcol->GetLoacalPosition();
    Vector3d boxcolPos = boxcol->object->GetPosition() + boxcol->GetLoacalPosition();
    Vector3d boxToBall = ballcolPos - boxcolPos;
    float distance = boxToBall.norm();
    if(distance <= PRECISION) {
        haveCollision = true;
    }
    else {
        Vector3d ballPoint = boxcolPos + boxToBall * (1 - (ballcol->radius + PRECISION) / distance);
        haveCollision = boxcol->CheckPointInside(ballPoint);
    }
    if(haveCollision) {
        Vector3d ballVel = ballcol->object->GetVelocity();

        bool checkCollision = false;
        Vector3d newBallPos = ballcolPos - ballVel * 0.5 * h;
        Vector3d newBoxToBall = newBallPos - boxcolPos;
        float newDistance = boxToBall.norm();
        Vector3d newBallPoint = boxcolPos + newBoxToBall * (1 - (ballcol->radius + PRECISION) / distance);
        if(newDistance <= PRECISION) {
            checkCollision = true;
        }
        else {
            checkCollision = boxcol->CheckPointInside(newBallPoint);
        }
        Vector3d collidePosition = newBallPoint;
        if(checkCollision) {
            collidePosition = ballcolPos - ballVel * h;
            if(boxcol->CheckPointInside(collidePosition))
            {
                collidePosition = collidePosition - ballVel * h;
            }
        }

        if(boxcol->CheckPointInY(collidePosition))
        {
            ballcol->object->SetVelocity(-ballVel.x, ballVel.y, ballVel.z);
        }
        else
        {
            ballcol->object->SetVelocity(ballVel.x, -ballVel.y, ballVel.z);
        }

        //pause = true;

        return true;
    }
    else {
        return false;
    }
}