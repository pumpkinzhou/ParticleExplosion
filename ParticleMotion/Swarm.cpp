#include "Swarm.h"

namespace particleMotion {
	Swarm::Swarm()
	{
		m_pParticles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm()
	{
		delete[] m_pParticles;
	}
}
