/*
 * Texture.cpp
 *
 *  Created on: 31-Dec-2013
 *      Author: zeneil
 */

#include "../Texture.h"

namespace Z3D_Base {

Texture::Texture() {
}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

Texture::Texture(unsigned int id) {
	this->id=id;
}

unsigned int *Texture::getID() {
	return &this->id;
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D,id);
}

unsigned int Texture::levels() {
	return __TEXTURE_LEVELS;
}

} /* namespace Z3D_Base */
