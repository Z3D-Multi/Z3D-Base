/*
 * Input.cpp
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#include "../Input.h"

#define NUM_KEYS 256
#define NUM_BUTTONS 3

namespace Z3D_Base {

/*
 * Static Variables:
 * =================
 */
static bool keyStates[NUM_KEYS];
static bool specialKeyStates[NUM_KEYS];
static int snapshotOfKeyStates[NUM_KEYS];
static int 			snapshotOfSpecialKeyStates[NUM_KEYS];
static int 			snapshotOfMouseStates[NUM_BUTTONS][2];
static Vector2f		snapshotOfMousePosition;

Input::Input() {
}

Input::~Input() {
}

/*
 * Functions:
 * =================
 */

void Input::keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true;
}
void Input::keyUp(unsigned char key, int x, int y) {
	keyStates[key] = false;
}

void Input::specialKeyPressed(int key, int x, int y) {
	specialKeyStates[key] = true;
}

void Input::specialKeyUp(int key, int x, int y) {
	specialKeyStates[key] = false;
}

void Input::fixMouse(int button, int state, int x, int y)
{
	snapshotOfMouseStates[button][0]=state;
}

void Input::mouseMotion(int x, int y)
{
	snapshotOfMousePosition.setX(x);
	snapshotOfMousePosition.setY(y);
}

void Input::update() {

	//Take system snapshot of mouse://
	for(register int i=0;i<NUM_BUTTONS;i++)
	{
		switch (snapshotOfMouseStates[i][1]) {
		case -1:
			if (snapshotOfMouseStates[i][0] == false)
				snapshotOfMouseStates[i][1] = 0;
			else
				snapshotOfMouseStates[i][1] = 2;
			break;
		case 0:
			if (snapshotOfMouseStates[i][0] == true)
				snapshotOfMouseStates[i][1] = 2;
			break;
		case 1:
			if (snapshotOfMouseStates[i][0] == false)
				snapshotOfMouseStates[i][1] = -1;
			break;
		case 2:
			if (snapshotOfMouseStates[i][0] == false)
				snapshotOfMouseStates[i][1] = -1;
			else
				snapshotOfMouseStates[i][1] = 1;
			break;
		}
	}

	//Take a system snapshot of keyboard
	for (register int i = 0; i < NUM_KEYS; i++) {
		switch (snapshotOfKeyStates[i]) {
		case -1:
			if (keyStates[i] == false)
				snapshotOfKeyStates[i] = 0;
			else
				snapshotOfKeyStates[i] = 2;
			break;

		case 0:
			if (keyStates[i] == true)
				snapshotOfKeyStates[i] = 2;
			break;

		case 1:
			if (keyStates[i] == false)
				snapshotOfKeyStates[i] = -1;
			break;

		case 2:
			if (keyStates[i] == false)
				snapshotOfKeyStates[i] = -1;
			else
				snapshotOfKeyStates[i] = 1;
			break;
		}

		switch (snapshotOfSpecialKeyStates[i]) {
		case -1:
			if (specialKeyStates[i] == false)
				snapshotOfSpecialKeyStates[i] = 0;
			else
				snapshotOfSpecialKeyStates[i] = 2;
			break;

		case 0:
			if (specialKeyStates[i] == true)
				snapshotOfSpecialKeyStates[i] = 2;
			break;
		case 1:
			if (specialKeyStates[i] == false)
				snapshotOfSpecialKeyStates[i] = -1;
			break;
		case 2:
			if (specialKeyStates[i] == false)
				snapshotOfSpecialKeyStates[i] = -1;
			else
				snapshotOfSpecialKeyStates[i] = 1;
			break;
		}
	}
}


bool Input::geyKey(int keyCode, bool special) {
	if (special)
		return snapshotOfSpecialKeyStates[keyCode] == 1;

	return snapshotOfKeyStates[keyCode] == 1;
}

bool Input::geyKeyDown(int keyCode, bool special) {
	if (special)
		return snapshotOfSpecialKeyStates[keyCode] > 1;

	return snapshotOfKeyStates[keyCode] > 1;
}

bool Input::geyKeyUp(int keyCode, bool special) {
	if (special)
		return snapshotOfSpecialKeyStates[keyCode] < 0;

	return snapshotOfKeyStates[keyCode] < 0;
}

bool Input::getMouse (int mouseButton)
{
	if(mouseButton > NUM_BUTTONS)
		return false;

	return snapshotOfMouseStates[mouseButton][1]==1;
}

bool Input::getMouseUp(int mouseButton)
{
	if(mouseButton > NUM_BUTTONS)
		return false;

	return snapshotOfMouseStates[mouseButton][1]>1;
}

bool Input::getMouseDown(int mouseButton)
{
	if(mouseButton > NUM_BUTTONS)
		return false;

	return snapshotOfMouseStates[mouseButton][1]<0;
}

Vector2f Input::getMousePosition()
{
	return snapshotOfMousePosition;
}

} /* namespace Z3D_Base */
