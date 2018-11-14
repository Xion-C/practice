#include "PBAObject.h"

#define MASS 2
#define CUBESIZE 10.0

PBAObject::PBAObject() : 
    mass(MASS),
    massInv(1.0 / mass),
    moi(Matrix3x3(0, 0, 0, 0, 0, 0, 0, 0, 0)),
    position(),
    quaternion(),
    rotation(quaternion.rotation()),
    velocity(),
    angularVelocity(),
    momentum(mass * velocity),
    angularMomentum(),
    force(),
    torque()
{
    ComputerMomentOfInertia();
    moiInv = moi.inv();
    rotMoi = rotation * moi * rotation.transpose();
    rotMoiInv = rotMoi.inv();
    angularMomentum = rotMoi * angularVelocity;
}

void RefreshState()
{
    //rotation = quaternion.rotation();

}

void PBAObject::SetPosition(float x, float y, float z)
{
    position = Vector3d(x, y, z);
}

void PBAObject::SetVelocity(float vx, float vy, float vz)
{
    velocity = Vector3d(vx, vy, vz);
    momentum = mass * velocity;
}

void PBAObject::SetAngle(float yaw, float pitch, float roll)
{
    quaternion.set(yaw, pitch, roll);
    rotation = quaternion.rotation();
    rotMoi = rotation * moi * rotation.transpose();
    angularMomentum = rotMoi * angularVelocity;
}

void PBAObject::SetAngularVelocity(float ux, float uy, float uz)
{
    angularVelocity = Vector3d(ux, uy, uz);
    angularMomentum = rotMoi * angularVelocity;
}

void PBAObject::ComputerMomentOfInertia()
{
    float m1, m2, m3;
    m1 = m2 = m3 = 0.4 * mass * CUBESIZE;
    moi = Matrix3x3(
        m1, 0, 0, 
        0, m2, 0,
        0, 0, m3);
}

void PBAObject::ComputeEulerIntegration()
{

}

void PBAObject::Update()
{
    const float h = 0.05;

    Vector3d posDot;
    Quaternion quatDot;
    Vector3d momDot;
    Vector3d angmomDot;
    Vector3d w;

    //posDot = massInv * momentum; //velocity
    posDot = velocity;
    rotation = quaternion.rotation();
    rotMoiInv = rotation * moiInv * rotation.transpose();
    //Vector3d w = rotMoiInv * angularMomentum; //angular velocity
    w = angularVelocity;
    
    Quaternion wq = Quaternion(w);
    quatDot = 0.5 * wq * quaternion;

    momDot = Vector3d(0, 0, 0);
    angmomDot = Vector3d(0, 0, 0);

    //ComputeEulerIntegration();

    position = position + posDot * h;
    quaternion = quaternion + quatDot * h;
    quaternion = quaternion.normalize();
    momentum = momentum + momDot * h;
    angularMomentum = angularMomentum + angmomDot * h;

    velocity = massInv * momentum;
    angularVelocity = rotMoiInv * angularMomentum;

    std::cout << "w: " << w << "\n";
    std::cout << "wq: " << wq << "\n";
    std::cout << "quatDot: " << quatDot << "\n";
    std::cout << "quaternion: " << quaternion << "\n";
    std::cout << "angularVelocity: " << angularVelocity << "\n";
    std::cout << "rotation: \n" << rotation << "\n";
    std::cout << "rotMoiInv: \n" << rotMoiInv << "\n";
    std::cout << "==================" << "\n";

}

void PBAObject::Draw()
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    quaternion.GLrotate();
    glutSolidCube(CUBESIZE);
    glPopMatrix();
}