/*
 * ParticleGravity.cpp
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#include "../ParticleGravity.h"

namespace Z3D_Jupiter {

ParticleGravity::ParticleGravity() {
	this->gravity.setXYZ(0.0f,0.9821f,0.0f);
}

ParticleGravity::ParticleGravity(const Vector3f& gravity) {
	this->gravity = gravity;
}

ParticleGravity::~ParticleGravity() {
	// TODO Auto-generated destructor stub
}

void ParticleGravity::updateForce(Particle* particle, real duration) {
	if(!particle->hasFiniteMass())
		return;

	particle->addForce(this->gravity*particle->getMass());
}

} /* namespace Z3D_Jupiter */

