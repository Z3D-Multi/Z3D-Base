//============================================================================
// Name        : 3DZ.cpp
// Author      : Zeneil Ambekar
// Version     :
// Copyright   : Free For All
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include <GL/freeglut.h>
//#include <GL/gl.h>
#define __BASE_ENGINE_MAINCOMPONENT "../BaseEngine/MainComponent.h"
#define __BASE_ENGINE_WINDOW "../BaseEngine/Window.h"
#define __BASE_ENGINE_LINEARIZER "../BaseEngine/GLUTLinearizer.h"

#include __BASE_ENGINE_MAINCOMPONENT
#include __BASE_ENGINE_WINDOW
#include __BASE_ENGINE_LINEARIZER
using namespace Z3D_Base;


const int HEIGHT = 800;
const int WIDTH = 600;
const int FRAME_CAP = 5.0e2f;
const char* title = "Z3D";


int main(int argc, char **argv) {

	MainComponent game(&argc,argv);
	game.setFrameCap(FRAME_CAP);
	Window::createWindow(WIDTH,HEIGHT,title);

	game.onWindowInit();
	runGlutInit();

	game.start();

	return 0;
}
