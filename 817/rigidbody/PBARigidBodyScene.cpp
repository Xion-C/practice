#include "PBARigidBodyScene.h"
#include "PBAObject.h"
#include "ColliderMesh.h"

#include "PlaneObject.h"

#define PLANEHEIGHT -15.0
#define PRECISION 0.1

RigidBodyScene::RigidBodyScene() :
    PBAScene()
{

}

void RigidBodyScene::Init()
{
    PBAObject* cube0 = AddObject("cube", new PBAObject());
    //objectlist["cube"]->SetVelocity(1, 2, 3);
    cube0->SetAngularVelocity(0.1, 0.1, 0.1);
    cube0->SetPosition(0, 10, 0);
    cube0->colliderMesh->SetCube();
    cube0->colliderMesh->Scale(5, 5, 5);

    //PBAObject* plane0 = AddObject("plane", new PBAObject());
    PBAObject* plane0 = AddObject("plane", new PlaneObject());
    plane0->SetPosition(0, PLANEHEIGHT, 0);
    plane0->SetStatic(true);
}

void RigidBodyScene::Update()
{
    PBAScene::Update();
    HandleStaticCollision(GetObject("plane"), GetObject("cube"));
}

void RigidBodyScene::HandleStaticCollision(PBAObject* objsta, PBAObject* objdyn)
{
    const float height = PLANEHEIGHT;
    const float cr = 0.7;
    Vector3d omega = objdyn->GetAngularVelocity();
    Vector3d pos = objdyn->GetPosition();
    Vector3d vel = objdyn->GetVelocity();
    Matrix3x3 rotMoiInv = objdyn->GetRotMoiInv();
    float mass = objdyn->GetMass();

    Vector3d normal = Vector3d(0, 1, 0);

    ColliderMesh* colliderMesh = objdyn->colliderMesh;
    for(auto& vert : colliderMesh->vertices) {
        if(vert.y <= height + PRECISION) {
            Vector3d ra = vert - pos;
            Vector3d vbefore = omega%ra + vel;
            float vbeforeN = vbefore * normal;
            float j = -(1 + cr) * vbeforeN / \
                (1.0 / mass + normal * (rotMoiInv*(ra%normal)%ra));
            Vector3d J = j * normal;
            objdyn->AddImpulseAtPosition(J, vert);
            //Vector3d newpos = Vector3d(pos.x, pos.y + height + PRECISION - vert.y, pos.z);
            //objdyn->SetVelocity()
            //objdyn->SetPosition(newpos.x, newpos.y, newpos.z);
        }
    }
}