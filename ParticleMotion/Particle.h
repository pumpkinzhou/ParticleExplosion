#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleExplosion {

struct Particle
{
	double m_x;
	double m_y;

	double m_speed;
	double m_direction;

	Particle();
	virtual ~Particle();
	void init();
	void update(int interval);
};

} /* end namespace */

#endif  /* PARTICLE_H_ */

