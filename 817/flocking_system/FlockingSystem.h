#ifndef __FLOCKINGSYSTEM_H__
#define __FLOCKINGSYSTEM_H__

#include <list>
#include "Model.h"
#include "ParameterLoader.h"
#include "Particle.h"
#include "ParticleCluster.h"
#include "StateVector.h"
#include "Vector.h"

typedef StateVector<Vector3d> SV3;

class FlockingParticles {
   private:
    Model *model;
    ParticleCluster *ps;
    float h;

    int pnum;
    bool active;

    float ka;  // collision avoidance
    float kv;  // velocity matching
    float kc;  // centering
    float amax;
    // distance thresholds
    float r1;
    float r2;
    // FOV thresholds
    float t1;
    float t2;

    float leadBoidSpeed;

    Particle leadBoid;

    // lead boid route
    int routePointsNum;
    std::vector<Vector3d> routePoints;
    bool routeOn;

   public:
    FlockingParticles(Model *m, ParticleCluster *p)
        : model(m), ps(p), active(false), routeOn(true) {}

    bool LoadParameters(const ParameterLoader &params);
    void Init();
    void TimeStep();
    void SimulateParticles();
    const Particle *GetLeadBoid() const;
    void MoveLeadBoid(const Vector3d &v);
    void ToggleRoute() { routeOn = !routeOn; }

   private:
    void HandleLeadBoidRoute();
    Vector3d computeEnvironmentalForce(const SV3 &sv, int index, float t);
    Vector3d computeInteractiongForce(const SV3 &sv, int i, int j, float t);
    void computeFlockingInteractionAccels(Vector3d aij[3], const SV3 &sv, int i,
                                          int j, float t);
    void computeFlockingLeadBoidAccels(Vector3d aij[3], const SV3 &sv, int i,
                                       float t);
    void computeSystemAccelerations(SV3 &svd, float *mass, const SV3 &sv,
                                    float t);
    void computeSystemDynamicFunction(SV3 &svd, float *mass, const SV3 &sv,
                                      float t);
    void computeEulerIntergration(SV3 &svnew, const SV3 &sv, const SV3 &svd,
                                  float t);
    void computeRK4Intergration(SV3 &svnew, float *mass, const SV3 &sv,
                                const SV3 &svd, float t);
};

#endif
