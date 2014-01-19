/*
 * particle.cpp
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#include "../particle.h"
#include "../../BaseEngine/Debug.h"
#include <assert.h>

namespace Z3D_Jupiter {

Particle::Particle() {
	this->inverseMass = 0.0f;
	this->damping = 1.0f;
}


Particle::Particle(real mass) {
	this->inverseMass = powf(mass,-1.0f);
	this->damping = 1.0f;
}

Particle::Particle(real mass, real damping) {
	this->inverseMass = powf(mass,-1.0f);
	this->damping = damping;
}

Particle::~Particle() {
}

const Vector3f& Particle::getAcceleration() const {
	return acceleration;
}

void Particle::setAcceleration(const Vector3f& acceleration) {
	this->acceleration = acceleration;
}

real Particle::getDamping() const {
	return damping;
}

void Particle::setDamping(real damping) {
	this->damping = damping;
}

real Particle::getInverseMass() const {
	return inverseMass;
}

void Particle::setInverseMass(real inverseMass) {
	this->inverseMass = inverseMass;
}

const Vector3f& Particle::getPosition() const {
	return position;
}

void Particle::setPosition(const Vector3f& position) {
	this->position = position;
}

const Vector3f& Particle::getVelocity() const {
	return velocity;
}

real Particle::getMass() const {
	if(this->inverseMass!=0.0f)
		return powf(this->inverseMass,-1.0f);

	Debug::error("Request for infinite mass");
	return -1.0f;
}

void Particle::setMass(real mass) {
	this->inverseMass = powf(mass,-1.0f);
}

bool Particle::hasFiniteMass() const {
	return this->inverseMass > 0.0f;
}

void Particle::setVelocity(const Vector3f& velocity) {
	this->velocity = velocity;
}

void Particle::integrate(real duration) {
	assert(duration>0.0f);

	this->position += this->velocity * duration;

	Vector3f resultingAcceleration = this->acceleration + this->forceAccumulator*this->inverseMass;
	this->velocity += resultingAcceleration*duration;
	this->velocity *= real_pow(this->damping, duration);
	this->clearAccumulator();
}

void Particle::addForce(Vector3f force) {
	this->forceAccumulator+= force;
}

void Particle::clearAccumulator() {
	this->forceAccumulator.setXYZ(0.0f,0.0f,0.0f);
}

} /* namespace Z3D_Jupiter */
