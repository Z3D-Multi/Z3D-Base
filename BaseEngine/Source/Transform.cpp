/*
 * Transform.cpp
 *
 *  Created on: 26-Dec-2013
 *      Author: zeneil
 */

#include "../Transform.h"

namespace Z3D_Base {

Camera Transform::camera;

Transform::Transform() {
	this->scale.setXYZ(1.0f, 1.0f, 1.0f);
}

const Vector3f& Transform::getTranslation() const {
	return translation;
}

void Transform::setTranslation(const Vector3f& transform) {
	this->translation = transform;
}

Transform::~Transform() {
}

void Transform::setScale(float x, float y, float z) {
	this->scale.setXYZ(x, y, z);
}

Camera& Transform::getCamera(){
	return Transform::camera;
}

void Transform::setCamera(Camera& camera) {
	Transform::camera = camera;
}

Matrix4f Transform::getTransform() {

	Matrix4f translation(this->translation, MATRIX4F_INIT_WITH_TRANSLATION);
	Matrix4f rotation(this->rotation, MATRIX4F_INIT_WITH_ROTATION);
	Matrix4f scale(this->scale, MATRIX4F_INIT_WITH_SCALE);
//	Matrix4f cameraRotation(this->camera.getForward(), this->camera.getUp());
//	Matrix4f cameraTranslation(-this->camera.getPos().getX(),-this->camera.getPos().getY(),-this->camera.getPos().getZ(),MATRIX4F_INIT_WITH_TRANSLATION);

	return translation * rotation * scale;
}

void Transform::setTranslation(float x, float y, float z) {
	this->translation.setXYZ(x, y, z);
}

const Vector3f& Transform::getScale() const {
	return scale;
}

void Transform::setScale(const Vector3f& scale) {
	this->scale = scale;
}

void Transform::setRotation(float x, float y, float z) {
	this->rotation.setXYZ(x, y, z);
}

const Vector3f& Transform::getRotation() const {
	return this->rotation;
}

void Transform::setRotation(const Vector3f& rotation) {
	this->rotation = rotation;
}

} /* namespace Z3D_Base */

