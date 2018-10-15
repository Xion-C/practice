#ifndef __PARTICLECLUSTER_H__
#define __PARTICLECLUSTER_H__

#include <list>
#include "Particle.h"


class ParticleCluster
{
public:
    std::list<Particle> particles;

    int GetNum() const {
        return particles.size();
    }

    int Clear() {
        particles.clear();
    }
};

#endif
