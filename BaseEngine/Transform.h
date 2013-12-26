/*
 * Transform.h
 *
 *  Created on: 26-Dec-2013
 *      Author: zeneil
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector3f.h"
#include "Matrix4f.h"

namespace Z3D_Base {

class Transform {
private:
	Vector3f rotation;
	Vector3f translation;
	Vector3f scale;

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Transform();
	virtual ~Transform();

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	const Vector3f& getTranslation() const;
	void setTranslation(const Vector3f& transform);
	void setTranslation(float x, float y, float z);
	const Vector3f& getRotation() const;
	void setRotation(const Vector3f& rotation);
	void setRotation(float x, float y, float z);
	const Vector3f& getScale() const;
	void setScale(const Vector3f& scale);
	void setScale(float x, float y, float z);

	Matrix4f getTransform();
};

} /* namespace Z3D_Base */

#endif /* TRANSLATION_H_ */
