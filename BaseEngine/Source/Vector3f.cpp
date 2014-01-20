/*
 * Vector3f.cpp
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#include "../Vector3f.h"
#include "../Mathf.h"
#include <glm/glm.hpp>
#include <glm/core/type_mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <cmath>
#include <iostream>

#ifndef PI
#define PI 3.14159265
#endif

namespace Z3D_Base {

Vector3f::Vector3f() {

	this->x=this->y=this->z=0.0f;

}

Vector3f::Vector3f(float x,float y,float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

Vector3f::Vector3f(const Vector3f &v) {
	this->x=v.x;
	this->y=v.y;
	this->z=v.z;
}

Vector3f::~Vector3f() {

}

float Vector3f::getX() const {
	return x;
}

void Vector3f::setX(float x) {
	this->x = x;
}

float Vector3f::getY() const {
	return y;
}

void Vector3f::setY(float y) {
	this->y = y;
}

float Vector3f::getZ() const {
	return z;
}

void Vector3f::setZ(float z) {
	this->z = z;
}

void Vector3f::setXYZ(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3f::length()
{
	return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

Vector3f Vector3f::normalize()
{

	float lenInverse = this->length();
	if(lenInverse==0.0f)
		return *this;

	lenInverse = 1/lenInverse;
	this->x *= lenInverse;
	this->y *= lenInverse;
	this->z *= lenInverse;
	return *this;
}

float Vector3f::dotProduct(Vector3f a,Vector3f b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

Vector3f Vector3f::crossProduct(Vector3f a,Vector3f b)
{
	return a.operator*(b);
}


Vector3f Vector3f::rotate(float angle, Vector3f axis)
{

	axis.normalize();

	glm::vec4 pos = glm::toMat4(glm::angleAxis(angle,glm::vec3(axis.getX(),axis.getY(),axis.getZ()))) * glm::vec4(this->getX(),this->getY(),this->getZ(),1.0f);

	this->setXYZ(pos.x,pos.y,pos.z);
	return *this;
}

Vector3f Vector3f::rotateToObtainNewVector(float angle,Vector3f axis)
{
	Vector3f temp(this->x,this->y,this->z);
	temp = temp.rotate(angle,axis);
	return temp;
}

Vector3f Vector3f::operator=(const Vector3f& rhs)
{
	this->x=rhs.x;
	this->y=rhs.y;
	this->z=rhs.z;
	return *this;
}

bool Vector3f::operator== (const Vector3f& rhs) const
{
	return this->x==rhs.x && this->y==rhs.y && this->z==rhs.z;
}

Vector3f Vector3f::operator* (float rhs)
{
	return Vector3f(x*rhs,y*rhs,z*rhs);
}

Vector3f Vector3f::operator*(const Vector3f& rhs)
{
	return Vector3f(
				this->y*rhs.z-rhs.y*this->z,
				this->z*rhs.x-rhs.z*this->x,
				this->x*rhs.y-rhs.x*this->y
			);
}

Vector3f Vector3f::operator+ (const Vector3f& rhs)
{
	return Vector3f(this->x+rhs.x,this->y+rhs.y,this->z+rhs.z);
}

Vector3f Vector3f::operator+ (float rhs)
{
	return Vector3f (this->x+rhs,this->y+rhs,this->z+rhs);
}

Vector3f Vector3f::operator- (const Vector3f& rhs)
{
	return Vector3f(this->x-rhs.x,this->y-rhs.y,this->z-rhs.z);
}

Vector3f Vector3f::operator- (float rhs)
{
	return Vector3f(this->x-rhs,this->y-rhs,this->z-rhs);
}

Vector3f Vector3f::operator/ (float rhs)
{
	return Vector3f(this->x/rhs,this->y/rhs,this->z/rhs);
}

Vector3f Vector3f::operator*= (float rhs)
{
	this->x*=rhs;
	this->y*=rhs;
	this->z*=rhs;
	return *this;
}

Vector3f Vector3f::operator+= (float rhs)
{
	this->x+=rhs;
	this->y+=rhs;
	this->z+=rhs;
	return *this;
}

Vector3f Vector3f::operator+= (const Vector3f& rhs)
{
	this->x+=rhs.x;
	this->y+=rhs.y;
	this->z+=rhs.z;
	return *this;
}

Vector3f Vector3f::operator-= (float rhs)
{
	this->x-=rhs;
	this->y-=rhs;
	this->z-=rhs;
	return *this;
}

Vector3f Vector3f::operator-= (const Vector3f& rhs)
{
	this->x-=rhs.x;
	this->y-=rhs.y;
	this->z-=rhs.z;
	return *this;
}

Vector3f Vector3f::operator/= (float rhs)
{
	this->x/=rhs;
	this->y/=rhs;
	this->z/=rhs;
	return *this;
}


} /* namespace Z3D_Base */
