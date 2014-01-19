/*
 * ParticleForceGenerator.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef PARTICLEFORCEGENERATOR_H_
#define PARTICLEFORCEGENERATOR_H_

#include "particle.h"
#include "precision.h"

namespace Z3D_Jupiter {

class ParticleForceGenerator {
public:
	virtual void updateForce(Particle *particle, real duration) =0;
};

} /* namespace Z3D_Jupiter */

#endif /* PARTICLEFORCEGENERATOR_H_ */
