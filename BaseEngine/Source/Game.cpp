/*
 * Game.cpp
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#include "../Game.h"
#include "../Input.h"
#include "../Vector2f.h"
#include "../ResourceLoader.h"
#include "../Time.h"
#include "../Mathf.h"
#include "../Debug.h"
#include <GL/freeglut.h>
#include <string>
#include <iostream>

namespace Z3D_Base {

Game::Game() {

	Vertex *vData = new Vertex[4] { Vertex(Vector3f(-1.0f, -1.0f, 0.0f),
			Vector2f(0.0f, 0.0f)), Vertex(Vector3f(0.0f, 1.0f, 0.0f),
			Vector2f(0.5f, 0.0f)), Vertex(Vector3f(1.0f, -1.0f, 0.0f),
			Vector2f(1.0f, 0.0f)), Vertex(Vector3f(0.0f, -1.0f, 1.0f),
			Vector2f(0.0f, 0.5f)),

	};

	unsigned int *ibo = new unsigned int[12] { 0, 1, 3, 3, 1, 2, 2, 1, 0, 0, 3,
			2 };

	this->player.setMesh(ResourceLoader::loadMesh("Assets/_Models/OBJ/Box.obj"));
	//this->mesh.addVertices(vData, 4, ibo, 12);

	Camera temp(Vector3f(0.0f, 0.0f, -20.0f), Vector3f(0.0f, 0.0f, 1.0f),
			Vector3f(0.0f, 1.0f, 0.f));

	this->player.getTransform()->setCamera(temp);
	//Transform transform;

	Shader *shader = this->player.getShader();
	shader->addFragmentShader(
			ResourceLoader::loadShader("Assets/_Shaders/Basic/fragment.fxs").c_str());
	shader->addVertexShader(
			ResourceLoader::loadShader("Assets/_Shaders/Basic/vertex.vxs").c_str());
	shader->compileShader();
	shader->addUniform("transform");

	this->gravity = new Z3D_Jupiter::ParticleGravity();
	this->drag = new Z3D_Jupiter::ParticleDrag(9.2, 0.1);
	Z3D_Jupiter::Particle *particle = (Z3D_Jupiter::Particle *)this->player.getParticle();
	particle->setMass(10.0f);

	this->registry = new Z3D_Jupiter::ParticleForceRegistry();
	this->registry->add((Z3D_Jupiter::Particle *)this->player.getParticle(),
			(Z3D_Jupiter::ParticleForceGenerator *) this->gravity);
	this->registry->add((Z3D_Jupiter::Particle *)this->player.getParticle(),
			(Z3D_Jupiter::ParticleForceGenerator *) this->drag);

	Debug::log("Initialization completed...");

}

Game::~Game() {
	delete (this->registry);
	delete (this->drag);
	delete (this->gravity);
}

void Game::input() {

}

float amount;

void Game::update() {

	//Update physics engine://
	this->registry->updateAllForcesAndParticles(Time::getDelta());

	this->transform.setTranslation(this->player.getParticle()->getPosition());
	//this->transform.setRotation(Vector3f(0.0f, 0.0f, 1.0f) * amount * 180.0f);
	this->transform.getCamera().input();

	if (Input::getMouseDown(GLUT_RIGHT_BUTTON)) {
		/*Vector2f temp = Input::getMousePosition();
		 std::cout << "Right mouse down... at x=" << temp.getX() << "& y="
		 << temp.getY() << " " << std::endl;*/

		Debug::log("Exected");

		/*if (Input::geyKey('x', false))
			this->particle->setVelocity(Vector3f(0.0f, -2.0f, 0.0f));
		else if (Input::geyKey('q', false))
			this->particle->setVelocity(Vector3f(-2.0f, 0.0f, 0.0f));
		else if (Input::geyKey('e', false))
			this->particle->setVelocity(Vector3f(2.0f, 0.0f, 0.0f));
		else
			this->particle->setVelocity(Vector3f(0.0f, 0.0f, 0.0f));*/

	}
}

void Game::render() {
//	this->shader.bind();
//	this->shader.setUniform("transform", this->transform.getTransform());
//	this->mesh.draw();
//	this->shader.setUniform("transform", Matrix4f(true));
//	this->mesh.draw();
	this->player.draw();
}

} /* namespace Z3D_Base */

