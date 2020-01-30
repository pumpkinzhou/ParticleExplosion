#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleMotion {

struct Particle
{
	double m_x;
	double m_y;

	Particle();
	virtual ~Particle();
};

}

#endif  /* PARTICLE_H_ */

