/*
 * Vector2f.cpp
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#include "../Vector2f.h"
#include "../Mathf.h"
#include <cmath>

#ifndef PI
#define PI 3.14159265
#endif

namespace Z3D_Base {

Vector2f::Vector2f() {
	// TODO Auto-generated constructor stub
	this->x=0.0f;
	this->y=0.0f;
}

Vector2f::Vector2f(float x, float y) {
	this->x=x;
	this->y=y;
}

Vector2f::Vector2f(const Vector2f &v) {
	this->x=v.x;
	this->y=v.y;
}
Vector2f::~Vector2f() {

}

float Vector2f::getX() const {
	return x;
}

void Vector2f::setX(float x) {
	this->x = x;
}

float Vector2f::getY() const {
	return y;
}

void Vector2f::setY(float y) {
	this->y = y;
}

void Vector2f::setXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2f::length()
{
	return sqrt(pow(x,2)+pow(y,2));
}

Vector2f Vector2f::normalize()
{
	float lenInverse = 1/length();
	x *= lenInverse;
	y *= lenInverse;
	return *this;
}

float Vector2f::dotProduct(Vector2f a, Vector2f b)
{
	return a.x*b.x+a.y*b.y;
}

Vector2f Vector2f::rotate(float angle)
{
	float theta = angle * PI / 180.0f;
	float x = this->x*cos(theta) - this->y*sin(theta);
	float y = this->y*cos(theta) + this->x*sin(theta);

	this->setXY(Mathf::round(x),Mathf::round(y));

	return *this;
}

Vector2f Vector2f::rotateToObtainNewVector(float angle)
{
	Vector2f temp(this->x,this->y);
	temp = temp.rotate(angle);
	return temp;
}

Vector2f Vector2f::operator= (Vector2f rhs)
{
	this->x=rhs.x;
	this->y=rhs.y;
	return *this;
}

bool Vector2f::operator== (const Vector2f& rhs) const
{
	return this->x==rhs.x && this->y==rhs.y;
}

Vector2f Vector2f::operator* (float rhs)
{
	return Vector2f(x*rhs,y*rhs);
}

Vector2f Vector2f::operator+ (Vector2f rhs)
{
	return Vector2f(this->x+rhs.x,this->y+rhs.y);
}

Vector2f Vector2f::operator+ (float rhs)
{
	Vector2f temp(this->x+rhs,this->y+rhs);
	return temp;
}

Vector2f Vector2f::operator- (Vector2f rhs)
{
	return Vector2f(this->x-rhs.x,this->y-rhs.y);
}

Vector2f Vector2f::operator- (float rhs)
{
	return Vector2f(this->x-rhs,this->y-rhs);
}

Vector2f Vector2f::operator/ (float rhs)
{
	return Vector2f(this->x/rhs,this->y/rhs);
}

Vector2f Vector2f::operator*= (float rhs)
{
	this->x*=rhs;
	this->y*=rhs;
	return *this;
}

Vector2f Vector2f::operator+= (float rhs)
{
	this->x+=rhs;
	this->y+=rhs;
	return *this;
}

Vector2f Vector2f::operator+= (Vector2f rhs)
{
	this->x+=rhs.x;
	this->y+=rhs.y;
	return *this;
}

Vector2f Vector2f::operator-= (float rhs)
{
	this->x-=rhs;
	this->y-=rhs;
	return *this;
}

Vector2f Vector2f::operator-= (Vector2f rhs)
{
	this->x-=rhs.x;
	this->y-=rhs.y;
	return *this;
}

Vector2f Vector2f::operator/= (float rhs)
{
	this->x/=rhs;
	this->y/=rhs;
	return *this;
}

} /* namespace Z3D_Base */
