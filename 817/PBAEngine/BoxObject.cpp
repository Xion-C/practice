#include "BoxObject.h"
#include "ParameterLoader.h"

#define CUBESIZE 1.0

BoxObject::BoxObject() : 
    PBARigidBody(),
    size(Vector3d(1.0, 1.0, 1.0))
{
    //staticFlag = true;
    Init();
}

void BoxObject::ComputerMomentOfInertia()
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

void BoxObject::SetSize(float x, float y, float z)
{
    size = Vector3d(x, y, z);
}

void BoxObject::Init()
{
    ComputerMomentOfInertia();
    moiInv = moi.inv();
    rotMoi = rotation * moi * rotation.transpose();
    rotMoiInv = rotMoi.inv();
    angularMomentum = rotMoi * angularVelocity;

}

void BoxObject::Update()
{
    if(!activatedFlag) return;
    if(staticFlag) return;
    const float h = ParameterLoader::GetInstance().timeStep;
    const Vector3d gravity = ParameterLoader::GetInstance().gravity;

    Vector3d posDot;
    Quaternion quatDot;
    Vector3d momDot;
    Vector3d angmomDot;

    posDot = massInv * momentum;
    rotation = orientation.rotation();
    rotMoiInv = rotation * moiInv * rotation.transpose();

    Quaternion wq = Quaternion(angularVelocity);
    quatDot = 0.5 * wq * orientation;


    momDot = Vector3d(0, 0, 0);
    angmomDot = Vector3d(0, 0, 0);

    momDot = momDot + gravity * mass;

    //integration
    position = position + velocity * h;
    orientation = orientation + quatDot * h;
    orientation = orientation.normalize();

    momentum = momentum + momDot * h;
    angularMomentum = angularMomentum + angmomDot * h;

    velocity = massInv * momentum;

    // IFDEBUG(
    //     std::cout << "box update: " << std::endl;
    //     std::cout << "box position: " << position << std::endl;
    // );

}

void BoxObject::Render()
{
    if(!activatedFlag) return;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor.data());
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor.data());
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    orientation.GLrotate();
    glScalef(size.x, size.y, size.z);
    glutSolidCube(CUBESIZE);
    glPopMatrix();

    // IFDEBUG(
    //     std::cout << "box draw: " << std::endl;
    //     std::cout << "box size: " << size << std::endl;
    // );
}



