/*
 * Vertex.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "Vector3f.h"
#include "Vector2f.h"

namespace Z3D_Base {

class Vertex {
private:
	Vector3f pos;
	Vector2f textureCoord;

public:
	static const int SIZE = 5;

	Vertex(Vector3f pos);
	Vertex(Vector3f pos, Vector2f texCoord);
	virtual ~Vertex();

	const Vector3f& getPos() const;
	void setPos(const Vector3f& pos);
	const Vector2f& getTextureCoord() const;
	void setTextureCoord(const Vector2f& textureCoord);
};

} /* namespace Z3D_Base */

#endif /* VERTEX_H_ */
