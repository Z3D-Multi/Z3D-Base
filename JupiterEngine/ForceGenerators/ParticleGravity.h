/*
 * ParticleGravity.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef PARTICLEGRAVITY_H_
#define PARTICLEGRAVITY_H_

#include "../../BaseEngine/Vector3f.h"

#include "../particle.h"
#include "../ParticleForceGenerator.h"

using namespace Z3D_Base;

namespace Z3D_Jupiter {

class ParticleGravity: public Z3D_Jupiter::ParticleForceGenerator {
private:
	Vector3f gravity;

public:
	ParticleGravity();
	ParticleGravity(const Vector3f &gravity);
	virtual ~ParticleGravity();

	virtual void updateForce(Particle *particle, real duration);
};

} /* namespace Z3D_Jupiter */

#endif /* PARTICLEGRAVITY_H_ */
