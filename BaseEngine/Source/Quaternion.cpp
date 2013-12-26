/*
 * Quaternion.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include "../Quaternion.h"
#include <cmath>

namespace Z3D_Base {

Quaternion::Quaternion() {

	for (int i = 0; i < 3; ++i)
		this->q[i] = 0.0f;

	this->q[_w] = 1.0f;
}

Quaternion::Quaternion(float x, float y, float z, float w) {

	this->q[_x] = x;
	this->q[_y] = y;
	this->q[_z] = z;
	this->q[_w] = w;

}

Quaternion::~Quaternion() {
	// TODO Auto-generated destructor stub
}

float Quaternion::length()
{
	return sqrt(pow(this->q[_x],2)+pow(this->q[_y],2)+pow(this->q[_z],2)+pow(this->q[_w],2));
}

Quaternion Quaternion::normalize()
{
	float lenInverse = 1/length();
	this->q[_x] *= lenInverse;
	this->q[_y] *= lenInverse;
	this->q[_z] *= lenInverse;
	return *this;
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(-q[_x],-q[_y],-q[_z],q[_w]);
}

Quaternion Quaternion::operator*(const Quaternion& rhs)
{
	return Quaternion(
		this->q[_w]*rhs.q[_w] - this->q[_x]*rhs.q[_x] - this->q[_y]*rhs.q[_y] - this->q[_z]*rhs.q[_z],
		this->q[_x]*rhs.q[_w] + this->q[_w]*rhs.q[_x] + this->q[_y]*rhs.q[_z] - this->q[_z]*rhs.q[_y],
		this->q[_y]*rhs.q[_w] + this->q[_w]*rhs.q[_y] + this->q[_z]*rhs.q[_x] - this->q[_x]*rhs.q[_z],
		this->q[_z]*rhs.q[_w] + this->q[_w]*rhs.q[_z] + this->q[_x]*rhs.q[_y] - this->q[_y]*rhs.q[_x]
	);
}

Quaternion Quaternion::operator*(const Vector3f& rhs)
{
	return Quaternion(
		-this->q[_x]*rhs.getX() - this->q[_y]*rhs.getY() - this->q[_z]*rhs.getZ(),
		this->q[_w]*rhs.getX() + this->q[_y]*rhs.getZ() - this->q[_z]*rhs.getY(),
		this->q[_w]*rhs.getY() + this->q[_z]*rhs.getX() - this->q[_x]*rhs.getZ(),
		this->q[_w]*rhs.getZ() + this->q[_x]*rhs.getY() - this->q[_y]*rhs.getX()
	);
}

float Quaternion::getX() const
{
	return this->q[_x];
}
void Quaternion::setX(float x)
{
	this->q[_x] = x;
}
float Quaternion::getY() const
{
	return this->q[_y];
}
void Quaternion::setY(float y)
{
	this->q[_y] = y;
}
float Quaternion::getZ() const
{
	return this->q[_z];
}
void Quaternion::setZ(float z)
{
	this->q[_z] = z;
}
float Quaternion::getW() const
{
	return this->q[_w];
}
void Quaternion::setW(float w)
{
	this->q[_w] = w;
}

} /* namespace Z3D_Base */
