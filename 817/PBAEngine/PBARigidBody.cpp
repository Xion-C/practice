#include "PBARigidBody.h"
#include "ParameterLoader.h"

#define MASS 1
#define CUBESIZE 5.0

PBARigidBody::PBARigidBody() : 
    PBAObject(),
    mesh(nullptr),
    renderer(nullptr),
    collider(nullptr),
    mass(MASS),
    massInv(1.0 / mass),
    moi(Matrix3x3(0, 0, 0, 0, 0, 0, 0, 0, 0)),
    rotation(orientation.rotation()),
    velocity(),
    angularVelocity(),
    momentum(mass * velocity),
    angularMomentum(),
    force(),
    torque(),
    gravityFlag(false),
    /* this part need to be moved to renderer */
    diffuseColor(std::vector<float>(4, 0.5)),
    specularColor(std::vector<float>(4, 1)),
    shininess(60.0)
{
    diffuseColor[3] = 1.0;
    Init();
}

PBARigidBody::~PBARigidBody()
{
    if(mesh) delete mesh;
    if(renderer) delete renderer;
    if(collider) delete collider;
}

void RefreshState()
{
    //rotation = orientation.rotation();

}

void PBARigidBody::SetVelocity(float vx, float vy, float vz)
{
    velocity = Vector3d(vx, vy, vz);
    momentum = mass * velocity;
}
void PBARigidBody::SetVelocity(const Vector3d& v)
{
    velocity = v;
    momentum = mass * velocity;
}

void PBARigidBody::SetAngle(float yaw, float pitch, float roll)
{
    orientation.set(yaw, pitch, roll);
    rotation = orientation.rotation();
    rotMoi = rotation * moi * rotation.transpose();
    angularMomentum = rotMoi * angularVelocity;
}

void PBARigidBody::SetAngularVelocity(float ux, float uy, float uz)
{
    angularVelocity = Vector3d(ux, uy, uz);
    angularMomentum = rotMoi * angularVelocity;
}

void PBARigidBody::SetGravity(bool s) {
    gravityFlag = s;
}


void PBARigidBody::BindCollider(PBACollider* col) {
    if(collider) delete collider;
    collider = col;
}

/************************************************/
void PBARigidBody::SetDiffuseColor(float r, float g, float b, float a)
{
    diffuseColor[0] = r;
    diffuseColor[1] = g;
    diffuseColor[2] = b;
    diffuseColor[3] = a;
}

void PBARigidBody::SetSpecularColor(float r, float g, float b, float a)
{
    diffuseColor[0] = r;
    diffuseColor[1] = g;
    diffuseColor[2] = b;
    diffuseColor[3] = a;
}

void PBARigidBody::SetShininess(float shin)
{
    shininess = shin;
}
/************************************************/

void PBARigidBody::ComputeEulerIntegration()
{

}


void PBARigidBody::AddImpulseAtPosition(const Vector3d& imp, const Vector3d& impos)
{
    momentum = momentum + imp;
    const Vector3d ra = impos - position;
    angularMomentum = ra%imp;

    velocity = massInv * momentum;
    angularVelocity = rotMoiInv * angularMomentum;
}

void PBARigidBody::Init()
{
    //ComputerMomentOfInertia();
    // moiInv = moi.inv();
    // rotMoi = rotation * moi * rotation.transpose();
    // rotMoiInv = rotMoi.inv();
    // angularMomentum = rotMoi * angularVelocity;
}

void PBARigidBody::Update()
{
    if(!activatedFlag) return;

    const float h = ParameterLoader::GetInstance().timeStep;
    const Vector3d gravity = Vector3d(0, -0.98, 0);

    Vector3d posDot;
    Quaternion quatDot;
    Vector3d momDot;
    Vector3d angmomDot;
    Vector3d w;

    //posDot = massInv * momentum; //velocity
    posDot = velocity;
    rotation = orientation.rotation();
    rotMoiInv = rotation * moiInv * rotation.transpose();

    //Vector3d w = rotMoiInv * angularMomentum; //angular velocity
    w = angularVelocity;
    Quaternion wq = Quaternion(w);
    quatDot = 0.5 * wq * orientation;

    momDot = Vector3d(0, 0, 0);
    angmomDot = Vector3d(0, 0, 0);

    //HandleEnvironmentalForce();
    if(!staticFlag) momDot = momDot + gravity * mass;

    //ComputeEulerIntegration();

    position = position + posDot * h;
    orientation = orientation + quatDot * h;
    orientation = orientation.normalize();
    momentum = momentum + momDot * h;
    angularMomentum = angularMomentum + angmomDot * h;

    velocity = massInv * momentum;
    angularVelocity = rotMoiInv * angularMomentum;

    //reset
    rotation = orientation.rotation();
    rotMoi = rotation * moi * rotation.transpose();
    rotMoiInv = rotation * moiInv * rotation.transpose();


    //update collider
    //colliderMesh->Update();


    // IFDEBUG(
    //     std::cout << "time step: " << h << std::endl;
    //     std::cout << "w: " << w << "\n";
    //     std::cout << "wq: " << wq << "\n";
    //     std::cout << "quatDot: " << quatDot << "\n";
    //     std::cout << "orientation: " << orientation << "\n";
    //     std::cout << "angularVelocity: " << angularVelocity << "\n";
    //     std::cout << "rotation: \n" << rotation << "\n";
    //     std::cout << "rotMoiInv: \n" << rotMoiInv << "\n";
    //     std::cout << "==================" << "\n";
    // )

}

void PBARigidBody::Render()
{
    if(!activatedFlag) return;
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    orientation.GLrotate();
    glutSolidCube(CUBESIZE);
    glPopMatrix();
}