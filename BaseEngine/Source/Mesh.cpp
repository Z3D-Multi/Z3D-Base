/*
 * Mesh.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <GL/glew.h>
#include "../Mesh.h"
#include "../Util.h"

namespace Z3D_Base {

Mesh::Mesh() {
#ifdef glGenBuffers
	glGenBuffers(1,(GLuint *)&this->vbo);
	glGenBuffers(1,(GLuint *)&this->ibo);
#endif

	if(!this->vbo)
		throw 10;

	this->size = 0;
}

Mesh::~Mesh() {
#ifdef glGenBuffers
	const GLuint *buffers = new GLuint[1] {(GLuint)vbo};
	if(glIsBuffer(vbo))
		glDeleteBuffers(1,buffers);
	delete(buffers);
#endif
}

void Mesh::addVertices(Vertex *vertices, int number)
{
	this->size = number * Vertex::SIZE;

#ifdef glBindBuffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Check if buffer bind was successful://
	if(!glIsBuffer(vbo))
		throw 10;
	const float* x = Util::createFlippedBuffer(vertices,number);
	//Add Buffer Data://
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*this->size,(void *)x,GL_STATIC_DRAW);
#else
#error Undefined Buffers
#endif

}

void Mesh::draw()
{
#ifdef glBindBuffer
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::SIZE*sizeof(float), 0);

	//Check if buffer bind was successful://
	if(glIsBuffer(vbo) != GL_TRUE)
		throw 10;

	//Draw the data://
	glDrawArrays(GL_TRIANGLES,0,this->size);

	glDisableVertexAttribArray(0);
#else
#error Undefined Buffers
#endif
}

} /* namespace Z3D_Base */
