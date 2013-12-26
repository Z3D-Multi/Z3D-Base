/*
 * MainComponent.h
 *
 *  Created on: 21-Dec-2013
 *      Author: zeneil
 */

#ifndef MAINCOMPONENT_H_
#define MAINCOMPONENT_H_

#include "Game.h"

namespace Z3D_Base {

class MainComponent {
public:

	/*
	 * Functions:
	 * =========
	 */
	MainComponent(int* argc, char** argv);
	virtual ~MainComponent();

	void onWindowInit();

	void start();
	void stop();
	bool isIsRunning() const;
	void setIsRunning(bool isRunning);
	double getFrameCap() const;
	void setFrameCap(double frameCap);

private:
	Game *game;

	bool isRunning;
	double frameCap;

	static void runPointer();
	void run();
	void render();
	void cleanup();

};

}
#endif /* MAINCOMPONENT_H_ */
