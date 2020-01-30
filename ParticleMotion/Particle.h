#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleMotion {

struct Particle
{
	double m_x;
	double m_y;

	double m_xspeed;
	double m_yspeed;

	Particle();
	virtual ~Particle();
	void update();
};

}

#endif  /* PARTICLE_H_ */

