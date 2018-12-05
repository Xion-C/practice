#include "PBAScene.h"
#include <iostream>

PBAScene::PBAScene() : 
    objectlist(),
    timeStep(0.05),
    pause(false)
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

void PBAScene::Clear()
{
    for(auto& obj : objectlist)
    {
        delete obj.second;
    }
    objectlist.clear();
}

void PBAScene::Update()
{
    if(pause) return;
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

PBARigidBody* PBAScene::AddObject(const std::string& name, PBARigidBody* obj)
{
    auto res = objectlist.find(name);
    if(res == objectlist.end()) {
        objectlist[name] = obj;
        obj->name = name;
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

void PBAScene::DeleteObject(const std::string& name)
{
    auto res = objectlist.find(name);
    if(res == objectlist.end()) {
        IFDEBUG(
            std::cerr << "no such object" << std::endl;
        )
    }
    else {
        delete res->second;
        objectlist.erase(res);
    }
}

PBARigidBody* PBAScene::GetObject(const std::string& name)
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