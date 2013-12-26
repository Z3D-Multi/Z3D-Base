/*
 * Window.cpp
 *
 *  Created on: 21-Dec-2013
 *      Author: zeneil
 */

#include "../Window.h"
#include <GL/freeglut.h>
#include <iostream>
using namespace Z3D_Base;

/*
 * Static Variables:
 * =================
 */
const char* Window::title;
bool Window::isWindowCloseRequested;

/*
 *
 * Member Functions:
 * ================
 *
 */

Window::Window() {
	// TODO Auto-generated constructor stub

}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

void Window::createWindow(int width,int height, const char* title)
{
	//Generate glut settings
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(width,height);
	glutCreateWindow(title);
	glutReshapeFunc(Window::reshape);
	glutCloseFunc(Window::closeWindowCallback);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	//Generate personal settings
	Window::title = title;
	Window::isWindowCloseRequested = false;
}

void Window::render()
{
	glutSwapBuffers();
}

void Window::reshape(int w, int h)
{
	if(h == 0)
			h = 1;

	float ratio = 1.0* w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void Window::closeWindowCallback()
{
	Window::isWindowCloseRequested = true;
}


bool Window::isCloseRequested()
{
	return Window::isWindowCloseRequested;
}
int Window::getWidth()
{
	return glutGet(GLUT_WINDOW_WIDTH);
}
int Window::getHeight()
{
	return glutGet(GLUT_WINDOW_HEIGHT);
}

const char* Window::getTitle()
{
	return Window::title;
}
