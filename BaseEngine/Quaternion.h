/*
 * Quaternion.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "Vector3f.h"

namespace Z3D_Base {

class Quaternion {
private:
	enum index {
		_x, _y, _z, _w
	};
	float q[4];

public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	virtual ~Quaternion();

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	float getZ() const;
	void setZ(float z);
	float getW() const;
	void setW(float w);

	/*
	 * 	Mathematical Functions:
	 * =======================
	 */
	float length();
	Quaternion normalize();
	Quaternion conjugate();

	/*
	 * 	Operator Overloads:
	 * ==================
	 */
	Quaternion operator*(const Quaternion& rhs);
	Quaternion operator*(const Vector3f& rhs);

};

} /* namespace Z3D_Base */

#endif /* QUATERNION_H_ */
