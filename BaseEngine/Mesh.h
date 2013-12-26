/*
 * Mesh.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef MESH_H_
#define MESH_H_

#include "Vertex.h"

namespace Z3D_Base {

class Mesh {
private:
	int vbo;
	int ibo;
	unsigned int size;

public:
	Mesh();
	virtual ~Mesh();

	void addVertices(Vertex *vertices, int number);
	void draw();
};

} /* namespace Z3D_Base */

#endif /* MESH_H_ */
