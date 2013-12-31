/*
 * RenderUtil.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include "../RenderUtil.h"
#include "../Transform.h"
#include "../Debug.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
namespace Z3D_Base {

RenderUtil::RenderUtil() {
	// TODO Auto-generated constructor stub

}

RenderUtil::~RenderUtil() {
	// TODO Auto-generated destructor stub
}

void RenderUtil::clearScreen()
{
	//TODO: Clear Stencil
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// Set the camera
	Camera camera = Transform::getCamera();
	Vector3f eyePosition = camera.getPos();
	Vector3f eyeCenter = eyePosition + camera.getForward();
	Vector3f eyeUp = camera.getUp();
	gluLookAt(	eyePosition.getX(), eyePosition.getY(), eyePosition.getZ(),
				eyeCenter.getX(), eyeCenter.getY(), eyeCenter.getZ(),
				eyeUp.getX(), eyeUp.getY(),  eyeUp.getZ());
}

void RenderUtil::initGraphics()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glEnable(GL_DEPTH_TEST);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//TODO: Depth clamp
	glEnable(GL_FRAMEBUFFER_SRGB);

}

char* RenderUtil::getOpenGLVersion()
{
	return (char *)glGetString(GL_VERSION);
}

} /* namespace Z3D_Base */
