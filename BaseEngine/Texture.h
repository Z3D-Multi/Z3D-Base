/*
 * Texture.h
 *
 *  Created on: 31-Dec-2013
 *      Author: zeneil
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#define __TEXTURE_LEVELS 1

#include <GL/freeglut.h>

namespace Z3D_Base {

class Texture {
private:
	unsigned int id;

public:
	Texture();
	Texture(unsigned int id);
	virtual ~Texture();

	unsigned int *getID();
	void bind();
	unsigned static int levels();
};

} /* namespace Z3D_Base */

#endif /* TEXTURE_H_ */
