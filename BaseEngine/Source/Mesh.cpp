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

float *floatArray;

Mesh::Mesh() {
#ifdef glGenBuffers
	glGenBuffers(1,(GLuint *)&this->vbo);
	glGenBuffers(1,&this->ibo);
#endif

	if (!this->vbo)
		throw 10;

	this->size = 0;
}

Mesh::~Mesh() {
#ifdef glGenBuffers
	const GLuint *buffers = new GLuint[2] {(GLuint)vbo,ibo};
	if(glIsBuffer(vbo))
	glDeleteBuffers(1,buffers);

	delete(buffers);
#endif
}

void Mesh::addVertices(Vertex *vertices, int number, unsigned int *indices,
		int indexNumber) {
	this->size = indexNumber;

#ifdef glBindBuffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Check if buffer bind was successful://
	if(!glIsBuffer(vbo))
	throw 10;
	floatArray = (float *)Util::createFlippedBuffer(vertices,number);
	//Add Buffer Data://
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*number * Vertex::SIZE,(void *)floatArray,GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*indexNumber, (GLubyte *)Util::createFlippedBuffer(indices,indexNumber), GL_STATIC_DRAW);
#else
#error Undefined Buffers
#endif
}

void Mesh::draw() {
#ifdef glBindBuffer
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::SIZE*sizeof(float), 0);
	const int sizeForTexture = (3*sizeof(float));
	glVertexAttribPointer(1, 2,	GL_FLOAT, false, Vertex::SIZE*sizeof(float), &sizeForTexture);

	//Check if buffer bind was successful://
	if(glIsBuffer(vbo) != GL_TRUE)
	throw 10;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	//Draw the data://
	glDrawElements(GL_TRIANGLES,this->size,GL_UNSIGNED_INT,0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
#else
#error Undefined Buffers
#endif
}

} /* namespace Z3D_Base */
