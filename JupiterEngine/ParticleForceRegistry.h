/*
 * ParticleForceRegistry.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef PARTICLEFORCEREGISTRY_H_
#define PARTICLEFORCEREGISTRY_H_

#include "stdi.h"
#include <vector>

namespace Z3D_Jupiter {

class ParticleForceRegistry {
protected:
	struct ParticleForceRegistration {
		Particle *particle;
		ParticleForceGenerator *fg;
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;

public:

	/*
	 * add:
	 * ----------------
	 * Add specific registration
	 */
	void add(Particle* particle, ParticleForceGenerator *fg);

	/*
	 * remove:
	 * ----------------
	 * Remove specific registration
	 */
	bool remove(Particle* particle, ParticleForceGenerator *fg);

	/*
	 * clear:
	 * ----------------
	 * Clears all registrations
	 */
	void clear();

	/*
	 * updateAllForces:
	 * ----------------
	 * Calls corresponding generators
	 */
	void updateAllForces(real duration);
	void updateAllForcesAndParticles(real duration);
};

} /* namespace Z3D_Jupiter */

#endif /* PARTICLEFORCEREGISTRY_H_ */
