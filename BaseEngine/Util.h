/*
 * Util.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "Vertex.h"
#include "Matrix4f.h"

namespace Z3D_Base {

class Util {
public:
	static const float* createFlippedBuffer(Vertex *vertices, int number);
	static const float* createFlippedBuffer(Matrix4f matrix);
};

} /* namespace Z3D_Base */

#endif /* UTIL_H_ */
