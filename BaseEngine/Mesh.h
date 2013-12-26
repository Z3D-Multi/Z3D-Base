/*
 * Mesh.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef MESH_H_
#define MESH_H_

#include "Vertex.h"
#include <GL/gl.h>

namespace Z3D_Base {

class Mesh {
private:
	int vbo;
	GLuint ibo;
	unsigned int size;
public:
	Mesh();
	virtual ~Mesh();

	void addVertices(Vertex *vertices, int number, unsigned int* indices,
			int indexNumber);
	void draw();
};

} /* namespace Z3D_Base */

#endif /* MESH_H_ */
