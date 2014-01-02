/*
 * Vertex.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include "../Vertex.h"

namespace Z3D_Base {

Vertex::Vertex(Vector3f pos) {
	this->pos=pos;
	this->textureCoord = Vector2f(0.0f,0.0f);
}

const Vector3f& Vertex::getPos() const {
	return pos;
}

const Vector2f& Vertex::getTextureCoord() const {
	return textureCoord;
}

Vertex::Vertex(Vector3f pos, Vector2f texCoord) {
	this->pos=pos;
	this->textureCoord = texCoord;
}

void Vertex::setTextureCoord(const Vector2f& textureCoord) {
	this->textureCoord = textureCoord;
}

void Vertex::setPos(const Vector3f& pos) {
	this->pos = pos;
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

} /* namespace Z3D_Base */
