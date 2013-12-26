/*
 * MainComponent.cpp
 *
 *  Created on: 21-Dec-2013
 *      Author: zeneil
 */

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <boost/chrono.hpp>
#include "../MainComponent.h"
#include "../Window.h"
#include "../Time.h"
#include "../Input.h"
#include "../RenderUtil.h"
#include "../Mesh.h"
using namespace Z3D_Base;

/*
 * Static Variables:
 * =================
 */
static MainComponent *current;
static long lastTime;
static double unprocessedTime;
/*
 *
 * Member Functions:
 * ================
 *
 */
MainComponent::MainComponent(int* argc, char** argv) {
	// TODO Auto-generated constructor stub

	//Generate glut settings
	glutInit(argc, argv);
	glutDisplayFunc(runPointer);
	glutIdleFunc(runPointer);

	//Class init
	current = this;
	this->isRunning = false;
	this->frameCap = 0.0f;
}

MainComponent::~MainComponent() {
	// TODO Auto-generated destructor stub
}

void MainComponent::onWindowInit() {

	//Primary Init
	glewInit();

	//Other Classes://
	this->game = new Game();
	RenderUtil::initGraphics();
}

void MainComponent::runPointer() {
	//Other Class startup:
	current->run();
}

void MainComponent::start() {

	if (this->isRunning)
		return;

	this->isRunning = true;

	lastTime = Time::getTime();
	unprocessedTime = 0.0;

	glutMainLoop();

	//Check if the loop is still running and resources are allocated://
	if(this->isRunning)
	{
		this->isRunning=false;
		this->cleanup();
	}

}
void MainComponent::stop() {
	this->isRunning = false;
}

void MainComponent::run() {

	const double frameTime = 1.0 / this->frameCap;

	if (this->isRunning) {

		static int frames = 0;
		static long frameCounter = 0;

		bool render = false;

		long startTime = Time::getTime();
		long passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime / (double) Time::SECOND;
		frameCounter += passedTime;

		while (unprocessedTime > frameTime) {
			render = true;

			unprocessedTime -= frameTime;

			if (Window::isCloseRequested())
				this->stop();

			Time::setDelta(frameTime);
			Input::update();

			//Update the game://
			game->input();
			game->update();

			if (frameCounter >= Time::SECOND) {
				std::cout << "Frame Rate: ";
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}

		}
		if (render) {
			this->render();
			frames++;
		}
	}
}

void MainComponent::render() {

	RenderUtil::clearScreen();
	game->render();
	Window::render();
}

bool MainComponent::isIsRunning() const {
	return isRunning;
}

void MainComponent::setIsRunning(bool isRunning) {
	this->isRunning = isRunning;
}

double MainComponent::getFrameCap() const {
	return frameCap;
}

void MainComponent::setFrameCap(double frameCap) {
	this->frameCap = frameCap;
}

void MainComponent::cleanup() {
	//Class cleanup
	delete (this->game);
}
