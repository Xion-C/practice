#include "PBAScene.h"
#include <iostream>

PBAScene::PBAScene() : 
    objectlist(),
    timeStep(0.05)
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

PBAObject* PBAScene::AddObject(const std::string& name, PBAObject* obj)
{
    auto res = objectlist.find(name);
    if(res == objectlist.end()) {
        objectlist[name] = obj;
    }
    else {
        IFDEBUG(
            std::cerr << "already have this object" << std::endl;
        )
        delete res->second;
        objectlist[name] = obj;
    }
    return obj;
}

PBAObject* PBAScene::GetObject(const std::string& name)
{
    auto res = objectlist.find(name);
    if(res == objectlist.end()) {
        IFDEBUG(
            std::cout << "no such object" << std::endl;
        )
        return nullptr;
    }
    else {
        return res->second;
    }
}