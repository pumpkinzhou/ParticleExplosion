#include "Particle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdlib.h>

namespace particleExplosion {
	Particle::Particle()
	{
		init();
	}

	Particle::~Particle(){}

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}

	void Particle::update(int interval)
	{
		m_direction += 0.001 * interval;
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1)
			init();

		if (rand() < RAND_MAX / 100)
			init();
	}
} /* end namespace */