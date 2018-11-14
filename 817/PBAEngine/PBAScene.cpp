#include "PBAScene.h"
#include <iostream>

PBAScene::PBAScene() : 
    objectlist()
{
    
}

PBAScene::~PBAScene()
{
    for(auto& obj : objectlist)
    {
        delete obj.second;
    }
}

void PBAScene::Init()
{
    std::cout << "PBAScene::Init" << "\n";
}

void PBAScene::Update()
{
    for(auto& obj : objectlist)
    {
        obj.second->Update();
    }
}

void PBAScene::Display()
{
    for(auto& obj : objectlist)
    {
        obj.second->Draw();
    }
}