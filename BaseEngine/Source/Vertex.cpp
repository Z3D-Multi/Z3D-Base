/*
 * Vertex.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include "../Vertex.h"

namespace Z3D_Base {

Vertex::Vertex(Vector3f pos) {
	// TODO Auto-generated constructor stub
	this->pos=pos;
}

const Vector3f& Vertex::getPos() const {
	return pos;
}

void Vertex::setPos(const Vector3f& pos) {
	this->pos = pos;
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

} /* namespace Z3D_Base */
