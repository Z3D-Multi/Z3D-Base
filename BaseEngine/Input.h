/*
 * Input.h
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <GL/freeglut.h>

#include "Vector2f.h"

namespace Z3D_Base {

class GLUTLinearizer;

class Input {

private:
	static void keyPressed(unsigned char key, int x, int y);
	static void keyUp(unsigned char key, int x, int y) ;
	static void specialKeyPressed(int key, int x, int y) ;
	static void specialKeyUp(int key, int x, int y) ;
	static void fixMouse(int button, int state, int x, int y);
	static void mouseMotion(int x, int y);


public:
	Input();
	virtual ~Input();
	friend class GLUTLinearizer;

	static void update();
	static bool geyKey(int keyCode,bool special=false);
	static bool geyKeyDown(int keyCode,bool special=false);
	static bool geyKeyUp(int keyCode,bool special=false);
	static bool getMouse (int mouseButton);
	static bool getMouseDown(int mouseButton);
	static bool getMouseUp(int mouseButton);
	static Vector2f getMousePosition();

};

} /* namespace Z3D_Base */
#endif /* INPUT_H_ */
