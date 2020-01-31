#pragma once
#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particleExplosion {

class Swarm
{
public:
	const static int NPARTICLES = 5000;
private:
	Particle* m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles() { return m_pParticles; };
	void update(int elapsed);
};

}

#endif  /* SWARM_H_ */