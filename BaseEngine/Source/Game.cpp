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
#include <GL/freeglut.h>
#include <string>
#include <iostream>

namespace Z3D_Base {

Game::Game() {
	Vertex *data = new Vertex[3] {
		Vertex(Vector3f(-1.0f,-1.0f,0.0f)),
		Vertex(Vector3f(0.0f,1.0f,0.0f)),
		Vertex(Vector3f(1.0f,-1.0f,0.0f)),
	};

	this->mesh.addVertices(data,3);

	this->shader.addFragmentShader(ResourceLoader::loadShader("Assets/_Shaders/Basic/fragment.fxs").c_str());
	this->shader.addVertexShader(ResourceLoader::loadShader("Assets/_Shaders/Basic/vertex.vxs").c_str());
	this->shader.compileShader();
	this->shader.addUniform("transform");
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::input()
{

}

float amount;

void Game::update()
{
	static float temp;
	temp += Time::getDelta()*200.0f;


	amount = (float)Mathf::fastSin(temp);

	this->transform.setTranslation(amount,0.0f,0.0f);
	this->transform.setRotation(0.0f,0.0f,amount*180.0f);
	this->transform.setScale(amount,amount,0.0f);

	if(Input::geyKeyDown(GLUT_KEY_UP,true))
		std::cout << std::endl << powf((float)Mathf::fastSin(temp),2.0f) << std::endl;

	if(Input::geyKeyUp(GLUT_KEY_UP,true))
		std::cout << "Key is up from update...";

	if(Input::geyKey(GLUT_KEY_DOWN,true))
		std::cout << "Key is pressed from update...";

	if(Input::getMouseDown(GLUT_RIGHT_BUTTON))
	{
		Vector2f temp = Input::getMousePosition();
		std::cout << "Right mouse down... at x=" << temp.getX() << "& y=" << temp.getY() << " "<< std::endl;
	}
}

void Game::render()
{
	this->shader.bind();
	this->shader.setUniform("transform",this->transform.getTransform());
	this->mesh.draw();
}

} /* namespace Z3D_Base */


