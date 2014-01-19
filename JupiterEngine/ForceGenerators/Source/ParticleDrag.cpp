/*
 * ParticleDrag.cpp
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#include "../ParticleDrag.h"

using namespace Z3D_Base;

namespace Z3D_Jupiter {

ParticleDrag::ParticleDrag() {
	this->k1=this->k2=0.0f;

}

ParticleDrag::~ParticleDrag() {
	// TODO Auto-generated destructor stub
}

ParticleDrag::ParticleDrag(real k1, real k2) {
	this->k1=k1;
	this->k2=k2;
}

void ParticleDrag::updateForce(Particle* particle, real duration) {
	Vector3f force;
	force = particle->getVelocity();

	real dragCoeff = force.length();
	dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;
	force.normalize();
	force *= -dragCoeff;
	particle->addForce(force);
}

} /* namespace Z3D_Jupiter */
