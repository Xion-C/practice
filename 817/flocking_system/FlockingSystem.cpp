#include "FlockingSystem.h"
#include "ParticleCluster.h"
#include "Utility.h"

#include <cmath>
#include <vector>

bool FlockingParticles::LoadParameters(const ParameterLoader &params) {
    h = params.timeStep;
    ka = params.ka;
    kv = params.kv;
    kc = params.kc;
    r1 = params.r1;
    r2 = params.r2;
    t1 = params.t1;
    t2 = params.t2;
    amax = params.amax;
    leadBoidSpeed = params.leadBoidSpeed;
    routePointsNum = params.routePointsNum;
    routePoints = params.routePoints;
}

void FlockingParticles::Init() { active = true; }

const Particle *FlockingParticles::GetLeadBoid() const { return &leadBoid; }

void FlockingParticles::MoveLeadBoid(const Vector3d &v) {
    // Particle *leadBoid = &(*(ps->particles.begin()));

    // leadBoid->pos = leadBoid->pos + v * h;
    // leadBoid->vel = v;
    // leadBoid->vel = leadBoid->vel + v;
    // Vector3d direction = v.normalize();
    // Vector3d newvel = leadBoid.vel + direction;
    Vector3d newvel = leadBoid.vel + v;
    newvel = newvel.normalize() * leadBoidSpeed;
    // while ((leadBoid.vel) * direction < 0) {
    //     newvel = leadBoid.vel + direction * leadBoidSpeed;
    // }
    Vector3d newpos = leadBoid.pos + leadBoid.vel * h;
    leadBoid.SetState(newpos, newvel);
    leadBoid.Colorize();
}

void FlockingParticles::HandleLeadBoidRoute() {
    static int currentRoute = 0;
    float turnrate = leadBoidSpeed * 0.1;
    // Particle *leadBoid = &(*(ps->particles.begin()));
    Vector3d toPoint = routePoints[currentRoute] - leadBoid.pos;
    float distance = toPoint.norm();
    if (distance < 1) {
        currentRoute = (currentRoute + 1) % routePointsNum;
        toPoint = routePoints[currentRoute] - leadBoid.pos;
        MoveLeadBoid(toPoint.normalize() * turnrate);
    } else {
        MoveLeadBoid(toPoint.normalize() * turnrate);
    }
}

Vector3d FlockingParticles::computeEnvironmentalForce(const SV3 &sv, int i,
                                                      float t) {
    return Vector3d(0, 0, 0);
}

// Vector3d FlockingParticles::computeInteractiongForce(const SV3 &sv, int i,
// int j, float t)
// {
//     Vector3d xij = sv.data[j] - sv.data[i];
//     Vector3d xijn = xij.normalize();
//     float dij = xij.norm();
//     Vector3d vij = sv.data[j + pnum] - sv.data[i + pnum];

//     // collision avoidance
//     Vector3d aija = -(ka / dij) * xijn;
//     // velocity matching
//     Vector3d aijv = kv * vij;
//     // centering
//     Vector3d aijc = kc * xij;

//     // // distance
//     // float kd = 0;
//     // if(dij < r1)
//     // {
//     //     kd = 1;
//     // }
//     // else if(dij <= r2)
//     // {
//     //     kd = (r2 - dij) / (r2 - r1);
//     // }

//     return ai;
// }

void FlockingParticles::computeFlockingInteractionAccels(Vector3d aij[3],
                                                         const SV3 &sv, int i,
                                                         int j, float t) {
    Vector3d xij = sv.data[j] - sv.data[i];
    Vector3d xijn = xij.normalize();
    float dij = xij.norm();
    Vector3d vij = sv.data[j + pnum] - sv.data[i + pnum];
    Vector3d vijn = vij.normalize();

    // distance
    float kd = 0.0;
    if (dij <= r1) {
        kd = 1.0;
    } else if (dij <= r2) {
        kd = (r2 - dij) / (r2 - r1);
    }
    // FOV
    float costheta = (xijn * vijn);
    float theta = acos(costheta) / M_1_PI * 180;
    float kt = 1;
    if (theta <= t1 * 0.5) {
        kt = 1;
    } else if (theta <= t2 * 0.5) {
        kt = (t2 * 0.5 - theta) / (t2 * 0.5 - t1 * 0.5);
    } else {
        kt = 0;
    }

    // collision avoidance
    aij[0] = -(ka / dij) * xijn * kt * kd;
    // velocity matching
    aij[1] = kv * vij * kt * kd;
    // centering
    aij[2] = kc * xij * kt * kd;
}

void FlockingParticles::computeFlockingLeadBoidAccels(Vector3d aij[3],
                                                      const SV3 &sv, int i,
                                                      float t) {
    Vector3d xij = leadBoid.pos - sv.data[i];
    Vector3d xijn = xij.normalize();
    float dij = xij.norm();
    Vector3d vij = leadBoid.vel - sv.data[i + pnum];
    Vector3d vijn = vij.normalize();

    // collision avoidance
    aij[0] = -(ka / dij) * xijn;
    // velocity matching
    aij[1] = kv * vij;
    // centering
    aij[2] = kc * xij;

    // std::cout << "lead aij: " << aij[0] << aij[1] << aij[2] << std::endl;
}

void FlockingParticles::computeSystemAccelerations(SV3 &svd, float *mass,
                                                   const SV3 &sv, float t) {
    for (int i = 0; i < pnum; i++) {
        svd.data[i + pnum] =
            (1 / mass[i]) * computeEnvironmentalForce(sv, i, t);
    }

    // general method
    // Vector3d fij;
    // for (int i = 0; i < pnum; i++)
    // {
    //     for (int j = i + 1; j < pnum; j++)
    //     {
    //         fij = computeInteractiongForce(sv, i, j, t);
    //         svd.data[i + pnum] = svd.data[i + pnum] + (1 / mass[i]) * fij;
    //         svd.data[j + pnum] = svd.data[j + pnum] - (1 / mass[j]) * fij;
    //     }
    // }

    Vector3d *aa = new Vector3d[pnum];
    Vector3d *av = new Vector3d[pnum];
    Vector3d *ac = new Vector3d[pnum];
    Vector3d aij[3];
    for (int i = 0; i < pnum; i++) {
        for (int j = i + 1; j < pnum; j++) {
            computeFlockingInteractionAccels(aij, sv, i, j, t);
            aa[i] = aa[i] + aij[0];
            av[i] = av[i] + aij[1];
            ac[i] = ac[i] + aij[2];
            aa[j] = aa[j] - aij[0];
            av[j] = av[j] - aij[1];
            ac[j] = ac[j] - aij[2];
        }

        // lead boid
        computeFlockingLeadBoidAccels(aij, sv, i, t);
        aa[i] = aa[i] + aij[0];
        av[i] = av[i] + aij[1];
        ac[i] = ac[i] + aij[2];
    }

    for (int i = 0; i < pnum; i++) {
        float aan = aa[i].norm();
        float avn = av[i].norm();
        float acn = ac[i].norm();
        // residual acceleration
        float ar = amax;
        Vector3d ai = (ar < aan ? ar : aan) * aa[i].normalize();
        ar = amax - ai.norm();
        ai = ai + (ar < avn ? ar : avn) * av[i].normalize();
        ar = amax - ai.norm();
        ai = ai + (ar < acn ? ar : acn) * ac[i].normalize();
        svd.data[i + pnum] = ai;
    }

    delete[] aa;
    delete[] av;
    delete[] ac;
}

void FlockingParticles::computeSystemDynamicFunction(SV3 &svd, float *mass,
                                                     const SV3 &sv, float t) {
    computeSystemAccelerations(svd, mass, sv, t);
    // int num = sv.N;
    // copy velocity
    for (int n = 0; n < pnum; n++) {
        svd.data[n] = sv.data[n + pnum];
    }
}

void FlockingParticles::computeEulerIntergration(SV3 &svnew, const SV3 &sv,
                                                 const SV3 &svd, float t) {
    svnew = sv + svd * t;
    // svnew = sv;
}

void FlockingParticles::computeRK4Intergration(SV3 &svnew, float *mass,
                                               const SV3 &sv, const SV3 &svd,
                                               float t) {
    int n = sv.N;
    SV3 k1 = svd;
    SV3 k2(n);
    computeSystemDynamicFunction(k2, mass, sv + k1 * (0.5 * h), t + 0.5 * h);
    SV3 k3(n);
    computeSystemDynamicFunction(k3, mass, sv + k2 * (0.5 * h), t + 0.5 * h);
    SV3 k4(n);
    computeSystemDynamicFunction(k3, mass, sv + k2 * h, t + h);
    svnew = sv + (k1 + k2 * 2 + k3 * 2 + k4) * (h / 6.0);
}

void FlockingParticles::SimulateParticles() {
    pnum = ps->GetNum();
    if (0 == pnum) return;

    std::list<Particle> &particles = ps->particles;

    // // lead boid
    // Vector3d leadx = leadBoid.pos;
    // Vector3d leadv = leadBoid.vel;
    // Vector3d leada = 0;

    SV3 sv(pnum);
    float mass[pnum];

    // set state vector
    std::list<Particle>::iterator itparticle = particles.begin();
    int n = 0;
    while (itparticle != particles.end()) {
        sv.data[n] = itparticle->pos;
        sv.data[n + pnum] = itparticle->vel;

        mass[n] = itparticle->mass;
        n++;
        itparticle++;
    }

    // system dynamic function
    SV3 svd(pnum);
    computeSystemDynamicFunction(svd, mass, sv, h);

    // new state vector
    SV3 svnew(pnum);
    computeEulerIntergration(svnew, sv, svd, h);
    // computeRK4Intergration(svnew, mass, sv, svd, h);

    // set new state
    itparticle = particles.begin();
    n = 0;
    while (itparticle != particles.end()) {
        itparticle->SetState(svnew.data[n], svnew.data[n + pnum]);
        itparticle->Colorize();

        // itparticle->pos = svnew.data[n];
        // itparticle->vel = svnew.data[n + pnum];
        n++;
        itparticle++;
    }

    leadBoid.SetState(leadBoid.pos, leadBoid.vel);
    leadBoid.Colorize();

    // std::cout << "leed: " << (particles.begin())->pos << std::endl;
    // std::cout << "lead: " << leadBoid.pos << std::endl;
}

void FlockingParticles::TimeStep() {
    if (active && ps->GetNum()) {
        SimulateParticles();
        if (routeOn) HandleLeadBoidRoute();
    }
}
