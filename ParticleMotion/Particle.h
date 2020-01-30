#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleMotion {

struct Particle
{
	double m_x;
	double m_y;

	double m_speed;
	double m_direction;

	Particle();
	virtual ~Particle();
	void update(int interval);
};

}

#endif  /* PARTICLE_H_ */

