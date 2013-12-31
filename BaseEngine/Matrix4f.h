/*
 * Matrix4f.h
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#ifndef MATRIX4F_H_
#define MATRIX4F_H_

#define MATRIX4F_INIT_WITH_TRANSLATION 	0x0
#define MATRIX4F_INIT_WITH_ROTATION		0x1
#define MATRIX4F_INIT_WITH_SCALE		0x2

#include "Vector3f.h"

namespace Z3D_Base {

class Matrix4f {
private:
	float m[4][4];

	void init(bool identity);

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Matrix4f(bool identity=false);
	//Constructor for scaling rotation and translation://
	Matrix4f(float x, float y, float z, int type);
	//Constructor for vector3f scaling rotation and translation://
	Matrix4f(Vector3f &axis, int type);
	//Constructor for vector3f camera Position://
	Matrix4f(const Vector3f &forward,const Vector3f &up);
	//Copy Constructor://
	Matrix4f(const Matrix4f& rhs);
	virtual ~Matrix4f();

	/*
	 * 	Mathematical Functions:
	 * =======================
	 */
	void loadIdentity();

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	float get(int x, int y) const;
	void set(int x, int y, float val);
	float* getValueList() const;

	/*
	 * 	Operator Overloads:
	 * ==================
	 */
	bool operator==(const Matrix4f& rhs) const;
	Matrix4f operator*(const Matrix4f& rhs);
	Matrix4f operator=(const Matrix4f& rhs);
	Vector3f operator*(const Vector3f& rhs);

};

} /* namespace Z3D_Base */

#endif /* MATRIX4F_H_ */
