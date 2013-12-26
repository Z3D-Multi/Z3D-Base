/*
 * Vertex.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "Vector3f.h"

namespace Z3D_Base {

class Vertex {
private:
	Vector3f pos;

public:
	static const int SIZE = 3;

	Vertex(Vector3f pos);
	virtual ~Vertex();

	const Vector3f& getPos() const;
	void setPos(const Vector3f& pos);
};

} /* namespace Z3D_Base */

#endif /* VERTEX_H_ */
