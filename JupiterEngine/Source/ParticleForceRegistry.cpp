/*
 * ParticleForceRegistry.cpp
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#include "../ParticleForceRegistry.h"

namespace Z3D_Jupiter {

void Z3D_Jupiter::ParticleForceRegistry::add(Particle* particle,
		ParticleForceGenerator* fg) {

	ParticleForceRegistration s;
	s.particle = particle;
	s.fg = fg;

	this->registrations.push_back(s);
}

bool Z3D_Jupiter::ParticleForceRegistry::remove(Particle* particle,
		ParticleForceGenerator* fg) {


	bool removed = false;

	for(Registry::iterator i = registrations.begin(); i!=registrations.end();i++)
	{
		if(i->particle == particle && i->fg == fg)
		{
			this->registrations.erase(i);
			removed = true;
		}
	}

	return removed;
}

void Z3D_Jupiter::ParticleForceRegistry::clear() {
}

void Z3D_Jupiter::ParticleForceRegistry::updateAllForces(real duration) {

	Registry::iterator i = registrations.begin();
	for (; i != registrations.end(); i++) {
		i->fg->updateForce(i->particle, duration);
	}
}

void Z3D_Jupiter::ParticleForceRegistry::updateAllForcesAndParticles(
		real duration) {

	Registry::iterator i = registrations.begin();
		for (; i != registrations.end(); i++) {
			i->fg->updateForce(i->particle, duration);
			i->particle->integrate(duration);
		}
}


} /* namespace Z3D_Jupiter */
