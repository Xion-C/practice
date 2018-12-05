#include "BallObject.h"
#include "ParameterLoader.h"

BallObject::BallObject() : 
    PBARigidBody(),
    radius(1.0)
{
    
}

void BallObject::Init()
{
    // moiInv = moi.inv();
    // rotMoi = rotation * moi * rotation.transpose();
    // rotMoiInv = rotMoi.inv();
    // angularMomentum = rotMoi * angularVelocity;
}

void BallObject::Update()
{
    const float h = ParameterLoader::GetInstance().timeStep;
    const Vector3d gravity = ParameterLoader::GetInstance().gravity;

    if(!staticFlag) {

        position = position + velocity * h;

        if(gravityFlag) {
            velocity = velocity + gravity * h;
        }

        Quaternion wq = Quaternion(angularVelocity);
        Quaternion quatDot = 0.5 * wq * orientation;

        orientation = orientation + quatDot * h;
        orientation = orientation.normalize();
    }

}


void BallObject::Draw()
{
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor.data());
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor.data());
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    orientation.GLrotate();
    glutSolidSphere(radius, 36, 13);
    glPopMatrix();

}

