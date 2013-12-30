/*
 * GLUTLinearizer.h
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#ifndef __GLUTLinearizer
#define __GLUTLinearizer

#include <GL/freeglut.h>
#include "Input.h"

namespace Z3D_Base {
class GLUTLinearizer
{
public:
	static void keyPressed(unsigned char key, int x, int y) {
		Input::keyPressed(key,x,y);
	}
	static void keyUp(unsigned char key, int x, int y) {
		Input::keyUp(key,x,y);
	}

	static void specialKeyPressed(int key, int x, int y) {
		Input::specialKeyPressed(key, x, y);
	}

	static void specialKeyUp(int key, int x, int y) {
		Input::specialKeyUp(key, x, y);
	}

	static void fixMouse(int button, int state, int x, int y)
	{
		Input::fixMouse(button,state,x,y);
	}

	static void mouseMotion(int x, int y)
	{
		Input::mouseMotion(x,y);
	}
};


void keyPressed(unsigned char key, int x, int y) {
	GLUTLinearizer::keyPressed(key,x,y);
}
void keyUp(unsigned char key, int x, int y) {
	GLUTLinearizer::keyUp(key,x,y);
}

void specialKeyPressed(int key, int x, int y) {
	GLUTLinearizer::specialKeyPressed(key, x, y);
}

void specialKeyUp(int key, int x, int y) {
	GLUTLinearizer::specialKeyUp(key, x, y);
}

void fixMouse(int button, int state, int x, int y)
{
	GLUTLinearizer::fixMouse(button,state,x,y);
}

void mouseMotion(int x, int y)
{
	GLUTLinearizer::mouseMotion(x,y);
}

void runGlutInit()
{
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutSpecialUpFunc(specialKeyUp);
	glutSpecialFunc(specialKeyPressed);
	glutMouseFunc(fixMouse);
	glutPassiveMotionFunc(mouseMotion);
}

}
#endif
