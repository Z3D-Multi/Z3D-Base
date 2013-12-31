/*
 * Camera.cpp
 *
 *  Created on: 31-Dec-2013
 *      Author: zeneil
 */

#include "../Camera.h"
#include "../Input.h"
#include "../Time.h"
#include "../Debug.h"
namespace Z3D_Base {

const Vector3f Camera::worldUp = Vector3f(0.0f, 1.0f, 0.0f);

Camera::Camera() {

	this->init(Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 1.0f),
			Camera::worldUp);
}

Camera::Camera(Vector3f pos, Vector3f forward, Vector3f up) {
	this->init(pos, forward, up);
}

void Camera::init(Vector3f pos, Vector3f forward, Vector3f up) {

	this->pos = pos;
	this->forward = forward;
	this->up = up;

	this->up.normalize();
	this->forward.normalize();
}

const Vector3f& Camera::getForward() const {
	return this->forward;
}

void Camera::setForward(const Vector3f& forward) {
	this->forward = forward;
}

const Vector3f& Camera::getPos() const {
	return this->pos;
}

void Camera::setPos(const Vector3f& pos) {
	this->pos = pos;
}

const Vector3f& Camera::getUp() const {
	return this->up;
}

void Camera::setUp(const Vector3f& up) {
	this->up = up;
}

Camera::~Camera() {
}

void Camera::move(Vector3f dir, float amt) {
	this->pos += dir * amt;
}

Vector3f Camera::getLeft() {
	Vector3f left = this->up * this->forward;
	return left.normalize();
}

Vector3f Camera::getRight() {
	Vector3f right = this->forward * this->up;
	return right.normalize();
}

void Camera::rotateX(float angle) {
	Vector3f HAxis = (Vector3f) Camera::worldUp * this->forward;
	HAxis.normalize();

	this->forward.rotate(angle, HAxis).normalize();
	this->up = this->forward * HAxis;
	this->up.normalize();
}

void Camera::rotateY(float angle) {
	Vector3f HAxis = (Vector3f) Camera::worldUp * this->forward;
	HAxis.normalize();

	this->forward.rotate(angle, Camera::worldUp).normalize();
	this->up = this->forward * HAxis;
	this->up.normalize();

}

void Camera::rotateZ(float angle) {

	Vector3f ZAxis = (Vector3f) Camera::worldUp;
	this->forward.rotate(angle, ZAxis).normalize();

}

void Camera::input() {

	float fMovAmt = (float) (10.0f * Time::getDelta());
	float fRotAmt = (float) (100.0f * Time::getDelta());

	if (Input::geyKey(GLUT_KEY_UP, true))
		this->rotateX(-fRotAmt);

	if (Input::geyKey(GLUT_KEY_DOWN, true))
		this->rotateX(fRotAmt);

	if (Input::geyKey(GLUT_KEY_LEFT, true))
		this->rotateZ(fRotAmt);

	if (Input::geyKey(GLUT_KEY_RIGHT, true))
		this->rotateZ(-fRotAmt);

	if (Input::geyKey('w', false))
		this->move(this->forward,fMovAmt);


	if (Input::geyKey('s', false))
		this->move(this->forward,-fMovAmt);

	if (Input::geyKey('a', false))
		this->move(this->getLeft(),fMovAmt);

	if (Input::geyKey('d', false))
		this->move(this->getRight(),fMovAmt);

}

} /* namespace Z3D_Base */
