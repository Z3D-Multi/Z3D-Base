/*
 * RenderUtil.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include "../RenderUtil.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

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
	gluLookAt(	0.0f, 0.0f, 10.0f,
				0.0f, 0.0f,  0.0f,
				0.0f, 1.0f,  0.0f);
}

void RenderUtil::initGraphics()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	//TODO: Depth clamp
	glEnable(GL_FRAMEBUFFER_SRGB);

}

char* RenderUtil::getOpenGLVersion()
{
	return (char *)glGetString(GL_VERSION);
}

} /* namespace Z3D_Base */
