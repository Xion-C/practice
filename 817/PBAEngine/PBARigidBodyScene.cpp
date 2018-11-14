#include "PBARigidBodyScene.h"

RigidBodyScene::RigidBodyScene() :
    PBAScene()
{

}

void RigidBodyScene::Init()
{
    objectlist["cube"] = new PBAObject;
    //objectlist["cube"]->SetVelocity(1, 2, 3);
    objectlist["cube"]->SetAngularVelocity(0.1, 0.1, 0.1);
}