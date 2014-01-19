/*
 * particle.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "../BaseEngine/Vector3f.h"
#include "precision.h"

using namespace Z3D_Base;

namespace Z3D_Jupiter {

class Particle {
private:
	Vector3f position, velocity, acceleration;
	Vector3f forceAccumulator;

	/*
	 * Damping:
	 * -------
	 * Remove numerical instability added in discrete integration and round off errors
	 */
	real damping;

	/*
	 * 	Inverse Mass:
	 * -------------
	 * Used to hold infinite masses as well
	 */
	real inverseMass;

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Particle();
	Particle(real mass);
	Particle(real mass, real damping);
	virtual ~Particle();

	/*
	 * 	Integrator Unit:
	 * ----------------
	 */
	void integrate(real duration);

	/*
	 * Getters & Setters:
	 * ==================
	 */
	const Vector3f& getAcceleration() const;
	void setAcceleration(const Vector3f& acceleration);
	real getDamping() const;
	void setDamping(real damping);
	real getInverseMass() const;
	void setInverseMass(real inverseMass);
	real getMass() const;
	void setMass(real mass);
	bool hasFiniteMass() const;
	const Vector3f& getPosition() const;
	void setPosition(const Vector3f& position);
	const Vector3f& getVelocity() const;
	void setVelocity(const Vector3f& velocity);

	void addForce(Vector3f force);
	void clearAccumulator();
};

} /* namespace Z3D_Jupiter */

#endif /* PARTICLE_H_ */
