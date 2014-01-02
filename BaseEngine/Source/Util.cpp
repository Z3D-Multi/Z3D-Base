/*
 * Util.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <vector>
#include <string.h>
#include "../Util.h"

namespace Z3D_Base {

const float* Util::createFlippedBuffer(Vertex *vertices, int number) {

	float *temp = new float[number * Vertex::SIZE];

	register int j=0;

	for (register int i = 0; i < number; ++i) {
		temp[j++] = vertices[i].getPos().getX();
		temp[j++] = vertices[i].getPos().getY();
		temp[j++] = vertices[i].getPos().getZ();
		temp[j++] = vertices[i].getTextureCoord().getX();
		temp[j++] = vertices[i].getTextureCoord().getY();
	}

	return (const float*)temp;
}

const float* Z3D_Base::Util::createFlippedBuffer(Matrix4f matrix) {

	float *temp = new float[16];

	for (register int i = 0; i < 16; ++i)
		temp[i] = matrix.get(i/4,i%4);

	return (const float*)temp;

}

const unsigned int* Z3D_Base::Util::createFlippedBuffer(unsigned int* indices, int number) {
	unsigned int *temp = new unsigned int[number];

	for (register int i = 0; i < number; ++i)
		temp[i]=indices[i];

	return temp;
}

} /* namespace Z3D_Base */

