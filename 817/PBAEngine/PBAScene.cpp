#include "PBAScene.h"
#include "ParameterLoader.h"

#include <iostream>

#define DEFAULT_TIMESTEP 0.05

PBAScene::PBAScene() : 
    objectlist(),
    timeStep(DEFAULT_TIMESTEP),
    pause(false)
{
    timeStep = ParameterLoader::GetInstance().timeStep;
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
        obj.second->Render();
    }

    for(auto& ui : uilist)
    {
        ui.second->Render();
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

PBAUI* PBAScene::AddUI(const std::string& name, PBAUI* ui)
{
    auto res = uilist.find(name);
    if(res == uilist.end()) {
        uilist[name] = ui;
        ui->name = name;
    }
    else {
        IFDEBUG(
            std::cerr << "already have this object" << std::endl;
        );
        delete res->second;
        uilist[name] = ui;
    }

    return ui;
}

PBAUI* PBAScene::GetUI(const std::string& name) 
{
    auto res = uilist.find(name);
    if(res == uilist.end()) {
        IFDEBUG(
            std::cerr << "no such ui" << std::endl;
        )
        return nullptr;
    }
    else {
        return res->second;
    }
}