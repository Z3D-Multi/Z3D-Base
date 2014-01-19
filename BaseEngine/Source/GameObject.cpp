/*
 * GameObject.cpp
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#include "../GameObject.h"

namespace Z3D_Base {

GameObject::GameObject() {
	this->mesh = 0x0;
	this->shader = new Shader();
	this->transform = new Transform();
	this->particle = new Z3D_Jupiter::Particle();

}


void GameObject::setShader(Shader *shader) {
	this->shader = shader;
}

Z3D_Jupiter::Particle* GameObject::getParticle(){
	return particle;
}

void GameObject::draw() {
	this->shader->bind();
	this->shader->setUniform("transform", this->transform->getTransform());
	this->mesh->draw();
}

bool GameObject::hasMeshAttached() {
	return this->mesh == 0x0;
}

Mesh* GameObject::getMesh() {
	return this->mesh;
}

void GameObject::setMesh(Mesh* mesh) {
	if(hasMeshAttached())
		delete(this->mesh);

	this->mesh = mesh;
}

Shader* GameObject::getShader() {
	return this->shader;
}

Transform* GameObject::getTransform() {
	return this->transform;
}

void GameObject::setTransform(Transform* transform) {
	this->transform = transform;
}

void GameObject::setParticle(Z3D_Jupiter::Particle* particle) {
	this->particle = particle;
}
GameObject::~GameObject() {
	delete(this->particle);
	delete(this->transform);
	delete(this->mesh);
	delete(this->shader);
}

} /* namespace Z3D_Base */
