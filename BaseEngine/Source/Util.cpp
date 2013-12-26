/*
 * Util.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <vector>
#include "../Util.h"

namespace Z3D_Base {

const float* Util::createFlippedBuffer(Vertex *vertices, int number) {

	float *temp = new float[number * Vertex::SIZE];

	register int j=0;

	for (register int i = 0; i < number; ++i) {
		temp[j++] = vertices[i].getPos().getX();
		temp[j++] = vertices[i].getPos().getY();
		temp[j++] = vertices[i].getPos().getZ();
	}

	return (const float*)temp;
}

const float* Z3D_Base::Util::createFlippedBuffer(Matrix4f matrix) {

	float *temp = new float[16];

	for (register int i = 0; i < 16; ++i)
		temp[i] = matrix.get(i/4,i%4);

	return (const float*)temp;

}

} /* namespace Z3D_Base */
