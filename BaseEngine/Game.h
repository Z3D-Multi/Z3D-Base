/*
 * Game.h
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#ifndef GAME_H_
#define GAME_H_

#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Texture.h"

namespace Z3D_Base {

class Game {
private:
	Mesh mesh;
	Shader shader;
	Transform transform;
	Texture texture;

public:
	Game();
	virtual ~Game();

	void input();
	void update();
	void render();
};

} /* namespace Z3D_Base */
#endif /* GAME_H_ */
