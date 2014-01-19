/*
 * ParticleDrag.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef PARTICLEDRAG_H_
#define PARTICLEDRAG_H_
#include "../../BaseEngine/Vector3f.h"

#include "../particle.h"
#include "../ParticleForceGenerator.h"

namespace Z3D_Jupiter {

class ParticleDrag:public ParticleForceGenerator {
private:
	real k1, k2;

public:
	ParticleDrag();
	ParticleDrag(real k1, real k2);
	virtual ~ParticleDrag();

	virtual void updateForce(Particle *particle, real duration);

};

} /* namespace Z3D_Jupiter */

#endif /* PARTICLEDRAG_H_ */
