#include "PBAObject.h"
#include "ParameterLoader.h"

#define MASS 10
#define CUBESIZE 5.0

PBAObject::PBAObject() : 
    colliderMesh(new ColliderMesh(this)),
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
    torque(),
    staticFlag(false)
{
    ComputerMomentOfInertia();
    moiInv = moi.inv();
    rotMoi = rotation * moi * rotation.transpose();
    rotMoiInv = rotMoi.inv();
    angularMomentum = rotMoi * angularVelocity;
}

PBAObject::~PBAObject()
{
    if(colliderMesh) delete colliderMesh;
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

void PBAObject::SetStatic(bool s) {
    staticFlag = s;
}

void PBAObject::ComputerMomentOfInertia()
{
    float m1, m2, m3;
    float w = CUBESIZE;
    float h = CUBESIZE;
    float l = CUBESIZE;
    m1 = mass * (w * w + h * h) / 12.0;
    m2 = mass * (l * l + w * w) / 12.0;
    m3 = mass * (l * l + h * h) / 12.0;
    moi = Matrix3x3(
        m1, 0, 0, 
        0, m2, 0,
        0, 0, m3);
}

void PBAObject::ComputeEulerIntegration()
{

}


void PBAObject::AddImpulseAtPosition(const Vector3d& imp, const Vector3d& impos)
{
    momentum = momentum + imp;
    const Vector3d ra = impos - position;
    angularMomentum = ra%imp;

    velocity = massInv * momentum;
    angularVelocity = rotMoiInv * angularMomentum;
}

void PBAObject::Update()
{
    const float h = ParameterLoader::GetInstance().timeStep;
    const Vector3d gravity = Vector3d(0, -0.98, 0);

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

    //HandleEnvironmentalForce();
    if(!staticFlag) momDot = momDot + gravity * mass;

    //ComputeEulerIntegration();

    position = position + posDot * h;
    quaternion = quaternion + quatDot * h;
    quaternion = quaternion.normalize();
    momentum = momentum + momDot * h;
    angularMomentum = angularMomentum + angmomDot * h;

    velocity = massInv * momentum;
    angularVelocity = rotMoiInv * angularMomentum;

    //reset
    rotation = quaternion.rotation();
    rotMoi = rotation * moi * rotation.transpose();
    rotMoiInv = rotation * moiInv * rotation.transpose();


    //update collider
    colliderMesh->Update();


    IFDEBUG(
        std::cout << "time step: " << h << std::endl;
        std::cout << "w: " << w << "\n";
        std::cout << "wq: " << wq << "\n";
        std::cout << "quatDot: " << quatDot << "\n";
        std::cout << "quaternion: " << quaternion << "\n";
        std::cout << "angularVelocity: " << angularVelocity << "\n";
        std::cout << "rotation: \n" << rotation << "\n";
        std::cout << "rotMoiInv: \n" << rotMoiInv << "\n";
        std::cout << "==================" << "\n";
    )

}

void PBAObject::Draw()
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    quaternion.GLrotate();
    glutSolidCube(CUBESIZE);
    glPopMatrix();
}