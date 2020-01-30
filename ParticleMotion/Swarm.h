#pragma once
#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particleMotion {

class Swarm
{
public:
	const static int NPARTICLES = 5000;
private:
	Particle* m_pParticles;
public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles() { return m_pParticles; };
};

}

#endif  /* SWARM_H_ */