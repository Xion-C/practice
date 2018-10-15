#include <vector>
#include "FlockingParticles.h"
#include "ParticleCluster.h"
#include "Utility.h"


bool FlockingParticles::LoadParameters(const ParameterLoader &params)
{
    h = params.timeStep;
    ka = params.ka;
    kv = params.kv;
    kc = params.kc;
    amax = params.amax;
    leadBoidSpeed = params.leadBoidSpeed;
    routePointsNum = params.routePointsNum;
    routePoints = params.routePoints;
}

void FlockingParticles::Init()
{
    active = true;
}


void FlockingParticles::MoveLeadBoid(const Vector3d& v)
{
    Particle* leadBoid = &(*(ps->particles.begin()));
    // leadBoid->pos = leadBoid->pos + v * h;
    // leadBoid->vel = v;
    //leadBoid->vel = leadBoid->vel + v;
    Vector3d direction = v.normalize();
    leadBoid->vel = leadBoid->vel + direction * leadBoidSpeed;
    leadBoid->pos = leadBoid->pos + leadBoid->vel * h;
}

void FlockingParticles::HandleLeadBoidRoute()
{
    static int currentRoute = 0;
    Particle* leadBoid = &(*(ps->particles.begin()));
    Vector3d toPoint = routePoints[currentRoute] - leadBoid->pos;
    float distance = toPoint.norm();
    if(distance < 0.5)
    {
        currentRoute = (currentRoute + 1) % routePointsNum;
    }
    else
    {
        MoveLeadBoid(toPoint);
    }
}

Vector3d FlockingParticles::computeEnvironmentalForce(const SV3& sv, int i, float t)
{
    return Vector3d(0, 0, 0);
}

Vector3d FlockingParticles::computeInteractiongForce(const SV3& sv, int i, int j, float t)
{
    Vector3d xij = sv.data[j] - sv.data[i];
    Vector3d xijn = xij.normalize();
    float dij = xij.norm();
    Vector3d vij = sv.data[j + pnum] - sv.data[i + pnum];

    // std::cout << "svj+n: " << sv.data[j + pnum] << " " << j << '\n';
    // std::cout << "svi+n: " << sv.data[i + pnum] << " " << i << '\n';
    // std::cout << "vij:  " << vij << '\n';

    // collision avoidance
    Vector3d aija = -(ka / dij) * xijn;
    // velocity matching
    Vector3d aijv = kv * vij;
    // centering
    Vector3d aijc = kc * xij;

    float aan = aija.norm();
    float avn = aijv.norm();
    float acn = aijc.norm();

    // residual acceleration
    float ar = amax;
    Vector3d ai = (ar < aan ? ar : aan) * aija.normalize();
    ar = amax - ai.norm();
    ai = ai + (ar < avn ? ar : avn) * aijv.normalize();
    ar = amax - ai.norm();
    ai = ai + (ar < acn ? ar : acn) * aijc.normalize();

    return ai;

}

void FlockingParticles::computeSystemAccelerations(SV3& svd, float* mass, const SV3& sv, float t)
{
    Vector3d fij;
    for(int i = 0; i < pnum; i++)
    {
        svd.data[i + pnum] = \
            (1 / mass[i]) * computeEnvironmentalForce(sv, i, t);
    }

    for(int i = 0; i < pnum; i++)
    {
        for(int j = 0; j < pnum; j++)
        {
            if(i == j)
                fij = 0;
            else
                fij = computeInteractiongForce(sv, i, j, t);
            svd.data[i + pnum] = svd.data[i + pnum] + (1 / mass[i]) * fij;
            svd.data[j + pnum] = svd.data[j + pnum] - (1 / mass[j]) * fij;
        }
    }

}

void FlockingParticles::computeSystemDynamicFunction(SV3& svd, float* mass, const SV3& sv, float t)
{
    computeSystemAccelerations(svd, mass, sv, t);
    //int num = sv.N;
    // copy velocity
    for(int n = 0; n < pnum; n++)
    {
        svd.data[n] = sv.data[n + pnum];
    }
}

void FlockingParticles::computeEulerIntergration(SV3& svnew, const SV3& sv, const SV3& svd, float t)
{
    svnew = sv + svd * t;
    //svnew = sv;
}


void FlockingParticles::SimulateParticles()
{
    pnum = ps->GetNum();
    if(0 == pnum) return;

    std::list<Particle>& particles = ps->particles;

    //std::cout << "num: "<< pnum << '\n';

    SV3 sv(pnum);
    float mass[pnum];

    //set state vector
    std::list<Particle>::iterator itparticle = particles.begin();
    int n = 0;
    while(itparticle != particles.end())
    {
        sv.data[n] = itparticle->pos;
        sv.data[n + pnum] = itparticle->vel;

        mass[n] = itparticle->mass;
        n++;
        itparticle++;
    }

    //system dynamic function
    SV3 svd(pnum);
    computeSystemDynamicFunction(svd, mass, sv, h);

    //new state vector
    SV3 svnew(pnum);
    computeEulerIntergration(svnew, sv, svd, h);

    //set new state
    itparticle = particles.begin();
    n = 0;
    while(itparticle != particles.end())
    {
        itparticle->SetState(svnew.data[n], svnew.data[n + pnum]);
        itparticle->Colorize();
        // itparticle->pos = svnew.data[n];
        // itparticle->vel = svnew.data[n + pnum];
        n++;
        itparticle++;
    }
}

void FlockingParticles::TimeStep()
{
    if(active && ps->GetNum())
    {
        SimulateParticles();
        if(routeOn) HandleLeadBoidRoute();
    }
}
