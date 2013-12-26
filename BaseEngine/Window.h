/*
 * Window.h
 *
 *  Created on: 21-Dec-2013
 *      Author: zeneil
 */

#ifndef WINDOW_H_
#define WINDOW_H_

namespace Z3D_Base {

class Window {
public:
	Window();
	virtual ~Window();

	static void createWindow(int width, int height,const char* title);
	static void render();
	static bool isCloseRequested();

private:
	static bool isWindowCloseRequested;
	static const char* title;

	//Functions://
	static void reshape(int w, int h);
	static int getWidth();
	static int getHeight();
	static const char* getTitle();

	static void closeWindowCallback();
};

}

#endif /* WINDOW_H_ */
