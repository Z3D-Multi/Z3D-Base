/*
 * GameObject.h
 *
 *  Created on: 02-Jan-2014
 *      Author: zeneil
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Transform.h"
#include "Shader.h"
#include "Mesh.h"
#include "../JupiterEngine/stdi.h"

namespace Z3D_Base {

class GameObject {

private:
	Shader *shader;
	Transform *transform;
	Mesh *mesh;
	Z3D_Jupiter::Particle *particle;

public:
	GameObject();
	virtual ~GameObject();


	/*
	 * Draw Object With shaders:
	 * ------------------------
	 */
	void draw();

	/*
	 * Getters & Setters:
	 * ==================
	 */
	bool hasMeshAttached();
	Mesh *getMesh();
	void setMesh(Mesh* mesh);
	Shader *getShader();
	void setShader(Shader *shader);
	Transform* getTransform();
	void setTransform(Transform *transform);
	Z3D_Jupiter::Particle* getParticle();
	void setParticle(Z3D_Jupiter::Particle* particle);




};

} /* namespace Z3D_Base */

#endif /* GAMEOBJECT_H_ */
