#ifndef __FLOCKINGPARTICLES_H__
#define __FLOCKINGPARTICLES_H__

#include <list>
#include "Vector.h"
#include "StateVector.h"
#include "ParameterLoader.h"
#include "Model.h"
#include "Particle.h"
#include "ParticleCluster.h"

typedef StateVector<Vector3d> SV3;

class FlockingParticles
{
public:
    FlockingParticles(Model* m, ParticleCluster* p) :
        model(m),
        ps(p),
        active(false),
        routeOn(true)
    {
    }

    bool LoadParameters(const ParameterLoader& params);
    void Init();
    void TimeStep();
    void SimulateParticles();
    void MoveLeadBoid(const Vector3d& v);
    void ToggleRoute() {
        routeOn = !routeOn;
    }

private:
    Model* model;
    ParticleCluster* ps;
    float h;

    int pnum;
    bool active;

    float ka; // collision avoidance
    float kv; // velocity matching
    float kc; // centering
    float amax;
    float leadBoidSpeed;

    //lead boid route
    int routePointsNum;
    std::vector<Vector3d> routePoints;
    bool routeOn;

    void HandleLeadBoidRoute();
    Vector3d computeEnvironmentalForce(const SV3& sv, int index, float t);
    Vector3d computeInteractiongForce(const SV3& sv, int i, int j, float t);
    void computeSystemAccelerations(SV3& svd, float* mass, const SV3& sv, float t);
    void computeSystemDynamicFunction(SV3& svd, float* mass, const SV3& sv, float t);
    void computeEulerIntergration(SV3& svnew, const SV3& sv, const SV3& svd, float t);
};

#endif
